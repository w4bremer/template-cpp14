#include <iostream>
#include "testbed2/generated/olink/remotemanyparaminterface.h"
#include "testbed2/generated/monitor/manyparaminterface.trace.h"
#include "testbed2/generated/olink/remotenestedstruct1interface.h"
#include "testbed2/generated/monitor/nestedstruct1interface.trace.h"
#include "testbed2/generated/olink/remotenestedstruct2interface.h"
#include "testbed2/generated/monitor/nestedstruct2interface.trace.h"
#include "testbed2/generated/olink/remotenestedstruct3interface.h"
#include "testbed2/generated/monitor/nestedstruct3interface.trace.h"
#include "tb_enum/generated/olink/remoteenuminterface.h"
#include "tb_enum/generated/monitor/enuminterface.trace.h"
#include "tb_same1/generated/olink/remotesamestruct1interface.h"
#include "tb_same1/generated/monitor/samestruct1interface.trace.h"
#include "tb_same1/generated/olink/remotesamestruct2interface.h"
#include "tb_same1/generated/monitor/samestruct2interface.trace.h"
#include "tb_same1/generated/olink/remotesameenum1interface.h"
#include "tb_same1/generated/monitor/sameenum1interface.trace.h"
#include "tb_same1/generated/olink/remotesameenum2interface.h"
#include "tb_same1/generated/monitor/sameenum2interface.trace.h"
#include "tb_same2/generated/olink/remotesamestruct1interface.h"
#include "tb_same2/generated/monitor/samestruct1interface.trace.h"
#include "tb_same2/generated/olink/remotesamestruct2interface.h"
#include "tb_same2/generated/monitor/samestruct2interface.trace.h"
#include "tb_same2/generated/olink/remotesameenum1interface.h"
#include "tb_same2/generated/monitor/sameenum1interface.trace.h"
#include "tb_same2/generated/olink/remotesameenum2interface.h"
#include "tb_same2/generated/monitor/sameenum2interface.trace.h"
#include "tb_simple/generated/olink/remotesimpleinterface.h"
#include "tb_simple/generated/monitor/simpleinterface.trace.h"
#include "tb_simple/generated/olink/remotesimplearrayinterface.h"
#include "tb_simple/generated/monitor/simplearrayinterface.trace.h"
#include "testbed1/generated/olink/remotestructinterface.h"
#include "testbed1/generated/monitor/structinterface.trace.h"
#include "testbed1/generated/olink/remotestructarrayinterface.h"
#include "testbed1/generated/monitor/structarrayinterface.trace.h"
#include "apigear/olink/olinkclient.h"
#include "apigear/tracer/tracer.h"

using namespace Test;

