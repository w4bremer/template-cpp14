#pragma warning (disable: 4251) 
#pragma warning (disable: 4099) 

#include <catch2/catch.hpp>
#include <catch2/trompeloeil.hpp>

#include "../olinkconnection.h"

#include "olink/clientregistry.h"
#include "olink/core/types.h"
#include "olink/core/protocol.h"

#include "private/frame.hpp"
#include "private/sinkobjectmock.hpp"
#include "private/test_server/test_server.hpp"

#include "nlohmann/json.hpp"

namespace tests{

namespace {
    // Message converter to translate messages for network format. Same should be used in tested classes.
    ApiGear::ObjectLink::MessageConverter converter(ApiGear::ObjectLink::MessageFormat::JSON);
    const std::string any_payload = "any";
    // Removes ping messages from a vector of messages.
    std::vector<Frame> removePingMessages(const std::vector<Frame>& in)
    {
        auto out = in;
        if (out.size() > 0)
        {
            out.erase(std::remove_if(out.begin(), out.end(),
                [](const auto& element) { return element.flags == Poco::Net::WebSocket::FRAME_OP_PING;}),
                out.end());
        }
        return out;
    }
    std::vector<Frame> removeAllNonTextMessages(const std::vector<Frame>& in)
    {
        auto out = in;
        if (out.size() > 0)
        {
            out.erase(std::remove_if(out.begin(), out.end(),
                [](const auto& element) { return element.flags != Poco::Net::WebSocket::FRAME_TEXT; }),
                out.end());
        }
        return out;
    }
}

TEST_CASE("OlinkConnection tests")
{
    auto portNumber = 8000;
    auto localHostAddress = "ws://127.0.0.1:" + std::to_string(portNumber);

    TestServer server(portNumber);
    ApiGear::ObjectLink::ClientRegistry registry;
    auto testOlinkConnection = ApiGear::PocoImpl::OlinkConnection::create(registry);

    SinkObjectMock sink1;
    std::string sink1Id = "tests.sink1";
    ALLOW_CALL(sink1, olinkObjectName()).RETURN(sink1Id);

    SECTION("Connect to host when sink is added and server is running. On teardown first disconnect sink then the client")
    {
        server.start();

        testOlinkConnection->connectToHost(Poco::URI(localHostAddress));
        testOlinkConnection->connectAndLinkObject(sink1);
        REQUIRE(registry.getSink(sink1Id) == &sink1);
        REQUIRE(registry.getNode(sink1Id) == &(testOlinkConnection->node()));

        // Check that server received link message
        auto expectedLinkMessage = converter.toString(ApiGear::ObjectLink::Protocol::linkMessage(sink1Id));

        auto msgs = removePingMessages(server.getReceivedFrames());
        REQUIRE(msgs[0].payload == expectedLinkMessage );
        REQUIRE(msgs[0].flags == Poco::Net::WebSocket::FRAME_TEXT);
        
        // Send init message from server and check it is delivered and decoded
        nlohmann::json initProperties = { {"property1", "some_string" }, { "property2",  9 }, { "property3", false } };
        REQUIRE_CALL(sink1, olinkOnInit(sink1Id, initProperties, &(testOlinkConnection->node())));
        
        auto preparedInitMessage = converter.toString(ApiGear::ObjectLink::Protocol::initMessage(sink1Id, initProperties));
        server.sendFrame(preparedInitMessage);
        // Wait for init message to be delivered and handled before the sink will be released
        Poco::Thread::sleep(30);

        // Remove sink: unlink, detach from node, remove from registry.
        REQUIRE_CALL(sink1, olinkOnRelease());
        testOlinkConnection->disconnectAndUnlink(sink1Id);
        REQUIRE(registry.getSink(sink1Id) == nullptr);
        REQUIRE(registry.getNode(sink1Id) == nullptr);

        //Check the unlink message
        auto expectedUnlinkMessage = converter.toString(ApiGear::ObjectLink::Protocol::unlinkMessage(sink1Id));
        msgs = removePingMessages(server.getReceivedFrames());
        REQUIRE(msgs[0].payload == expectedUnlinkMessage);
        REQUIRE(msgs[0].flags == Poco::Net::WebSocket::FRAME_TEXT);
        
        testOlinkConnection->disconnect();
        msgs = removePingMessages(server.getReceivedFrames());
        REQUIRE(msgs.size() > 0);
        // Check close frame was sent
        REQUIRE(msgs[0].flags == Poco::Net::WebSocket::FRAME_OP_CLOSE);
        server.stop();
    }

    SECTION("Add sink after connecting to host. On teardown disconnect the client from server first. ")
    {
        server.start();
        // Connect sink
        testOlinkConnection->connectAndLinkObject(sink1);
        REQUIRE(registry.getSink(sink1Id) == &sink1);
        REQUIRE(registry.getNode(sink1Id) == &(testOlinkConnection->node()));

        // Connect to server
        testOlinkConnection->connectToHost(Poco::URI(localHostAddress));
        auto msgs = removePingMessages(server.getReceivedFrames());
        // expect the link message to be received on server side 
        auto expectedLinkMessage = converter.toString(ApiGear::ObjectLink::Protocol::linkMessage(sink1Id));
        REQUIRE(msgs[0].payload == expectedLinkMessage);
        REQUIRE(msgs[0].flags == Poco::Net::WebSocket::FRAME_TEXT);

        // Send from server init message
        nlohmann::json initProperties = { {"property1", "some_string" }, { "property2",  9 }, { "property3", false } };
        REQUIRE_CALL(sink1, olinkOnInit(sink1Id, initProperties, &(testOlinkConnection->node())));
        auto preparedInitMessage = converter.toString(ApiGear::ObjectLink::Protocol::initMessage(sink1Id, initProperties));
        server.sendFrame(preparedInitMessage);
        
        // Teardown
        REQUIRE_CALL(sink1, olinkOnRelease());
        testOlinkConnection->disconnect();
        // No changes in registry in case user wants to restore connection.
        REQUIRE(registry.getSink(sink1Id) == &sink1);
        REQUIRE(registry.getNode(sink1Id) == &(testOlinkConnection->node()));
        // Check unlink was sent
        msgs = removePingMessages(server.getReceivedFrames());
        auto expectedUnlinkMessage = converter.toString(ApiGear::ObjectLink::Protocol::unlinkMessage(sink1Id));
        REQUIRE(msgs.size() == 2);
        REQUIRE(msgs[0].payload == expectedUnlinkMessage);
        REQUIRE(msgs[0].flags == Poco::Net::WebSocket::FRAME_TEXT);
        // Check close frame was sent
        REQUIRE(msgs[1].flags == Poco::Net::WebSocket::FRAME_OP_CLOSE);

        REQUIRE_CALL(sink1, olinkOnRelease());
        testOlinkConnection->disconnectAndUnlink(sink1Id);
        REQUIRE(registry.getSink(sink1Id) == nullptr);
        REQUIRE(registry.getNode(sink1Id) == nullptr);
        server.stop();
    }

    SECTION("Cleanup resources olink connection destruction.")
    {
        server.start();
        // Connect sink
        testOlinkConnection->connectAndLinkObject(sink1);
        REQUIRE(registry.getSink(sink1Id) == &sink1);
        REQUIRE(registry.getNode(sink1Id) == &(testOlinkConnection->node()));

        // Connect to server
        testOlinkConnection->connectToHost(Poco::URI(localHostAddress));
        auto msgs = removePingMessages(server.getReceivedFrames());
        // expect the link message to be received on server side 
        auto expectedLinkMessage = converter.toString(ApiGear::ObjectLink::Protocol::linkMessage(sink1Id));
        REQUIRE(msgs[0].payload == expectedLinkMessage);
        REQUIRE(msgs[0].flags == Poco::Net::WebSocket::FRAME_TEXT);

        REQUIRE_CALL(sink1, olinkOnRelease());
        testOlinkConnection.reset();
        REQUIRE(registry.getSink(sink1Id) == nullptr);
        REQUIRE(registry.getNode(sink1Id) == nullptr);

        // Check unlink was sent
        msgs = removePingMessages(server.getReceivedFrames());
        auto expectedUnlinkMessage = converter.toString(ApiGear::ObjectLink::Protocol::unlinkMessage(sink1Id));
        REQUIRE(msgs.size() == 2);
        REQUIRE(msgs[0].payload == expectedUnlinkMessage);
        REQUIRE(msgs[0].flags == Poco::Net::WebSocket::FRAME_TEXT);
        // Check close frame was sent
        REQUIRE(msgs[1].flags == Poco::Net::WebSocket::FRAME_OP_CLOSE);

        server.stop();
    }

    SECTION("Server sends close frame and then is up again")
    {
        server.start();

        testOlinkConnection->connectToHost(Poco::URI(localHostAddress));
        testOlinkConnection->connectAndLinkObject(sink1);
        REQUIRE(registry.getSink(sink1Id) == &sink1);
        REQUIRE(registry.getNode(sink1Id) == &(testOlinkConnection->node()));

        // Check that server received link message
        auto expectedLinkMessage = converter.toString(ApiGear::ObjectLink::Protocol::linkMessage(sink1Id));

        auto msgs = removePingMessages(server.getReceivedFrames());
        REQUIRE(msgs[0].payload == expectedLinkMessage);
        REQUIRE(msgs[0].flags == Poco::Net::WebSocket::FRAME_TEXT);

        // Send init message from server and check it is delivered and decoded
        nlohmann::json initProperties = { {"property1", "some_string" }, { "property2",  9 }, { "property3", false } };
        REQUIRE_CALL(sink1, olinkOnInit(sink1Id, initProperties, &(testOlinkConnection->node())));

        auto preparedInitMessage = converter.toString(ApiGear::ObjectLink::Protocol::initMessage(sink1Id, initProperties));
        server.sendFrame(preparedInitMessage);
        // Wait for init message to be delivered and handled before the sink will be released
        Poco::Thread::sleep(30);


        //send close frame from server side
        server.sendFrame(any_payload, Poco::Net::WebSocket::FRAME_OP_CLOSE);
        // Wait for init message to be delivered and handled before the sink will be released
        Poco::Thread::sleep(30);
        // wait for re-connection
        Poco::Thread::sleep(1001);
        // Cleanup
        REQUIRE_CALL(sink1, olinkOnRelease());
        testOlinkConnection->disconnectAndUnlink(sink1Id);
        auto expectedUnlinkMessage = converter.toString(ApiGear::ObjectLink::Protocol::unlinkMessage(sink1Id));

        msgs = removeAllNonTextMessages(server.getReceivedFrames());
        // Expect socket re-connects, and sends link message on re-connection
        REQUIRE(msgs[0].payload == expectedLinkMessage);
        //Check the unlink message
        REQUIRE(msgs[1].payload == expectedUnlinkMessage);

         testOlinkConnection->disconnect();
         msgs = removePingMessages(server.getReceivedFrames());
         REQUIRE(msgs.size() > 0);
         // Check close frame was sent
         REQUIRE(msgs[0].flags == Poco::Net::WebSocket::FRAME_OP_CLOSE);
         server.stop();
    }
}

}