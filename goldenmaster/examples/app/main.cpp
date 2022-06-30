
#include "testbed2_manyparaminterface.h"
#include "generated/monitor/testbed2_manyparaminterface.trace.h"
#include "testbed2_nestedstruct1interface.h"
#include "generated/monitor/testbed2_nestedstruct1interface.trace.h"
#include "testbed2_nestedstruct2interface.h"
#include "generated/monitor/testbed2_nestedstruct2interface.trace.h"
#include "testbed2_nestedstruct3interface.h"
#include "generated/monitor/testbed2_nestedstruct3interface.trace.h"
#include "tb_enum_enuminterface.h"
#include "generated/monitor/tb_enum_enuminterface.trace.h"
#include "tb_same1_samestruct1interface.h"
#include "generated/monitor/tb_same1_samestruct1interface.trace.h"
#include "tb_same1_samestruct2interface.h"
#include "generated/monitor/tb_same1_samestruct2interface.trace.h"
#include "tb_same1_sameenum1interface.h"
#include "generated/monitor/tb_same1_sameenum1interface.trace.h"
#include "tb_same1_sameenum2interface.h"
#include "generated/monitor/tb_same1_sameenum2interface.trace.h"
#include "tb_same2_samestruct1interface.h"
#include "generated/monitor/tb_same2_samestruct1interface.trace.h"
#include "tb_same2_samestruct2interface.h"
#include "generated/monitor/tb_same2_samestruct2interface.trace.h"
#include "tb_same2_sameenum1interface.h"
#include "generated/monitor/tb_same2_sameenum1interface.trace.h"
#include "tb_same2_sameenum2interface.h"
#include "generated/monitor/tb_same2_sameenum2interface.trace.h"
#include "tb_simple_simpleinterface.h"
#include "generated/monitor/tb_simple_simpleinterface.trace.h"
#include "tb_simple_simplearrayinterface.h"
#include "generated/monitor/tb_simple_simplearrayinterface.trace.h"
#include "testbed1_structinterface.h"
#include "generated/monitor/testbed1_structinterface.trace.h"
#include "testbed1_structarrayinterface.h"
#include "generated/monitor/testbed1_structarrayinterface.trace.h"
#include "apigear/tracer/tracer.h"

using namespace Test;

