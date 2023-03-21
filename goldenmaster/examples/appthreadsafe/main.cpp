
#include "testbed2/implementation/manyparaminterface.h"
#include "testbed2/generated/core/manyparaminterface.threadsafedecorator.h"
#include "testbed2/implementation/nestedstruct1interface.h"
#include "testbed2/generated/core/nestedstruct1interface.threadsafedecorator.h"
#include "testbed2/implementation/nestedstruct2interface.h"
#include "testbed2/generated/core/nestedstruct2interface.threadsafedecorator.h"
#include "testbed2/implementation/nestedstruct3interface.h"
#include "testbed2/generated/core/nestedstruct3interface.threadsafedecorator.h"
#include "tb_enum/implementation/enuminterface.h"
#include "tb_enum/generated/core/enuminterface.threadsafedecorator.h"
#include "tb_same1/implementation/samestruct1interface.h"
#include "tb_same1/generated/core/samestruct1interface.threadsafedecorator.h"
#include "tb_same1/implementation/samestruct2interface.h"
#include "tb_same1/generated/core/samestruct2interface.threadsafedecorator.h"
#include "tb_same1/implementation/sameenum1interface.h"
#include "tb_same1/generated/core/sameenum1interface.threadsafedecorator.h"
#include "tb_same1/implementation/sameenum2interface.h"
#include "tb_same1/generated/core/sameenum2interface.threadsafedecorator.h"
#include "tb_same2/implementation/samestruct1interface.h"
#include "tb_same2/generated/core/samestruct1interface.threadsafedecorator.h"
#include "tb_same2/implementation/samestruct2interface.h"
#include "tb_same2/generated/core/samestruct2interface.threadsafedecorator.h"
#include "tb_same2/implementation/sameenum1interface.h"
#include "tb_same2/generated/core/sameenum1interface.threadsafedecorator.h"
#include "tb_same2/implementation/sameenum2interface.h"
#include "tb_same2/generated/core/sameenum2interface.threadsafedecorator.h"
#include "tb_simple/implementation/simpleinterface.h"
#include "tb_simple/generated/core/simpleinterface.threadsafedecorator.h"
#include "tb_simple/implementation/simplearrayinterface.h"
#include "tb_simple/generated/core/simplearrayinterface.threadsafedecorator.h"
#include "tb_simple/implementation/nopropertiesinterface.h"
#include "tb_simple/generated/core/nopropertiesinterface.threadsafedecorator.h"
#include "tb_simple/implementation/nooperationsinterface.h"
#include "tb_simple/generated/core/nooperationsinterface.threadsafedecorator.h"
#include "tb_simple/implementation/nosignalsinterface.h"
#include "tb_simple/generated/core/nosignalsinterface.threadsafedecorator.h"
#include "testbed1/implementation/structinterface.h"
#include "testbed1/generated/core/structinterface.threadsafedecorator.h"
#include "testbed1/implementation/structarrayinterface.h"
#include "testbed1/generated/core/structarrayinterface.threadsafedecorator.h"

void testTestbed2ManyParamInterface()
{
    using namespace Test::Testbed2;

    std::unique_ptr<IManyParamInterface> testManyParamInterface = std::make_unique<ManyParamInterfaceThreadSafeDecorator>(std::make_shared<ManyParamInterface>());

    // Thread safe access
    auto prop1 = testManyParamInterface->getProp1();
    testManyParamInterface->setProp1(0);
    auto prop2 = testManyParamInterface->getProp2();
    testManyParamInterface->setProp2(0);
    auto prop3 = testManyParamInterface->getProp3();
    testManyParamInterface->setProp3(0);
    auto prop4 = testManyParamInterface->getProp4();
    testManyParamInterface->setProp4(0);
}

void testTestbed2NestedStruct1Interface()
{
    using namespace Test::Testbed2;

    std::unique_ptr<INestedStruct1Interface> testNestedStruct1Interface = std::make_unique<NestedStruct1InterfaceThreadSafeDecorator>(std::make_shared<NestedStruct1Interface>());

    // Thread safe access
    auto prop1 = testNestedStruct1Interface->getProp1();
    testNestedStruct1Interface->setProp1(NestedStruct1());
}

