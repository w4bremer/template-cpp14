#include <iostream>
#include "testbed2/generated/mqtt/manyparaminterfaceclient.h"
#include "testbed2/generated/mqtt/nestedstruct1interfaceclient.h"
#include "testbed2/generated/mqtt/nestedstruct2interfaceclient.h"
#include "testbed2/generated/mqtt/nestedstruct3interfaceclient.h"
#include "tb_enum/generated/mqtt/enuminterfaceclient.h"
#include "tb_same1/generated/mqtt/samestruct1interfaceclient.h"
#include "tb_same1/generated/mqtt/samestruct2interfaceclient.h"
#include "tb_same1/generated/mqtt/sameenum1interfaceclient.h"
#include "tb_same1/generated/mqtt/sameenum2interfaceclient.h"
#include "tb_same2/generated/mqtt/samestruct1interfaceclient.h"
#include "tb_same2/generated/mqtt/samestruct2interfaceclient.h"
#include "tb_same2/generated/mqtt/sameenum1interfaceclient.h"
#include "tb_same2/generated/mqtt/sameenum2interfaceclient.h"
#include "tb_simple/generated/mqtt/voidinterfaceclient.h"
#include "tb_simple/generated/mqtt/simpleinterfaceclient.h"
#include "tb_simple/generated/mqtt/simplearrayinterfaceclient.h"
#include "tb_simple/generated/mqtt/nopropertiesinterfaceclient.h"
#include "tb_simple/generated/mqtt/nooperationsinterfaceclient.h"
#include "tb_simple/generated/mqtt/nosignalsinterfaceclient.h"
#include "testbed1/generated/mqtt/structinterfaceclient.h"
#include "testbed1/generated/mqtt/structarrayinterfaceclient.h"
#include "apigear/mqtt/mqttcppclient.h"
#include <random>
#include <mutex>

using namespace Test;

int main(){
    std::mt19937 randomNumberGenerator (std::random_device{}());
    std::uniform_int_distribution<> distribution (0, 100000);

    auto randomId = distribution(randomNumberGenerator);
    // MQTT clients need to have unique identifiers
    auto mqttclient = std::make_shared<ApiGear::MQTTImpl::Client>("testClient"+std::to_string(randomId));
    mqttclient->connectToHost("");
    std::unique_ptr<Testbed2::IManyParamInterface> testTestbed2ManyParamInterface = std::make_unique<Testbed2::mqtt::ManyParamInterfaceClient>(mqttclient);
    std::unique_ptr<Testbed2::INestedStruct1Interface> testTestbed2NestedStruct1Interface = std::make_unique<Testbed2::mqtt::NestedStruct1InterfaceClient>(mqttclient);
    std::unique_ptr<Testbed2::INestedStruct2Interface> testTestbed2NestedStruct2Interface = std::make_unique<Testbed2::mqtt::NestedStruct2InterfaceClient>(mqttclient);
    std::unique_ptr<Testbed2::INestedStruct3Interface> testTestbed2NestedStruct3Interface = std::make_unique<Testbed2::mqtt::NestedStruct3InterfaceClient>(mqttclient);
    std::unique_ptr<TbEnum::IEnumInterface> testTbEnumEnumInterface = std::make_unique<TbEnum::mqtt::EnumInterfaceClient>(mqttclient);
    std::unique_ptr<TbSame1::ISameStruct1Interface> testTbSame1SameStruct1Interface = std::make_unique<TbSame1::mqtt::SameStruct1InterfaceClient>(mqttclient);
    std::unique_ptr<TbSame1::ISameStruct2Interface> testTbSame1SameStruct2Interface = std::make_unique<TbSame1::mqtt::SameStruct2InterfaceClient>(mqttclient);
    std::unique_ptr<TbSame1::ISameEnum1Interface> testTbSame1SameEnum1Interface = std::make_unique<TbSame1::mqtt::SameEnum1InterfaceClient>(mqttclient);
    std::unique_ptr<TbSame1::ISameEnum2Interface> testTbSame1SameEnum2Interface = std::make_unique<TbSame1::mqtt::SameEnum2InterfaceClient>(mqttclient);
    std::unique_ptr<TbSame2::ISameStruct1Interface> testTbSame2SameStruct1Interface = std::make_unique<TbSame2::mqtt::SameStruct1InterfaceClient>(mqttclient);
    std::unique_ptr<TbSame2::ISameStruct2Interface> testTbSame2SameStruct2Interface = std::make_unique<TbSame2::mqtt::SameStruct2InterfaceClient>(mqttclient);
    std::unique_ptr<TbSame2::ISameEnum1Interface> testTbSame2SameEnum1Interface = std::make_unique<TbSame2::mqtt::SameEnum1InterfaceClient>(mqttclient);
    std::unique_ptr<TbSame2::ISameEnum2Interface> testTbSame2SameEnum2Interface = std::make_unique<TbSame2::mqtt::SameEnum2InterfaceClient>(mqttclient);
    std::unique_ptr<TbSimple::IVoidInterface> testTbSimpleVoidInterface = std::make_unique<TbSimple::mqtt::VoidInterfaceClient>(mqttclient);
    std::unique_ptr<TbSimple::ISimpleInterface> testTbSimpleSimpleInterface = std::make_unique<TbSimple::mqtt::SimpleInterfaceClient>(mqttclient);
    std::unique_ptr<TbSimple::ISimpleArrayInterface> testTbSimpleSimpleArrayInterface = std::make_unique<TbSimple::mqtt::SimpleArrayInterfaceClient>(mqttclient);
    std::unique_ptr<TbSimple::INoPropertiesInterface> testTbSimpleNoPropertiesInterface = std::make_unique<TbSimple::mqtt::NoPropertiesInterfaceClient>(mqttclient);
    std::unique_ptr<TbSimple::INoOperationsInterface> testTbSimpleNoOperationsInterface = std::make_unique<TbSimple::mqtt::NoOperationsInterfaceClient>(mqttclient);
    std::unique_ptr<TbSimple::INoSignalsInterface> testTbSimpleNoSignalsInterface = std::make_unique<TbSimple::mqtt::NoSignalsInterfaceClient>(mqttclient);
    std::unique_ptr<Testbed1::IStructInterface> testTestbed1StructInterface = std::make_unique<Testbed1::mqtt::StructInterfaceClient>(mqttclient);
    std::unique_ptr<Testbed1::IStructArrayInterface> testTestbed1StructArrayInterface = std::make_unique<Testbed1::mqtt::StructArrayInterfaceClient>(mqttclient);

    bool keepRunning = true;
    std::string cmd;
    do {
        std::cout << "Enter command:" << std::endl;
        getline (std::cin, cmd);

        if(cmd == "quit"){
            mqttclient->disconnect();
            keepRunning = false;
        } else {

        }
    } while(keepRunning);

    return 0;
}
