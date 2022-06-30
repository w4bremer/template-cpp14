#include <iostream>
#include "generated/olink/testbed2_manyparaminterfaceinterface.h"
#include "generated/monitor/testbed2_manyparaminterface.trace.h"
#include "generated/olink/testbed2_nestedstruct1interfaceinterface.h"
#include "generated/monitor/testbed2_nestedstruct1interface.trace.h"
#include "generated/olink/testbed2_nestedstruct2interfaceinterface.h"
#include "generated/monitor/testbed2_nestedstruct2interface.trace.h"
#include "generated/olink/testbed2_nestedstruct3interfaceinterface.h"
#include "generated/monitor/testbed2_nestedstruct3interface.trace.h"
#include "generated/olink/tb_enum_enuminterfaceinterface.h"
#include "generated/monitor/tb_enum_enuminterface.trace.h"
#include "generated/olink/tb_same1_samestruct1interfaceinterface.h"
#include "generated/monitor/tb_same1_samestruct1interface.trace.h"
#include "generated/olink/tb_same1_samestruct2interfaceinterface.h"
#include "generated/monitor/tb_same1_samestruct2interface.trace.h"
#include "generated/olink/tb_same1_sameenum1interfaceinterface.h"
#include "generated/monitor/tb_same1_sameenum1interface.trace.h"
#include "generated/olink/tb_same1_sameenum2interfaceinterface.h"
#include "generated/monitor/tb_same1_sameenum2interface.trace.h"
#include "generated/olink/tb_same2_samestruct1interfaceinterface.h"
#include "generated/monitor/tb_same2_samestruct1interface.trace.h"
#include "generated/olink/tb_same2_samestruct2interfaceinterface.h"
#include "generated/monitor/tb_same2_samestruct2interface.trace.h"
#include "generated/olink/tb_same2_sameenum1interfaceinterface.h"
#include "generated/monitor/tb_same2_sameenum1interface.trace.h"
#include "generated/olink/tb_same2_sameenum2interfaceinterface.h"
#include "generated/monitor/tb_same2_sameenum2interface.trace.h"
#include "generated/olink/tb_simple_simpleinterfaceinterface.h"
#include "generated/monitor/tb_simple_simpleinterface.trace.h"
#include "generated/olink/tb_simple_simplearrayinterfaceinterface.h"
#include "generated/monitor/tb_simple_simplearrayinterface.trace.h"
#include "generated/olink/testbed1_structinterfaceinterface.h"
#include "generated/monitor/testbed1_structinterface.trace.h"
#include "generated/olink/testbed1_structarrayinterfaceinterface.h"
#include "generated/monitor/testbed1_structarrayinterface.trace.h"
#include "apigear/olink/olinkclient.h"
#include "apigear/tracer/tracer.h"

using namespace Test;

