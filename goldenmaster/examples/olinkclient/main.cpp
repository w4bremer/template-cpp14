#include <iostream>
#include "testbed2/generated/olink/remotemanyparaminterface.h"
#include "testbed2/generated/monitor/manyparaminterface.tracedecorator.h"
#include "testbed2/generated/olink/remotenestedstruct1interface.h"
#include "testbed2/generated/monitor/nestedstruct1interface.tracedecorator.h"
#include "testbed2/generated/olink/remotenestedstruct2interface.h"
#include "testbed2/generated/monitor/nestedstruct2interface.tracedecorator.h"
#include "testbed2/generated/olink/remotenestedstruct3interface.h"
#include "testbed2/generated/monitor/nestedstruct3interface.tracedecorator.h"
#include "tb_enum/generated/olink/remoteenuminterface.h"
#include "tb_enum/generated/monitor/enuminterface.tracedecorator.h"
#include "tb_same1/generated/olink/remotesamestruct1interface.h"
#include "tb_same1/generated/monitor/samestruct1interface.tracedecorator.h"
#include "tb_same1/generated/olink/remotesamestruct2interface.h"
#include "tb_same1/generated/monitor/samestruct2interface.tracedecorator.h"
#include "tb_same1/generated/olink/remotesameenum1interface.h"
#include "tb_same1/generated/monitor/sameenum1interface.tracedecorator.h"
#include "tb_same1/generated/olink/remotesameenum2interface.h"
#include "tb_same1/generated/monitor/sameenum2interface.tracedecorator.h"
#include "tb_same2/generated/olink/remotesamestruct1interface.h"
#include "tb_same2/generated/monitor/samestruct1interface.tracedecorator.h"
#include "tb_same2/generated/olink/remotesamestruct2interface.h"
#include "tb_same2/generated/monitor/samestruct2interface.tracedecorator.h"
#include "tb_same2/generated/olink/remotesameenum1interface.h"
#include "tb_same2/generated/monitor/sameenum1interface.tracedecorator.h"
#include "tb_same2/generated/olink/remotesameenum2interface.h"
#include "tb_same2/generated/monitor/sameenum2interface.tracedecorator.h"
#include "tb_simple/generated/olink/remotesimpleinterface.h"
#include "tb_simple/generated/monitor/simpleinterface.tracedecorator.h"
#include "tb_simple/generated/olink/remotesimplearrayinterface.h"
#include "tb_simple/generated/monitor/simplearrayinterface.tracedecorator.h"
#include "testbed1/generated/olink/remotestructinterface.h"
#include "testbed1/generated/monitor/structinterface.tracedecorator.h"
#include "testbed1/generated/olink/remotestructarrayinterface.h"
#include "testbed1/generated/monitor/structarrayinterface.tracedecorator.h"

#include "apigear/olink/olinkconnection.h"
#include "apigear/tracer/tracer.h"
#include "olink/consolelogger.h"
#include "olink/clientregistry.h"

using namespace Test;

