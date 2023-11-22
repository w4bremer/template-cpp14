#include <iostream>
#include "io_world/generated/olink/helloclient.h"
#include "apigear/olink/olinkconnection.h"
#include "apigear/tracer/tracer.h"
#include "apigear/olink/olinklogadapter.h"
#include "olink/clientregistry.h"
#include "olink/clientnode.h"
#include "apigear/olink/olinkconnection.h"
#include <iostream>


using namespace HelloWorldExample;

int main() {
    // Create a global registry.
    ApiGear::ObjectLink::ClientRegistry registry;
    // Create a client and make a connection
    ApiGear::PocoImpl::OlinkConnection client(registry);
    // Create your client and request linking, which will try to connect with a server side for this object.
    auto ioWorldHello = std::make_shared<IoWorld::olink::HelloClient>();

    client.connectAndLinkObject(ioWorldHello);
    client.connectToHost(Poco::URI("ws://localhost:8182"));

    // Or subscribe for signals.
    ioWorldHello->_getPublisher().subscribeToJustSaid([](auto& /*args*/) { std::cout << "Just said received" << std::endl; });
    ioWorldHello->_getPublisher().subscribeToLastChanged([](auto& /*args*/) { std::cout << "Last Changed" << std::endl; });


    bool keepRunning = true;
    std::string cmd;
    do {
        std::cout << "Enter command:" << std::endl;
        getline(std::cin, cmd);

        if (cmd == "quit") {
            keepRunning = false;
            client.disconnect();
        }
    } while (keepRunning);
    client.disconnectAndUnlink(ioWorldHello->olinkObjectName());

    return 0;
}