int main(){
    ApiGear::PocoImpl::Tracer tracer;
    tracer.connect("http://localhost:5555", "testExampleApp");
    std::unique_ptr<Testbed2::IManyParamInterface> testTestbed2ManyParamInterface = std::make_unique<Testbed2::ManyParamInterface>();
    std::unique_ptr<Testbed2::IManyParamInterfaceDecorator> testTestbed2ManyParamInterfaceTracerDecorator(Testbed2::ManyParamInterfaceTracerDecorator::connect(testTestbed2ManyParamInterface.get(), &tracer));
    std::unique_ptr<Testbed2::INestedStruct1Interface> testTestbed2NestedStruct1Interface = std::make_unique<Testbed2::NestedStruct1Interface>();
    std::unique_ptr<Testbed2::INestedStruct1InterfaceDecorator> testTestbed2NestedStruct1InterfaceTracerDecorator(Testbed2::NestedStruct1InterfaceTracerDecorator::connect(testTestbed2NestedStruct1Interface.get(), &tracer));
    std::unique_ptr<Testbed2::INestedStruct2Interface> testTestbed2NestedStruct2Interface = std::make_unique<Testbed2::NestedStruct2Interface>();
    std::unique_ptr<Testbed2::INestedStruct2InterfaceDecorator> testTestbed2NestedStruct2InterfaceTracerDecorator(Testbed2::NestedStruct2InterfaceTracerDecorator::connect(testTestbed2NestedStruct2Interface.get(), &tracer));
    std::unique_ptr<Testbed2::INestedStruct3Interface> testTestbed2NestedStruct3Interface = std::make_unique<Testbed2::NestedStruct3Interface>();
    std::unique_ptr<Testbed2::INestedStruct3InterfaceDecorator> testTestbed2NestedStruct3InterfaceTracerDecorator(Testbed2::NestedStruct3InterfaceTracerDecorator::connect(testTestbed2NestedStruct3Interface.get(), &tracer));
    std::unique_ptr<TbEnum::IEnumInterface> testTbEnumEnumInterface = std::make_unique<TbEnum::EnumInterface>();
    std::unique_ptr<TbEnum::IEnumInterfaceDecorator> testTbEnumEnumInterfaceTracerDecorator(TbEnum::EnumInterfaceTracerDecorator::connect(testTbEnumEnumInterface.get(), &tracer));
    std::unique_ptr<TbSame1::ISameStruct1Interface> testTbSame1SameStruct1Interface = std::make_unique<TbSame1::SameStruct1Interface>();
    std::unique_ptr<TbSame1::ISameStruct1InterfaceDecorator> testTbSame1SameStruct1InterfaceTracerDecorator(TbSame1::SameStruct1InterfaceTracerDecorator::connect(testTbSame1SameStruct1Interface.get(), &tracer));
    std::unique_ptr<TbSame1::ISameStruct2Interface> testTbSame1SameStruct2Interface = std::make_unique<TbSame1::SameStruct2Interface>();
    std::unique_ptr<TbSame1::ISameStruct2InterfaceDecorator> testTbSame1SameStruct2InterfaceTracerDecorator(TbSame1::SameStruct2InterfaceTracerDecorator::connect(testTbSame1SameStruct2Interface.get(), &tracer));
    std::unique_ptr<TbSame1::ISameEnum1Interface> testTbSame1SameEnum1Interface = std::make_unique<TbSame1::SameEnum1Interface>();
    std::unique_ptr<TbSame1::ISameEnum1InterfaceDecorator> testTbSame1SameEnum1InterfaceTracerDecorator(TbSame1::SameEnum1InterfaceTracerDecorator::connect(testTbSame1SameEnum1Interface.get(), &tracer));
    std::unique_ptr<TbSame1::ISameEnum2Interface> testTbSame1SameEnum2Interface = std::make_unique<TbSame1::SameEnum2Interface>();
    std::unique_ptr<TbSame1::ISameEnum2InterfaceDecorator> testTbSame1SameEnum2InterfaceTracerDecorator(TbSame1::SameEnum2InterfaceTracerDecorator::connect(testTbSame1SameEnum2Interface.get(), &tracer));
    std::unique_ptr<TbSame2::ISameStruct1Interface> testTbSame2SameStruct1Interface = std::make_unique<TbSame2::SameStruct1Interface>();
    std::unique_ptr<TbSame2::ISameStruct1InterfaceDecorator> testTbSame2SameStruct1InterfaceTracerDecorator(TbSame2::SameStruct1InterfaceTracerDecorator::connect(testTbSame2SameStruct1Interface.get(), &tracer));
    std::unique_ptr<TbSame2::ISameStruct2Interface> testTbSame2SameStruct2Interface = std::make_unique<TbSame2::SameStruct2Interface>();
    std::unique_ptr<TbSame2::ISameStruct2InterfaceDecorator> testTbSame2SameStruct2InterfaceTracerDecorator(TbSame2::SameStruct2InterfaceTracerDecorator::connect(testTbSame2SameStruct2Interface.get(), &tracer));
    std::unique_ptr<TbSame2::ISameEnum1Interface> testTbSame2SameEnum1Interface = std::make_unique<TbSame2::SameEnum1Interface>();
    std::unique_ptr<TbSame2::ISameEnum1InterfaceDecorator> testTbSame2SameEnum1InterfaceTracerDecorator(TbSame2::SameEnum1InterfaceTracerDecorator::connect(testTbSame2SameEnum1Interface.get(), &tracer));
    std::unique_ptr<TbSame2::ISameEnum2Interface> testTbSame2SameEnum2Interface = std::make_unique<TbSame2::SameEnum2Interface>();
    std::unique_ptr<TbSame2::ISameEnum2InterfaceDecorator> testTbSame2SameEnum2InterfaceTracerDecorator(TbSame2::SameEnum2InterfaceTracerDecorator::connect(testTbSame2SameEnum2Interface.get(), &tracer));
    std::unique_ptr<TbSimple::ISimpleInterface> testTbSimpleSimpleInterface = std::make_unique<TbSimple::SimpleInterface>();
    std::unique_ptr<TbSimple::ISimpleInterfaceDecorator> testTbSimpleSimpleInterfaceTracerDecorator(TbSimple::SimpleInterfaceTracerDecorator::connect(testTbSimpleSimpleInterface.get(), &tracer));
    std::unique_ptr<TbSimple::ISimpleArrayInterface> testTbSimpleSimpleArrayInterface = std::make_unique<TbSimple::SimpleArrayInterface>();
    std::unique_ptr<TbSimple::ISimpleArrayInterfaceDecorator> testTbSimpleSimpleArrayInterfaceTracerDecorator(TbSimple::SimpleArrayInterfaceTracerDecorator::connect(testTbSimpleSimpleArrayInterface.get(), &tracer));
    std::unique_ptr<Testbed1::IStructInterface> testTestbed1StructInterface = std::make_unique<Testbed1::StructInterface>();
    std::unique_ptr<Testbed1::IStructInterfaceDecorator> testTestbed1StructInterfaceTracerDecorator(Testbed1::StructInterfaceTracerDecorator::connect(testTestbed1StructInterface.get(), &tracer));
    std::unique_ptr<Testbed1::IStructArrayInterface> testTestbed1StructArrayInterface = std::make_unique<Testbed1::StructArrayInterface>();
    std::unique_ptr<Testbed1::IStructArrayInterfaceDecorator> testTestbed1StructArrayInterfaceTracerDecorator(Testbed1::StructArrayInterfaceTracerDecorator::connect(testTestbed1StructArrayInterface.get(), &tracer));

    return 0;
}