void testTestbed2NestedStruct2Interface()
{
    using namespace Test::Testbed2;

    std::unique_ptr<INestedStruct2Interface> testNestedStruct2Interface = std::make_unique<NestedStruct2InterfaceThreadSafeDecorator>(std::make_shared<NestedStruct2Interface>());

    // Thread safe access
    auto prop1 = testNestedStruct2Interface->getProp1();
    testNestedStruct2Interface->setProp1(NestedStruct1());
    auto prop2 = testNestedStruct2Interface->getProp2();
    testNestedStruct2Interface->setProp2(NestedStruct2());
}

void testTestbed2NestedStruct3Interface()
{
    using namespace Test::Testbed2;

    std::unique_ptr<INestedStruct3Interface> testNestedStruct3Interface = std::make_unique<NestedStruct3InterfaceThreadSafeDecorator>(std::make_shared<NestedStruct3Interface>());

    // Thread safe access
    auto prop1 = testNestedStruct3Interface->getProp1();
    testNestedStruct3Interface->setProp1(NestedStruct1());
    auto prop2 = testNestedStruct3Interface->getProp2();
    testNestedStruct3Interface->setProp2(NestedStruct2());
    auto prop3 = testNestedStruct3Interface->getProp3();
    testNestedStruct3Interface->setProp3(NestedStruct3());
}

void testTbEnumEnumInterface()
{
    using namespace Test::TbEnum;

    std::unique_ptr<IEnumInterface> testEnumInterface = std::make_unique<EnumInterfaceThreadSafeDecorator>(std::make_shared<EnumInterface>());

    // Thread safe access
    auto prop0 = testEnumInterface->getProp0();
    testEnumInterface->setProp0(Enum0Enum::value0);
    auto prop1 = testEnumInterface->getProp1();
    testEnumInterface->setProp1(Enum1Enum::value1);
    auto prop2 = testEnumInterface->getProp2();
    testEnumInterface->setProp2(Enum2Enum::value2);
    auto prop3 = testEnumInterface->getProp3();
    testEnumInterface->setProp3(Enum3Enum::value3);
}

void testTbSame1SameStruct1Interface()
{
    using namespace Test::TbSame1;

    std::unique_ptr<ISameStruct1Interface> testSameStruct1Interface = std::make_unique<SameStruct1InterfaceThreadSafeDecorator>(std::make_shared<SameStruct1Interface>());

    // Thread safe access
    auto prop1 = testSameStruct1Interface->getProp1();
    testSameStruct1Interface->setProp1(Struct1());
}

void testTbSame1SameStruct2Interface()
{
    using namespace Test::TbSame1;

    std::unique_ptr<ISameStruct2Interface> testSameStruct2Interface = std::make_unique<SameStruct2InterfaceThreadSafeDecorator>(std::make_shared<SameStruct2Interface>());

    // Thread safe access
    auto prop1 = testSameStruct2Interface->getProp1();
    testSameStruct2Interface->setProp1(Struct2());
    auto prop2 = testSameStruct2Interface->getProp2();
    testSameStruct2Interface->setProp2(Struct2());
}

void testTbSame1SameEnum1Interface()
{
    using namespace Test::TbSame1;

    std::unique_ptr<ISameEnum1Interface> testSameEnum1Interface = std::make_unique<SameEnum1InterfaceThreadSafeDecorator>(std::make_shared<SameEnum1Interface>());

    // Thread safe access
    auto prop1 = testSameEnum1Interface->getProp1();
    testSameEnum1Interface->setProp1(Enum1Enum::value1);
}

void testTbSame1SameEnum2Interface()
{
    using namespace Test::TbSame1;

    std::unique_ptr<ISameEnum2Interface> testSameEnum2Interface = std::make_unique<SameEnum2InterfaceThreadSafeDecorator>(std::make_shared<SameEnum2Interface>());

    // Thread safe access
    auto prop1 = testSameEnum2Interface->getProp1();
    testSameEnum2Interface->setProp1(Enum1Enum::value1);
    auto prop2 = testSameEnum2Interface->getProp2();
    testSameEnum2Interface->setProp2(Enum2Enum::value1);
}

