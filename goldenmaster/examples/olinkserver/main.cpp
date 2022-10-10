
#include "testbed2/implementation/manyparaminterface.h"
#include "testbed2/generated/olink/manyparaminterfaceservice.adapter.h"
#include "testbed2/implementation/nestedstruct1interface.h"
#include "testbed2/generated/olink/nestedstruct1interfaceservice.adapter.h"
#include "testbed2/implementation/nestedstruct2interface.h"
#include "testbed2/generated/olink/nestedstruct2interfaceservice.adapter.h"
#include "testbed2/implementation/nestedstruct3interface.h"
#include "testbed2/generated/olink/nestedstruct3interfaceservice.adapter.h"
#include "tb_enum/implementation/enuminterface.h"
#include "tb_enum/generated/olink/enuminterfaceservice.adapter.h"
#include "tb_same1/implementation/samestruct1interface.h"
#include "tb_same1/generated/olink/samestruct1interfaceservice.adapter.h"
#include "tb_same1/implementation/samestruct2interface.h"
#include "tb_same1/generated/olink/samestruct2interfaceservice.adapter.h"
#include "tb_same1/implementation/sameenum1interface.h"
#include "tb_same1/generated/olink/sameenum1interfaceservice.adapter.h"
#include "tb_same1/implementation/sameenum2interface.h"
#include "tb_same1/generated/olink/sameenum2interfaceservice.adapter.h"
#include "tb_same2/implementation/samestruct1interface.h"
#include "tb_same2/generated/olink/samestruct1interfaceservice.adapter.h"
#include "tb_same2/implementation/samestruct2interface.h"
#include "tb_same2/generated/olink/samestruct2interfaceservice.adapter.h"
#include "tb_same2/implementation/sameenum1interface.h"
#include "tb_same2/generated/olink/sameenum1interfaceservice.adapter.h"
#include "tb_same2/implementation/sameenum2interface.h"
#include "tb_same2/generated/olink/sameenum2interfaceservice.adapter.h"
#include "tb_simple/implementation/simpleinterface.h"
#include "tb_simple/generated/olink/simpleinterfaceservice.adapter.h"
#include "tb_simple/implementation/simplearrayinterface.h"
#include "tb_simple/generated/olink/simplearrayinterfaceservice.adapter.h"
#include "testbed1/implementation/structinterface.h"
#include "testbed1/generated/olink/structinterfaceservice.adapter.h"
#include "testbed1/implementation/structarrayinterface.h"
#include "testbed1/generated/olink/structarrayinterfaceservice.adapter.h"

#include "olink/consolelogger.h"
#include "olink/remoteregistry.h"
#include "apigear/olink/olinkhost.h"

#include <iostream>

using namespace Test;

