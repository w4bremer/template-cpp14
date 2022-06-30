#include <iostream>
#include "testbed2_manyparaminterface.h"
#include "generated/olink/testbed2_manyparaminterfaceadapter.h"
#include "testbed2_nestedstruct1interface.h"
#include "generated/olink/testbed2_nestedstruct1interfaceadapter.h"
#include "testbed2_nestedstruct2interface.h"
#include "generated/olink/testbed2_nestedstruct2interfaceadapter.h"
#include "testbed2_nestedstruct3interface.h"
#include "generated/olink/testbed2_nestedstruct3interfaceadapter.h"
#include "tb_enum_enuminterface.h"
#include "generated/olink/tb_enum_enuminterfaceadapter.h"
#include "tb_same1_samestruct1interface.h"
#include "generated/olink/tb_same1_samestruct1interfaceadapter.h"
#include "tb_same1_samestruct2interface.h"
#include "generated/olink/tb_same1_samestruct2interfaceadapter.h"
#include "tb_same1_sameenum1interface.h"
#include "generated/olink/tb_same1_sameenum1interfaceadapter.h"
#include "tb_same1_sameenum2interface.h"
#include "generated/olink/tb_same1_sameenum2interfaceadapter.h"
#include "tb_same2_samestruct1interface.h"
#include "generated/olink/tb_same2_samestruct1interfaceadapter.h"
#include "tb_same2_samestruct2interface.h"
#include "generated/olink/tb_same2_samestruct2interfaceadapter.h"
#include "tb_same2_sameenum1interface.h"
#include "generated/olink/tb_same2_sameenum1interfaceadapter.h"
#include "tb_same2_sameenum2interface.h"
#include "generated/olink/tb_same2_sameenum2interfaceadapter.h"
#include "tb_simple_simpleinterface.h"
#include "generated/olink/tb_simple_simpleinterfaceadapter.h"
#include "tb_simple_simplearrayinterface.h"
#include "generated/olink/tb_simple_simplearrayinterfaceadapter.h"
#include "testbed1_structinterface.h"
#include "generated/olink/testbed1_structinterfaceadapter.h"
#include "testbed1_structarrayinterface.h"
#include "generated/olink/testbed1_structarrayinterfaceadapter.h"
#include "apigear/olink/olinkhost.h"

using namespace Test;