void testTbSame2SameStruct1Interface()
{
    using namespace Test::TbSame2;

    std::unique_ptr<ISameStruct1Interface> testSameStruct1Interface = std::make_unique<SameStruct1InterfaceThreadSafeDecorator>(std::make_shared<SameStruct1Interface>());

    // Thread safe access
    auto prop1 = testSameStruct1Interface->getProp1();
    testSameStruct1Interface->setProp1(Struct1());
}

void testTbSame2SameStruct2Interface()
{
    using namespace Test::TbSame2;

    std::unique_ptr<ISameStruct2Interface> testSameStruct2Interface = std::make_unique<SameStruct2InterfaceThreadSafeDecorator>(std::make_shared<SameStruct2Interface>());

    // Thread safe access
    auto prop1 = testSameStruct2Interface->getProp1();
    testSameStruct2Interface->setProp1(Struct2());
    auto prop2 = testSameStruct2Interface->getProp2();
    testSameStruct2Interface->setProp2(Struct2());
}

void testTbSame2SameEnum1Interface()
{
    using namespace Test::TbSame2;

    std::unique_ptr<ISameEnum1Interface> testSameEnum1Interface = std::make_unique<SameEnum1InterfaceThreadSafeDecorator>(std::make_shared<SameEnum1Interface>());

    // Thread safe access
    auto prop1 = testSameEnum1Interface->getProp1();
    testSameEnum1Interface->setProp1(Enum1Enum::value1);
}

void testTbSame2SameEnum2Interface()
{
    using namespace Test::TbSame2;

    std::unique_ptr<ISameEnum2Interface> testSameEnum2Interface = std::make_unique<SameEnum2InterfaceThreadSafeDecorator>(std::make_shared<SameEnum2Interface>());

    // Thread safe access
    auto prop1 = testSameEnum2Interface->getProp1();
    testSameEnum2Interface->setProp1(Enum1Enum::value1);
    auto prop2 = testSameEnum2Interface->getProp2();
    testSameEnum2Interface->setProp2(Enum2Enum::value1);
}

void testTbSimpleSimpleInterface()
{
    using namespace Test::TbSimple;

    std::unique_ptr<ISimpleInterface> testSimpleInterface = std::make_unique<SimpleInterfaceThreadSafeDecorator>(std::make_shared<SimpleInterface>());

    // Thread safe access
    auto propBool = testSimpleInterface->getPropBool();
    testSimpleInterface->setPropBool(false);
    auto propInt = testSimpleInterface->getPropInt();
    testSimpleInterface->setPropInt(0);
    auto propInt32 = testSimpleInterface->getPropInt32();
    testSimpleInterface->setPropInt32(0);
    auto propInt64 = testSimpleInterface->getPropInt64();
    testSimpleInterface->setPropInt64(0LL);
    auto propFloat = testSimpleInterface->getPropFloat();
    testSimpleInterface->setPropFloat(0.0f);
    auto propFloat32 = testSimpleInterface->getPropFloat32();
    testSimpleInterface->setPropFloat32(0.0f);
    auto propFloat64 = testSimpleInterface->getPropFloat64();
    testSimpleInterface->setPropFloat64(0.0);
    auto propString = testSimpleInterface->getPropString();
    testSimpleInterface->setPropString(std::string());
}

void testTbSimpleSimpleArrayInterface()
{
    using namespace Test::TbSimple;

    std::unique_ptr<ISimpleArrayInterface> testSimpleArrayInterface = std::make_unique<SimpleArrayInterfaceThreadSafeDecorator>(std::make_shared<SimpleArrayInterface>());

    // Thread safe access
    auto propBool = testSimpleArrayInterface->getPropBool();
    testSimpleArrayInterface->setPropBool(std::list<bool>());
    auto propInt = testSimpleArrayInterface->getPropInt();
    testSimpleArrayInterface->setPropInt(std::list<int>());
    auto propInt32 = testSimpleArrayInterface->getPropInt32();
    testSimpleArrayInterface->setPropInt32(std::list<int32_t>());
    auto propInt64 = testSimpleArrayInterface->getPropInt64();
    testSimpleArrayInterface->setPropInt64(std::list<int64_t>());
    auto propFloat = testSimpleArrayInterface->getPropFloat();
    testSimpleArrayInterface->setPropFloat(std::list<float>());
    auto propFloat32 = testSimpleArrayInterface->getPropFloat32();
    testSimpleArrayInterface->setPropFloat32(std::list<float>());
    auto propFloat64 = testSimpleArrayInterface->getPropFloat64();
    testSimpleArrayInterface->setPropFloat64(std::list<double>());
    auto propString = testSimpleArrayInterface->getPropString();
    testSimpleArrayInterface->setPropString(std::list<std::string>());
}

