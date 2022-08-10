#include <iostream>
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
#include "apigear/olink/olinkhost.h"

using namespace Test;

int main(){
    ApiGear::ObjectLink::RemoteRegistry registry;
    ApiGear::PocoImpl::OLinkHost testserver(registry);
    std::unique_ptr<Testbed2::IManyParamInterface> testTestbed2ManyParamInterface = std::make_unique<Testbed2::ManyParamInterface>();
    Testbed2::olink::ManyParamInterfaceServiceAdapter testTestbed2ManyParamInterfaceServiceAdapter(*testTestbed2ManyParamInterface, registry);
    std::unique_ptr<Testbed2::INestedStruct1Interface> testTestbed2NestedStruct1Interface = std::make_unique<Testbed2::NestedStruct1Interface>();
    Testbed2::olink::NestedStruct1InterfaceServiceAdapter testTestbed2NestedStruct1InterfaceServiceAdapter(*testTestbed2NestedStruct1Interface, registry);
    std::unique_ptr<Testbed2::INestedStruct2Interface> testTestbed2NestedStruct2Interface = std::make_unique<Testbed2::NestedStruct2Interface>();
    Testbed2::olink::NestedStruct2InterfaceServiceAdapter testTestbed2NestedStruct2InterfaceServiceAdapter(*testTestbed2NestedStruct2Interface, registry);
    std::unique_ptr<Testbed2::INestedStruct3Interface> testTestbed2NestedStruct3Interface = std::make_unique<Testbed2::NestedStruct3Interface>();
    Testbed2::olink::NestedStruct3InterfaceServiceAdapter testTestbed2NestedStruct3InterfaceServiceAdapter(*testTestbed2NestedStruct3Interface, registry);
    std::unique_ptr<TbEnum::IEnumInterface> testTbEnumEnumInterface = std::make_unique<TbEnum::EnumInterface>();
    TbEnum::olink::EnumInterfaceServiceAdapter testTbEnumEnumInterfaceServiceAdapter(*testTbEnumEnumInterface, registry);
    std::unique_ptr<TbSame1::ISameStruct1Interface> testTbSame1SameStruct1Interface = std::make_unique<TbSame1::SameStruct1Interface>();
    TbSame1::olink::SameStruct1InterfaceServiceAdapter testTbSame1SameStruct1InterfaceServiceAdapter(*testTbSame1SameStruct1Interface, registry);
    std::unique_ptr<TbSame1::ISameStruct2Interface> testTbSame1SameStruct2Interface = std::make_unique<TbSame1::SameStruct2Interface>();
    TbSame1::olink::SameStruct2InterfaceServiceAdapter testTbSame1SameStruct2InterfaceServiceAdapter(*testTbSame1SameStruct2Interface, registry);
    std::unique_ptr<TbSame1::ISameEnum1Interface> testTbSame1SameEnum1Interface = std::make_unique<TbSame1::SameEnum1Interface>();
    TbSame1::olink::SameEnum1InterfaceServiceAdapter testTbSame1SameEnum1InterfaceServiceAdapter(*testTbSame1SameEnum1Interface, registry);
    std::unique_ptr<TbSame1::ISameEnum2Interface> testTbSame1SameEnum2Interface = std::make_unique<TbSame1::SameEnum2Interface>();
    TbSame1::olink::SameEnum2InterfaceServiceAdapter testTbSame1SameEnum2InterfaceServiceAdapter(*testTbSame1SameEnum2Interface, registry);
    std::unique_ptr<TbSame2::ISameStruct1Interface> testTbSame2SameStruct1Interface = std::make_unique<TbSame2::SameStruct1Interface>();
    TbSame2::olink::SameStruct1InterfaceServiceAdapter testTbSame2SameStruct1InterfaceServiceAdapter(*testTbSame2SameStruct1Interface, registry);
    std::unique_ptr<TbSame2::ISameStruct2Interface> testTbSame2SameStruct2Interface = std::make_unique<TbSame2::SameStruct2Interface>();
    TbSame2::olink::SameStruct2InterfaceServiceAdapter testTbSame2SameStruct2InterfaceServiceAdapter(*testTbSame2SameStruct2Interface, registry);
    std::unique_ptr<TbSame2::ISameEnum1Interface> testTbSame2SameEnum1Interface = std::make_unique<TbSame2::SameEnum1Interface>();
    TbSame2::olink::SameEnum1InterfaceServiceAdapter testTbSame2SameEnum1InterfaceServiceAdapter(*testTbSame2SameEnum1Interface, registry);
    std::unique_ptr<TbSame2::ISameEnum2Interface> testTbSame2SameEnum2Interface = std::make_unique<TbSame2::SameEnum2Interface>();
    TbSame2::olink::SameEnum2InterfaceServiceAdapter testTbSame2SameEnum2InterfaceServiceAdapter(*testTbSame2SameEnum2Interface, registry);
    std::unique_ptr<TbSimple::ISimpleInterface> testTbSimpleSimpleInterface = std::make_unique<TbSimple::SimpleInterface>();
    TbSimple::olink::SimpleInterfaceServiceAdapter testTbSimpleSimpleInterfaceServiceAdapter(*testTbSimpleSimpleInterface, registry);
    std::unique_ptr<TbSimple::ISimpleArrayInterface> testTbSimpleSimpleArrayInterface = std::make_unique<TbSimple::SimpleArrayInterface>();
    TbSimple::olink::SimpleArrayInterfaceServiceAdapter testTbSimpleSimpleArrayInterfaceServiceAdapter(*testTbSimpleSimpleArrayInterface, registry);
    std::unique_ptr<Testbed1::IStructInterface> testTestbed1StructInterface = std::make_unique<Testbed1::StructInterface>();
    Testbed1::olink::StructInterfaceServiceAdapter testTestbed1StructInterfaceServiceAdapter(*testTestbed1StructInterface, registry);
    std::unique_ptr<Testbed1::IStructArrayInterface> testTestbed1StructArrayInterface = std::make_unique<Testbed1::StructArrayInterface>();
    Testbed1::olink::StructArrayInterfaceServiceAdapter testTestbed1StructArrayInterfaceServiceAdapter(*testTestbed1StructArrayInterface, registry);

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

    return 0;
}