int main(){
    ApiGear::PocoImpl::Tracer tracer;
    tracer.connect("http://localhost:5555", "testExampleOLinkApp");
    ApiGear::ObjectLink::ClientRegistry registry;
    ApiGear::PocoImpl::OLinkClient testClient(registry);
    std::unique_ptr<Testbed2::IManyParamInterface> testTestbed2ManyParamInterface = std::make_unique<Testbed2::olink::RemoteManyParamInterface>(registry, testClient);
    std::unique_ptr<Testbed2::IManyParamInterface> testTestbed2ManyParamInterfaceTracerDecorator(Testbed2::ManyParamInterfaceTracerDecorator::connect(testTestbed2ManyParamInterface.get(), tracer));
    std::unique_ptr<Testbed2::INestedStruct1Interface> testTestbed2NestedStruct1Interface = std::make_unique<Testbed2::olink::RemoteNestedStruct1Interface>(registry, testClient);
    std::unique_ptr<Testbed2::INestedStruct1Interface> testTestbed2NestedStruct1InterfaceTracerDecorator(Testbed2::NestedStruct1InterfaceTracerDecorator::connect(testTestbed2NestedStruct1Interface.get(), tracer));
    std::unique_ptr<Testbed2::INestedStruct2Interface> testTestbed2NestedStruct2Interface = std::make_unique<Testbed2::olink::RemoteNestedStruct2Interface>(registry, testClient);
    std::unique_ptr<Testbed2::INestedStruct2Interface> testTestbed2NestedStruct2InterfaceTracerDecorator(Testbed2::NestedStruct2InterfaceTracerDecorator::connect(testTestbed2NestedStruct2Interface.get(), tracer));
    std::unique_ptr<Testbed2::INestedStruct3Interface> testTestbed2NestedStruct3Interface = std::make_unique<Testbed2::olink::RemoteNestedStruct3Interface>(registry, testClient);
    std::unique_ptr<Testbed2::INestedStruct3Interface> testTestbed2NestedStruct3InterfaceTracerDecorator(Testbed2::NestedStruct3InterfaceTracerDecorator::connect(testTestbed2NestedStruct3Interface.get(), tracer));
    std::unique_ptr<TbEnum::IEnumInterface> testTbEnumEnumInterface = std::make_unique<TbEnum::olink::RemoteEnumInterface>(registry, testClient);
    std::unique_ptr<TbEnum::IEnumInterface> testTbEnumEnumInterfaceTracerDecorator(TbEnum::EnumInterfaceTracerDecorator::connect(testTbEnumEnumInterface.get(), tracer));
    std::unique_ptr<TbSame1::ISameStruct1Interface> testTbSame1SameStruct1Interface = std::make_unique<TbSame1::olink::RemoteSameStruct1Interface>(registry, testClient);
    std::unique_ptr<TbSame1::ISameStruct1Interface> testTbSame1SameStruct1InterfaceTracerDecorator(TbSame1::SameStruct1InterfaceTracerDecorator::connect(testTbSame1SameStruct1Interface.get(), tracer));
    std::unique_ptr<TbSame1::ISameStruct2Interface> testTbSame1SameStruct2Interface = std::make_unique<TbSame1::olink::RemoteSameStruct2Interface>(registry, testClient);
    std::unique_ptr<TbSame1::ISameStruct2Interface> testTbSame1SameStruct2InterfaceTracerDecorator(TbSame1::SameStruct2InterfaceTracerDecorator::connect(testTbSame1SameStruct2Interface.get(), tracer));
    std::unique_ptr<TbSame1::ISameEnum1Interface> testTbSame1SameEnum1Interface = std::make_unique<TbSame1::olink::RemoteSameEnum1Interface>(registry, testClient);
    std::unique_ptr<TbSame1::ISameEnum1Interface> testTbSame1SameEnum1InterfaceTracerDecorator(TbSame1::SameEnum1InterfaceTracerDecorator::connect(testTbSame1SameEnum1Interface.get(), tracer));
    std::unique_ptr<TbSame1::ISameEnum2Interface> testTbSame1SameEnum2Interface = std::make_unique<TbSame1::olink::RemoteSameEnum2Interface>(registry, testClient);
    std::unique_ptr<TbSame1::ISameEnum2Interface> testTbSame1SameEnum2InterfaceTracerDecorator(TbSame1::SameEnum2InterfaceTracerDecorator::connect(testTbSame1SameEnum2Interface.get(), tracer));
    std::unique_ptr<TbSame2::ISameStruct1Interface> testTbSame2SameStruct1Interface = std::make_unique<TbSame2::olink::RemoteSameStruct1Interface>(registry, testClient);
    std::unique_ptr<TbSame2::ISameStruct1Interface> testTbSame2SameStruct1InterfaceTracerDecorator(TbSame2::SameStruct1InterfaceTracerDecorator::connect(testTbSame2SameStruct1Interface.get(), tracer));
    std::unique_ptr<TbSame2::ISameStruct2Interface> testTbSame2SameStruct2Interface = std::make_unique<TbSame2::olink::RemoteSameStruct2Interface>(registry, testClient);
    std::unique_ptr<TbSame2::ISameStruct2Interface> testTbSame2SameStruct2InterfaceTracerDecorator(TbSame2::SameStruct2InterfaceTracerDecorator::connect(testTbSame2SameStruct2Interface.get(), tracer));
    std::unique_ptr<TbSame2::ISameEnum1Interface> testTbSame2SameEnum1Interface = std::make_unique<TbSame2::olink::RemoteSameEnum1Interface>(registry, testClient);
    std::unique_ptr<TbSame2::ISameEnum1Interface> testTbSame2SameEnum1InterfaceTracerDecorator(TbSame2::SameEnum1InterfaceTracerDecorator::connect(testTbSame2SameEnum1Interface.get(), tracer));
    std::unique_ptr<TbSame2::ISameEnum2Interface> testTbSame2SameEnum2Interface = std::make_unique<TbSame2::olink::RemoteSameEnum2Interface>(registry, testClient);
    std::unique_ptr<TbSame2::ISameEnum2Interface> testTbSame2SameEnum2InterfaceTracerDecorator(TbSame2::SameEnum2InterfaceTracerDecorator::connect(testTbSame2SameEnum2Interface.get(), tracer));
    std::unique_ptr<TbSimple::ISimpleInterface> testTbSimpleSimpleInterface = std::make_unique<TbSimple::olink::RemoteSimpleInterface>(registry, testClient);
    std::unique_ptr<TbSimple::ISimpleInterface> testTbSimpleSimpleInterfaceTracerDecorator(TbSimple::SimpleInterfaceTracerDecorator::connect(testTbSimpleSimpleInterface.get(), tracer));
    std::unique_ptr<TbSimple::ISimpleArrayInterface> testTbSimpleSimpleArrayInterface = std::make_unique<TbSimple::olink::RemoteSimpleArrayInterface>(registry, testClient);
    std::unique_ptr<TbSimple::ISimpleArrayInterface> testTbSimpleSimpleArrayInterfaceTracerDecorator(TbSimple::SimpleArrayInterfaceTracerDecorator::connect(testTbSimpleSimpleArrayInterface.get(), tracer));
    std::unique_ptr<Testbed1::IStructInterface> testTestbed1StructInterface = std::make_unique<Testbed1::olink::RemoteStructInterface>(registry, testClient);
    std::unique_ptr<Testbed1::IStructInterface> testTestbed1StructInterfaceTracerDecorator(Testbed1::StructInterfaceTracerDecorator::connect(testTestbed1StructInterface.get(), tracer));
    std::unique_ptr<Testbed1::IStructArrayInterface> testTestbed1StructArrayInterface = std::make_unique<Testbed1::olink::RemoteStructArrayInterface>(registry, testClient);
    std::unique_ptr<Testbed1::IStructArrayInterface> testTestbed1StructArrayInterfaceTracerDecorator(Testbed1::StructArrayInterfaceTracerDecorator::connect(testTestbed1StructArrayInterface.get(), tracer));
    
    testClient.connectToHost(Poco::URI("ws://localhost:8000"));

    bool keepRunning = true;
    std::string cmd;
    do {
        std::cout << "Enter command:" << std::endl;
        getline (std::cin, cmd);

        if(cmd == "quit"){
            keepRunning = false;
            testClient.disconnect();
        }
    } while(keepRunning);

    return 0;
}