void testTbSimpleNoPropertiesInterface()
{
    using namespace Test::TbSimple;

    std::unique_ptr<INoPropertiesInterface> testNoPropertiesInterface = std::make_unique<NoPropertiesInterfaceThreadSafeDecorator>(std::make_shared<NoPropertiesInterface>());

    // Thread safe access
}

void testTbSimpleNoOperationsInterface()
{
    using namespace Test::TbSimple;

    std::unique_ptr<INoOperationsInterface> testNoOperationsInterface = std::make_unique<NoOperationsInterfaceThreadSafeDecorator>(std::make_shared<NoOperationsInterface>());

    // Thread safe access
    auto propBool = testNoOperationsInterface->getPropBool();
    testNoOperationsInterface->setPropBool(false);
    auto propInt = testNoOperationsInterface->getPropInt();
    testNoOperationsInterface->setPropInt(0);
}

void testTbSimpleNoSignalsInterface()
{
    using namespace Test::TbSimple;

    std::unique_ptr<INoSignalsInterface> testNoSignalsInterface = std::make_unique<NoSignalsInterfaceThreadSafeDecorator>(std::make_shared<NoSignalsInterface>());

    // Thread safe access
    auto propBool = testNoSignalsInterface->getPropBool();
    testNoSignalsInterface->setPropBool(false);
    auto propInt = testNoSignalsInterface->getPropInt();
    testNoSignalsInterface->setPropInt(0);
}

void testTestbed1StructInterface()
{
    using namespace Test::Testbed1;

    std::unique_ptr<IStructInterface> testStructInterface = std::make_unique<StructInterfaceThreadSafeDecorator>(std::make_shared<StructInterface>());

    // Thread safe access
    auto propBool = testStructInterface->getPropBool();
    testStructInterface->setPropBool(StructBool());
    auto propInt = testStructInterface->getPropInt();
    testStructInterface->setPropInt(StructInt());
    auto propFloat = testStructInterface->getPropFloat();
    testStructInterface->setPropFloat(StructFloat());
    auto propString = testStructInterface->getPropString();
    testStructInterface->setPropString(StructString());
}

void testTestbed1StructArrayInterface()
{
    using namespace Test::Testbed1;

    std::unique_ptr<IStructArrayInterface> testStructArrayInterface = std::make_unique<StructArrayInterfaceThreadSafeDecorator>(std::make_shared<StructArrayInterface>());

    // Thread safe access
    auto propBool = testStructArrayInterface->getPropBool();
    testStructArrayInterface->setPropBool(std::list<StructBool>());
    auto propInt = testStructArrayInterface->getPropInt();
    testStructArrayInterface->setPropInt(std::list<StructInt>());
    auto propFloat = testStructArrayInterface->getPropFloat();
    testStructArrayInterface->setPropFloat(std::list<StructFloat>());
    auto propString = testStructArrayInterface->getPropString();
    testStructArrayInterface->setPropString(std::list<StructString>());
}


int main(){
    testTestbed2ManyParamInterface();
    testTestbed2NestedStruct1Interface();
    testTestbed2NestedStruct2Interface();
    testTestbed2NestedStruct3Interface();
    testTbEnumEnumInterface();
    testTbSame1SameStruct1Interface();
    testTbSame1SameStruct2Interface();
    testTbSame1SameEnum1Interface();
    testTbSame1SameEnum2Interface();
    testTbSame2SameStruct1Interface();
    testTbSame2SameStruct2Interface();
    testTbSame2SameEnum1Interface();
    testTbSame2SameEnum2Interface();
    testTbSimpleSimpleInterface();
    testTbSimpleSimpleArrayInterface();
    testTbSimpleNoPropertiesInterface();
    testTbSimpleNoOperationsInterface();
    testTbSimpleNoSignalsInterface();
    testTestbed1StructInterface();
    testTestbed1StructArrayInterface();

    return 0;
}