int main(){
    ApiGear::PocoImpl::Tracer tracer;
    tracer.connect("http://localhost:5555", "testExampleOLinkApp");
    ApiGear::ObjectLink::ClientRegistry registry;
    ApiGear::PocoImpl::OLinkClient testClient(registry);
    std::unique_ptr<Testbed2::IManyParamInterface> testTestbed2ManyParamInterface = std::make_unique<Testbed2::OLinkManyParamInterface>(registry, testClient);
    std::unique_ptr<Testbed2::IManyParamInterfaceDecorator> testTestbed2ManyParamInterfaceTracerDecorator(Testbed2::ManyParamInterfaceTracerDecorator::connect(testTestbed2ManyParamInterface.get(), &tracer));
    std::unique_ptr<Testbed2::INestedStruct1Interface> testTestbed2NestedStruct1Interface = std::make_unique<Testbed2::OLinkNestedStruct1Interface>(registry, testClient);
    std::unique_ptr<Testbed2::INestedStruct1InterfaceDecorator> testTestbed2NestedStruct1InterfaceTracerDecorator(Testbed2::NestedStruct1InterfaceTracerDecorator::connect(testTestbed2NestedStruct1Interface.get(), &tracer));
    std::unique_ptr<Testbed2::INestedStruct2Interface> testTestbed2NestedStruct2Interface = std::make_unique<Testbed2::OLinkNestedStruct2Interface>(registry, testClient);
    std::unique_ptr<Testbed2::INestedStruct2InterfaceDecorator> testTestbed2NestedStruct2InterfaceTracerDecorator(Testbed2::NestedStruct2InterfaceTracerDecorator::connect(testTestbed2NestedStruct2Interface.get(), &tracer));
    std::unique_ptr<Testbed2::INestedStruct3Interface> testTestbed2NestedStruct3Interface = std::make_unique<Testbed2::OLinkNestedStruct3Interface>(registry, testClient);
    std::unique_ptr<Testbed2::INestedStruct3InterfaceDecorator> testTestbed2NestedStruct3InterfaceTracerDecorator(Testbed2::NestedStruct3InterfaceTracerDecorator::connect(testTestbed2NestedStruct3Interface.get(), &tracer));
    std::unique_ptr<TbEnum::IEnumInterface> testTbEnumEnumInterface = std::make_unique<TbEnum::OLinkEnumInterface>(registry, testClient);
    std::unique_ptr<TbEnum::IEnumInterfaceDecorator> testTbEnumEnumInterfaceTracerDecorator(TbEnum::EnumInterfaceTracerDecorator::connect(testTbEnumEnumInterface.get(), &tracer));
    std::unique_ptr<TbSame1::ISameStruct1Interface> testTbSame1SameStruct1Interface = std::make_unique<TbSame1::OLinkSameStruct1Interface>(registry, testClient);
    std::unique_ptr<TbSame1::ISameStruct1InterfaceDecorator> testTbSame1SameStruct1InterfaceTracerDecorator(TbSame1::SameStruct1InterfaceTracerDecorator::connect(testTbSame1SameStruct1Interface.get(), &tracer));
    std::unique_ptr<TbSame1::ISameStruct2Interface> testTbSame1SameStruct2Interface = std::make_unique<TbSame1::OLinkSameStruct2Interface>(registry, testClient);
    std::unique_ptr<TbSame1::ISameStruct2InterfaceDecorator> testTbSame1SameStruct2InterfaceTracerDecorator(TbSame1::SameStruct2InterfaceTracerDecorator::connect(testTbSame1SameStruct2Interface.get(), &tracer));
    std::unique_ptr<TbSame1::ISameEnum1Interface> testTbSame1SameEnum1Interface = std::make_unique<TbSame1::OLinkSameEnum1Interface>(registry, testClient);
    std::unique_ptr<TbSame1::ISameEnum1InterfaceDecorator> testTbSame1SameEnum1InterfaceTracerDecorator(TbSame1::SameEnum1InterfaceTracerDecorator::connect(testTbSame1SameEnum1Interface.get(), &tracer));
    std::unique_ptr<TbSame1::ISameEnum2Interface> testTbSame1SameEnum2Interface = std::make_unique<TbSame1::OLinkSameEnum2Interface>(registry, testClient);
    std::unique_ptr<TbSame1::ISameEnum2InterfaceDecorator> testTbSame1SameEnum2InterfaceTracerDecorator(TbSame1::SameEnum2InterfaceTracerDecorator::connect(testTbSame1SameEnum2Interface.get(), &tracer));
    std::unique_ptr<TbSame2::ISameStruct1Interface> testTbSame2SameStruct1Interface = std::make_unique<TbSame2::OLinkSameStruct1Interface>(registry, testClient);
    std::unique_ptr<TbSame2::ISameStruct1InterfaceDecorator> testTbSame2SameStruct1InterfaceTracerDecorator(TbSame2::SameStruct1InterfaceTracerDecorator::connect(testTbSame2SameStruct1Interface.get(), &tracer));
    std::unique_ptr<TbSame2::ISameStruct2Interface> testTbSame2SameStruct2Interface = std::make_unique<TbSame2::OLinkSameStruct2Interface>(registry, testClient);
    std::unique_ptr<TbSame2::ISameStruct2InterfaceDecorator> testTbSame2SameStruct2InterfaceTracerDecorator(TbSame2::SameStruct2InterfaceTracerDecorator::connect(testTbSame2SameStruct2Interface.get(), &tracer));
    std::unique_ptr<TbSame2::ISameEnum1Interface> testTbSame2SameEnum1Interface = std::make_unique<TbSame2::OLinkSameEnum1Interface>(registry, testClient);
    std::unique_ptr<TbSame2::ISameEnum1InterfaceDecorator> testTbSame2SameEnum1InterfaceTracerDecorator(TbSame2::SameEnum1InterfaceTracerDecorator::connect(testTbSame2SameEnum1Interface.get(), &tracer));
    std::unique_ptr<TbSame2::ISameEnum2Interface> testTbSame2SameEnum2Interface = std::make_unique<TbSame2::OLinkSameEnum2Interface>(registry, testClient);
    std::unique_ptr<TbSame2::ISameEnum2InterfaceDecorator> testTbSame2SameEnum2InterfaceTracerDecorator(TbSame2::SameEnum2InterfaceTracerDecorator::connect(testTbSame2SameEnum2Interface.get(), &tracer));
    std::unique_ptr<TbSimple::ISimpleInterface> testTbSimpleSimpleInterface = std::make_unique<TbSimple::OLinkSimpleInterface>(registry, testClient);
    std::unique_ptr<TbSimple::ISimpleInterfaceDecorator> testTbSimpleSimpleInterfaceTracerDecorator(TbSimple::SimpleInterfaceTracerDecorator::connect(testTbSimpleSimpleInterface.get(), &tracer));
    std::unique_ptr<TbSimple::ISimpleArrayInterface> testTbSimpleSimpleArrayInterface = std::make_unique<TbSimple::OLinkSimpleArrayInterface>(registry, testClient);
    std::unique_ptr<TbSimple::ISimpleArrayInterfaceDecorator> testTbSimpleSimpleArrayInterfaceTracerDecorator(TbSimple::SimpleArrayInterfaceTracerDecorator::connect(testTbSimpleSimpleArrayInterface.get(), &tracer));
    std::unique_ptr<Testbed1::IStructInterface> testTestbed1StructInterface = std::make_unique<Testbed1::OLinkStructInterface>(registry, testClient);
    std::unique_ptr<Testbed1::IStructInterfaceDecorator> testTestbed1StructInterfaceTracerDecorator(Testbed1::StructInterfaceTracerDecorator::connect(testTestbed1StructInterface.get(), &tracer));
    std::unique_ptr<Testbed1::IStructArrayInterface> testTestbed1StructArrayInterface = std::make_unique<Testbed1::OLinkStructArrayInterface>(registry, testClient);
    std::unique_ptr<Testbed1::IStructArrayInterfaceDecorator> testTestbed1StructArrayInterfaceTracerDecorator(Testbed1::StructArrayInterfaceTracerDecorator::connect(testTestbed1StructArrayInterface.get(), &tracer));
    
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