int main(){
    ApiGear::ObjectLink::RemoteRegistry registry;
    ApiGear::ObjectLink::ConsoleLogger logger;
    registry.onLog(logger.logFunc());
    
    ApiGear::PocoImpl::OLinkHost testserver(registry);
    auto testTestbed2ManyParamInterface = std::make_shared<Testbed2::ManyParamInterface>();
    auto testTestbed2ManyParamInterfaceServiceAdapter = std::make_shared<Testbed2::olink::ManyParamInterfaceServiceAdapter>(testTestbed2ManyParamInterface, registry);
    registry.addSource(testTestbed2ManyParamInterfaceServiceAdapter);
    auto testTestbed2NestedStruct1Interface = std::make_shared<Testbed2::NestedStruct1Interface>();
    auto testTestbed2NestedStruct1InterfaceServiceAdapter = std::make_shared<Testbed2::olink::NestedStruct1InterfaceServiceAdapter>(testTestbed2NestedStruct1Interface, registry);
    registry.addSource(testTestbed2NestedStruct1InterfaceServiceAdapter);
    auto testTestbed2NestedStruct2Interface = std::make_shared<Testbed2::NestedStruct2Interface>();
    auto testTestbed2NestedStruct2InterfaceServiceAdapter = std::make_shared<Testbed2::olink::NestedStruct2InterfaceServiceAdapter>(testTestbed2NestedStruct2Interface, registry);
    registry.addSource(testTestbed2NestedStruct2InterfaceServiceAdapter);
    auto testTestbed2NestedStruct3Interface = std::make_shared<Testbed2::NestedStruct3Interface>();
    auto testTestbed2NestedStruct3InterfaceServiceAdapter = std::make_shared<Testbed2::olink::NestedStruct3InterfaceServiceAdapter>(testTestbed2NestedStruct3Interface, registry);
    registry.addSource(testTestbed2NestedStruct3InterfaceServiceAdapter);
    auto testTbEnumEnumInterface = std::make_shared<TbEnum::EnumInterface>();
    auto testTbEnumEnumInterfaceServiceAdapter = std::make_shared<TbEnum::olink::EnumInterfaceServiceAdapter>(testTbEnumEnumInterface, registry);
    registry.addSource(testTbEnumEnumInterfaceServiceAdapter);
    auto testTbSame1SameStruct1Interface = std::make_shared<TbSame1::SameStruct1Interface>();
    auto testTbSame1SameStruct1InterfaceServiceAdapter = std::make_shared<TbSame1::olink::SameStruct1InterfaceServiceAdapter>(testTbSame1SameStruct1Interface, registry);
    registry.addSource(testTbSame1SameStruct1InterfaceServiceAdapter);
    auto testTbSame1SameStruct2Interface = std::make_shared<TbSame1::SameStruct2Interface>();
    auto testTbSame1SameStruct2InterfaceServiceAdapter = std::make_shared<TbSame1::olink::SameStruct2InterfaceServiceAdapter>(testTbSame1SameStruct2Interface, registry);
    registry.addSource(testTbSame1SameStruct2InterfaceServiceAdapter);
    auto testTbSame1SameEnum1Interface = std::make_shared<TbSame1::SameEnum1Interface>();
    auto testTbSame1SameEnum1InterfaceServiceAdapter = std::make_shared<TbSame1::olink::SameEnum1InterfaceServiceAdapter>(testTbSame1SameEnum1Interface, registry);
    registry.addSource(testTbSame1SameEnum1InterfaceServiceAdapter);
    auto testTbSame1SameEnum2Interface = std::make_shared<TbSame1::SameEnum2Interface>();
    auto testTbSame1SameEnum2InterfaceServiceAdapter = std::make_shared<TbSame1::olink::SameEnum2InterfaceServiceAdapter>(testTbSame1SameEnum2Interface, registry);
    registry.addSource(testTbSame1SameEnum2InterfaceServiceAdapter);
    auto testTbSame2SameStruct1Interface = std::make_shared<TbSame2::SameStruct1Interface>();
    auto testTbSame2SameStruct1InterfaceServiceAdapter = std::make_shared<TbSame2::olink::SameStruct1InterfaceServiceAdapter>(testTbSame2SameStruct1Interface, registry);
    registry.addSource(testTbSame2SameStruct1InterfaceServiceAdapter);
    auto testTbSame2SameStruct2Interface = std::make_shared<TbSame2::SameStruct2Interface>();
    auto testTbSame2SameStruct2InterfaceServiceAdapter = std::make_shared<TbSame2::olink::SameStruct2InterfaceServiceAdapter>(testTbSame2SameStruct2Interface, registry);
    registry.addSource(testTbSame2SameStruct2InterfaceServiceAdapter);
    auto testTbSame2SameEnum1Interface = std::make_shared<TbSame2::SameEnum1Interface>();
    auto testTbSame2SameEnum1InterfaceServiceAdapter = std::make_shared<TbSame2::olink::SameEnum1InterfaceServiceAdapter>(testTbSame2SameEnum1Interface, registry);
    registry.addSource(testTbSame2SameEnum1InterfaceServiceAdapter);
    auto testTbSame2SameEnum2Interface = std::make_shared<TbSame2::SameEnum2Interface>();
    auto testTbSame2SameEnum2InterfaceServiceAdapter = std::make_shared<TbSame2::olink::SameEnum2InterfaceServiceAdapter>(testTbSame2SameEnum2Interface, registry);
    registry.addSource(testTbSame2SameEnum2InterfaceServiceAdapter);
    auto testTbSimpleSimpleInterface = std::make_shared<TbSimple::SimpleInterface>();
    auto testTbSimpleSimpleInterfaceServiceAdapter = std::make_shared<TbSimple::olink::SimpleInterfaceServiceAdapter>(testTbSimpleSimpleInterface, registry);
    registry.addSource(testTbSimpleSimpleInterfaceServiceAdapter);
    auto testTbSimpleSimpleArrayInterface = std::make_shared<TbSimple::SimpleArrayInterface>();
    auto testTbSimpleSimpleArrayInterfaceServiceAdapter = std::make_shared<TbSimple::olink::SimpleArrayInterfaceServiceAdapter>(testTbSimpleSimpleArrayInterface, registry);
    registry.addSource(testTbSimpleSimpleArrayInterfaceServiceAdapter);
    auto testTestbed1StructInterface = std::make_shared<Testbed1::StructInterface>();
    auto testTestbed1StructInterfaceServiceAdapter = std::make_shared<Testbed1::olink::StructInterfaceServiceAdapter>(testTestbed1StructInterface, registry);
    registry.addSource(testTestbed1StructInterfaceServiceAdapter);
    auto testTestbed1StructArrayInterface = std::make_shared<Testbed1::StructArrayInterface>();
    auto testTestbed1StructArrayInterfaceServiceAdapter = std::make_shared<Testbed1::olink::StructArrayInterfaceServiceAdapter>(testTestbed1StructArrayInterface, registry);
    registry.addSource(testTestbed1StructArrayInterfaceServiceAdapter);

    testserver.listen(8000);

    bool keepRunning = true;
    std::string cmd;
    do {
        std::cout << "Enter command:" << std::endl;
        getline (std::cin, cmd);

        if(cmd == "quit"){
            testserver.close();
            keepRunning = false;
        }
    } while(keepRunning);
    registry.removeSource(testTestbed2ManyParamInterfaceServiceAdapter->olinkObjectName());
    registry.removeSource(testTestbed2NestedStruct1InterfaceServiceAdapter->olinkObjectName());
    registry.removeSource(testTestbed2NestedStruct2InterfaceServiceAdapter->olinkObjectName());
    registry.removeSource(testTestbed2NestedStruct3InterfaceServiceAdapter->olinkObjectName());
    registry.removeSource(testTbEnumEnumInterfaceServiceAdapter->olinkObjectName());
    registry.removeSource(testTbSame1SameStruct1InterfaceServiceAdapter->olinkObjectName());
    registry.removeSource(testTbSame1SameStruct2InterfaceServiceAdapter->olinkObjectName());
    registry.removeSource(testTbSame1SameEnum1InterfaceServiceAdapter->olinkObjectName());
    registry.removeSource(testTbSame1SameEnum2InterfaceServiceAdapter->olinkObjectName());
    registry.removeSource(testTbSame2SameStruct1InterfaceServiceAdapter->olinkObjectName());
    registry.removeSource(testTbSame2SameStruct2InterfaceServiceAdapter->olinkObjectName());
    registry.removeSource(testTbSame2SameEnum1InterfaceServiceAdapter->olinkObjectName());
    registry.removeSource(testTbSame2SameEnum2InterfaceServiceAdapter->olinkObjectName());
    registry.removeSource(testTbSimpleSimpleInterfaceServiceAdapter->olinkObjectName());
    registry.removeSource(testTbSimpleSimpleArrayInterfaceServiceAdapter->olinkObjectName());
    registry.removeSource(testTestbed1StructInterfaceServiceAdapter->olinkObjectName());
    registry.removeSource(testTestbed1StructArrayInterfaceServiceAdapter->olinkObjectName());
    
    return 0;
}