int main(){
    ApiGear::PocoImpl::Tracer tracer;
    tracer.connect("http://localhost:5555", "testExampleOLinkApp");
    ApiGear::ObjectLink::ClientRegistry registry;
    ApiGear::ObjectLink::ConsoleLogger logger;
    registry.onLog(logger.logFunc());
    auto testClient = ApiGear::PocoImpl::OlinkConnection::create(registry);
    testClient->node().onLog(logger.logFunc());
    std::unique_ptr<Testbed2::IManyParamInterface> testTestbed2ManyParamInterface = std::make_unique<Testbed2::olink::RemoteManyParamInterface>(testClient);
    std::unique_ptr<Testbed2::IManyParamInterface> testTestbed2ManyParamInterfaceTraceDecorator = Testbed2::ManyParamInterfaceTraceDecorator::connect(*testTestbed2ManyParamInterface, tracer);
    std::unique_ptr<Testbed2::INestedStruct1Interface> testTestbed2NestedStruct1Interface = std::make_unique<Testbed2::olink::RemoteNestedStruct1Interface>(testClient);
    std::unique_ptr<Testbed2::INestedStruct1Interface> testTestbed2NestedStruct1InterfaceTraceDecorator = Testbed2::NestedStruct1InterfaceTraceDecorator::connect(*testTestbed2NestedStruct1Interface, tracer);
    std::unique_ptr<Testbed2::INestedStruct2Interface> testTestbed2NestedStruct2Interface = std::make_unique<Testbed2::olink::RemoteNestedStruct2Interface>(testClient);
    std::unique_ptr<Testbed2::INestedStruct2Interface> testTestbed2NestedStruct2InterfaceTraceDecorator = Testbed2::NestedStruct2InterfaceTraceDecorator::connect(*testTestbed2NestedStruct2Interface, tracer);
    std::unique_ptr<Testbed2::INestedStruct3Interface> testTestbed2NestedStruct3Interface = std::make_unique<Testbed2::olink::RemoteNestedStruct3Interface>(testClient);
    std::unique_ptr<Testbed2::INestedStruct3Interface> testTestbed2NestedStruct3InterfaceTraceDecorator = Testbed2::NestedStruct3InterfaceTraceDecorator::connect(*testTestbed2NestedStruct3Interface, tracer);
    std::unique_ptr<TbEnum::IEnumInterface> testTbEnumEnumInterface = std::make_unique<TbEnum::olink::RemoteEnumInterface>(testClient);
    std::unique_ptr<TbEnum::IEnumInterface> testTbEnumEnumInterfaceTraceDecorator = TbEnum::EnumInterfaceTraceDecorator::connect(*testTbEnumEnumInterface, tracer);
    std::unique_ptr<TbSame1::ISameStruct1Interface> testTbSame1SameStruct1Interface = std::make_unique<TbSame1::olink::RemoteSameStruct1Interface>(testClient);
    std::unique_ptr<TbSame1::ISameStruct1Interface> testTbSame1SameStruct1InterfaceTraceDecorator = TbSame1::SameStruct1InterfaceTraceDecorator::connect(*testTbSame1SameStruct1Interface, tracer);
    std::unique_ptr<TbSame1::ISameStruct2Interface> testTbSame1SameStruct2Interface = std::make_unique<TbSame1::olink::RemoteSameStruct2Interface>(testClient);
    std::unique_ptr<TbSame1::ISameStruct2Interface> testTbSame1SameStruct2InterfaceTraceDecorator = TbSame1::SameStruct2InterfaceTraceDecorator::connect(*testTbSame1SameStruct2Interface, tracer);
    std::unique_ptr<TbSame1::ISameEnum1Interface> testTbSame1SameEnum1Interface = std::make_unique<TbSame1::olink::RemoteSameEnum1Interface>(testClient);
    std::unique_ptr<TbSame1::ISameEnum1Interface> testTbSame1SameEnum1InterfaceTraceDecorator = TbSame1::SameEnum1InterfaceTraceDecorator::connect(*testTbSame1SameEnum1Interface, tracer);
    std::unique_ptr<TbSame1::ISameEnum2Interface> testTbSame1SameEnum2Interface = std::make_unique<TbSame1::olink::RemoteSameEnum2Interface>(testClient);
    std::unique_ptr<TbSame1::ISameEnum2Interface> testTbSame1SameEnum2InterfaceTraceDecorator = TbSame1::SameEnum2InterfaceTraceDecorator::connect(*testTbSame1SameEnum2Interface, tracer);
    std::unique_ptr<TbSame2::ISameStruct1Interface> testTbSame2SameStruct1Interface = std::make_unique<TbSame2::olink::RemoteSameStruct1Interface>(testClient);
    std::unique_ptr<TbSame2::ISameStruct1Interface> testTbSame2SameStruct1InterfaceTraceDecorator = TbSame2::SameStruct1InterfaceTraceDecorator::connect(*testTbSame2SameStruct1Interface, tracer);
    std::unique_ptr<TbSame2::ISameStruct2Interface> testTbSame2SameStruct2Interface = std::make_unique<TbSame2::olink::RemoteSameStruct2Interface>(testClient);
    std::unique_ptr<TbSame2::ISameStruct2Interface> testTbSame2SameStruct2InterfaceTraceDecorator = TbSame2::SameStruct2InterfaceTraceDecorator::connect(*testTbSame2SameStruct2Interface, tracer);
    std::unique_ptr<TbSame2::ISameEnum1Interface> testTbSame2SameEnum1Interface = std::make_unique<TbSame2::olink::RemoteSameEnum1Interface>(testClient);
    std::unique_ptr<TbSame2::ISameEnum1Interface> testTbSame2SameEnum1InterfaceTraceDecorator = TbSame2::SameEnum1InterfaceTraceDecorator::connect(*testTbSame2SameEnum1Interface, tracer);
    std::unique_ptr<TbSame2::ISameEnum2Interface> testTbSame2SameEnum2Interface = std::make_unique<TbSame2::olink::RemoteSameEnum2Interface>(testClient);
    std::unique_ptr<TbSame2::ISameEnum2Interface> testTbSame2SameEnum2InterfaceTraceDecorator = TbSame2::SameEnum2InterfaceTraceDecorator::connect(*testTbSame2SameEnum2Interface, tracer);
    std::unique_ptr<TbSimple::ISimpleInterface> testTbSimpleSimpleInterface = std::make_unique<TbSimple::olink::RemoteSimpleInterface>(testClient);
    std::unique_ptr<TbSimple::ISimpleInterface> testTbSimpleSimpleInterfaceTraceDecorator = TbSimple::SimpleInterfaceTraceDecorator::connect(*testTbSimpleSimpleInterface, tracer);
    std::unique_ptr<TbSimple::ISimpleArrayInterface> testTbSimpleSimpleArrayInterface = std::make_unique<TbSimple::olink::RemoteSimpleArrayInterface>(testClient);
    std::unique_ptr<TbSimple::ISimpleArrayInterface> testTbSimpleSimpleArrayInterfaceTraceDecorator = TbSimple::SimpleArrayInterfaceTraceDecorator::connect(*testTbSimpleSimpleArrayInterface, tracer);
    std::unique_ptr<Testbed1::IStructInterface> testTestbed1StructInterface = std::make_unique<Testbed1::olink::RemoteStructInterface>(testClient);
    std::unique_ptr<Testbed1::IStructInterface> testTestbed1StructInterfaceTraceDecorator = Testbed1::StructInterfaceTraceDecorator::connect(*testTestbed1StructInterface, tracer);
    std::unique_ptr<Testbed1::IStructArrayInterface> testTestbed1StructArrayInterface = std::make_unique<Testbed1::olink::RemoteStructArrayInterface>(testClient);
    std::unique_ptr<Testbed1::IStructArrayInterface> testTestbed1StructArrayInterfaceTraceDecorator = Testbed1::StructArrayInterfaceTraceDecorator::connect(*testTestbed1StructArrayInterface, tracer);
    
    testClient->connectToHost(Poco::URI("ws://localhost:8000"));

    bool keepRunning = true;
    std::string cmd;
    do {
        std::cout << "Enter command:" << std::endl;
        getline (std::cin, cmd);

        if(cmd == "quit"){
            keepRunning = false;
            testClient->disconnect();
        }
    } while(keepRunning);

    return 0;
}