int main(){
    ApiGear::ObjectLink::RemoteRegistry registry;
    ApiGear::PocoImpl::OLinkHost testserver(registry);
    std::unique_ptr<Testbed2::IManyParamInterface> testTestbed2ManyParamInterface = std::make_unique<Testbed2::ManyParamInterface>();
    Testbed2::OLinkManyParamInterfaceAdapter testTestbed2ManyParamInterfaceAdapter(testTestbed2ManyParamInterface.get(), registry);
    std::unique_ptr<Testbed2::INestedStruct1Interface> testTestbed2NestedStruct1Interface = std::make_unique<Testbed2::NestedStruct1Interface>();
    Testbed2::OLinkNestedStruct1InterfaceAdapter testTestbed2NestedStruct1InterfaceAdapter(testTestbed2NestedStruct1Interface.get(), registry);
    std::unique_ptr<Testbed2::INestedStruct2Interface> testTestbed2NestedStruct2Interface = std::make_unique<Testbed2::NestedStruct2Interface>();
    Testbed2::OLinkNestedStruct2InterfaceAdapter testTestbed2NestedStruct2InterfaceAdapter(testTestbed2NestedStruct2Interface.get(), registry);
    std::unique_ptr<Testbed2::INestedStruct3Interface> testTestbed2NestedStruct3Interface = std::make_unique<Testbed2::NestedStruct3Interface>();
    Testbed2::OLinkNestedStruct3InterfaceAdapter testTestbed2NestedStruct3InterfaceAdapter(testTestbed2NestedStruct3Interface.get(), registry);
    std::unique_ptr<TbEnum::IEnumInterface> testTbEnumEnumInterface = std::make_unique<TbEnum::EnumInterface>();
    TbEnum::OLinkEnumInterfaceAdapter testTbEnumEnumInterfaceAdapter(testTbEnumEnumInterface.get(), registry);
    std::unique_ptr<TbSame1::ISameStruct1Interface> testTbSame1SameStruct1Interface = std::make_unique<TbSame1::SameStruct1Interface>();
    TbSame1::OLinkSameStruct1InterfaceAdapter testTbSame1SameStruct1InterfaceAdapter(testTbSame1SameStruct1Interface.get(), registry);
    std::unique_ptr<TbSame1::ISameStruct2Interface> testTbSame1SameStruct2Interface = std::make_unique<TbSame1::SameStruct2Interface>();
    TbSame1::OLinkSameStruct2InterfaceAdapter testTbSame1SameStruct2InterfaceAdapter(testTbSame1SameStruct2Interface.get(), registry);
    std::unique_ptr<TbSame1::ISameEnum1Interface> testTbSame1SameEnum1Interface = std::make_unique<TbSame1::SameEnum1Interface>();
    TbSame1::OLinkSameEnum1InterfaceAdapter testTbSame1SameEnum1InterfaceAdapter(testTbSame1SameEnum1Interface.get(), registry);
    std::unique_ptr<TbSame1::ISameEnum2Interface> testTbSame1SameEnum2Interface = std::make_unique<TbSame1::SameEnum2Interface>();
    TbSame1::OLinkSameEnum2InterfaceAdapter testTbSame1SameEnum2InterfaceAdapter(testTbSame1SameEnum2Interface.get(), registry);
    std::unique_ptr<TbSame2::ISameStruct1Interface> testTbSame2SameStruct1Interface = std::make_unique<TbSame2::SameStruct1Interface>();
    TbSame2::OLinkSameStruct1InterfaceAdapter testTbSame2SameStruct1InterfaceAdapter(testTbSame2SameStruct1Interface.get(), registry);
    std::unique_ptr<TbSame2::ISameStruct2Interface> testTbSame2SameStruct2Interface = std::make_unique<TbSame2::SameStruct2Interface>();
    TbSame2::OLinkSameStruct2InterfaceAdapter testTbSame2SameStruct2InterfaceAdapter(testTbSame2SameStruct2Interface.get(), registry);
    std::unique_ptr<TbSame2::ISameEnum1Interface> testTbSame2SameEnum1Interface = std::make_unique<TbSame2::SameEnum1Interface>();
    TbSame2::OLinkSameEnum1InterfaceAdapter testTbSame2SameEnum1InterfaceAdapter(testTbSame2SameEnum1Interface.get(), registry);
    std::unique_ptr<TbSame2::ISameEnum2Interface> testTbSame2SameEnum2Interface = std::make_unique<TbSame2::SameEnum2Interface>();
    TbSame2::OLinkSameEnum2InterfaceAdapter testTbSame2SameEnum2InterfaceAdapter(testTbSame2SameEnum2Interface.get(), registry);
    std::unique_ptr<TbSimple::ISimpleInterface> testTbSimpleSimpleInterface = std::make_unique<TbSimple::SimpleInterface>();
    TbSimple::OLinkSimpleInterfaceAdapter testTbSimpleSimpleInterfaceAdapter(testTbSimpleSimpleInterface.get(), registry);
    std::unique_ptr<TbSimple::ISimpleArrayInterface> testTbSimpleSimpleArrayInterface = std::make_unique<TbSimple::SimpleArrayInterface>();
    TbSimple::OLinkSimpleArrayInterfaceAdapter testTbSimpleSimpleArrayInterfaceAdapter(testTbSimpleSimpleArrayInterface.get(), registry);
    std::unique_ptr<Testbed1::IStructInterface> testTestbed1StructInterface = std::make_unique<Testbed1::StructInterface>();
    Testbed1::OLinkStructInterfaceAdapter testTestbed1StructInterfaceAdapter(testTestbed1StructInterface.get(), registry);
    std::unique_ptr<Testbed1::IStructArrayInterface> testTestbed1StructArrayInterface = std::make_unique<Testbed1::StructArrayInterface>();
    Testbed1::OLinkStructArrayInterfaceAdapter testTestbed1StructArrayInterfaceAdapter(testTestbed1StructArrayInterface.get(), registry);

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
