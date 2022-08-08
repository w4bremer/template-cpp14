
#include "testbed2/implementation/manyparaminterface.h"
#include "testbed2/generated/monitor/manyparaminterface.trace.h"
#include "testbed2/implementation/nestedstruct1interface.h"
#include "testbed2/generated/monitor/nestedstruct1interface.trace.h"
#include "testbed2/implementation/nestedstruct2interface.h"
#include "testbed2/generated/monitor/nestedstruct2interface.trace.h"
#include "testbed2/implementation/nestedstruct3interface.h"
#include "testbed2/generated/monitor/nestedstruct3interface.trace.h"
#include "tb_enum/implementation/enuminterface.h"
#include "tb_enum/generated/monitor/enuminterface.trace.h"
#include "tb_same1/implementation/samestruct1interface.h"
#include "tb_same1/generated/monitor/samestruct1interface.trace.h"
#include "tb_same1/implementation/samestruct2interface.h"
#include "tb_same1/generated/monitor/samestruct2interface.trace.h"
#include "tb_same1/implementation/sameenum1interface.h"
#include "tb_same1/generated/monitor/sameenum1interface.trace.h"
#include "tb_same1/implementation/sameenum2interface.h"
#include "tb_same1/generated/monitor/sameenum2interface.trace.h"
#include "tb_same2/implementation/samestruct1interface.h"
#include "tb_same2/generated/monitor/samestruct1interface.trace.h"
#include "tb_same2/implementation/samestruct2interface.h"
#include "tb_same2/generated/monitor/samestruct2interface.trace.h"
#include "tb_same2/implementation/sameenum1interface.h"
#include "tb_same2/generated/monitor/sameenum1interface.trace.h"
#include "tb_same2/implementation/sameenum2interface.h"
#include "tb_same2/generated/monitor/sameenum2interface.trace.h"
#include "tb_simple/implementation/simpleinterface.h"
#include "tb_simple/generated/monitor/simpleinterface.trace.h"
#include "tb_simple/implementation/simplearrayinterface.h"
#include "tb_simple/generated/monitor/simplearrayinterface.trace.h"
#include "testbed1/implementation/structinterface.h"
#include "testbed1/generated/monitor/structinterface.trace.h"
#include "testbed1/implementation/structarrayinterface.h"
#include "testbed1/generated/monitor/structarrayinterface.trace.h"
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
