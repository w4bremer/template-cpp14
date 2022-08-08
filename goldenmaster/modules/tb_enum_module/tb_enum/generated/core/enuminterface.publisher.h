/**
NO TITLE
Copyright (C) 2020 ApiGear UG

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#pragma once

#include <memory>
#include "tb_enum/generated/api/datastructs.api.h"
#include "tb_enum/generated/api/enuminterface.api.h"
#include "tb_enum/generated/api/common.h"

namespace Test {
namespace TbEnum {
/**
 * Implementation EnumInterfacePublisher
 */
class TEST_TB_ENUM_EXPORT EnumInterfacePublisher: public IEnumInterfacePublisher
{
public:
    explicit EnumInterfacePublisher();
    virtual ~EnumInterfacePublisher();

    // EnumInterfacePublisher is not copyable
    EnumInterfacePublisher(const EnumInterfacePublisher& a) = delete;
    EnumInterfacePublisher& operator=(const EnumInterfacePublisher& a) = delete;
    // EnumInterfacePublisher is not movable
    EnumInterfacePublisher(EnumInterfacePublisher&& a) = delete;
    EnumInterfacePublisher& operator=(EnumInterfacePublisher&& a) = delete;

    void subscribeToEnumInterfaceInterface(IEnumInterfaceSubscriber& subscriber) override;
    void unsubscribeFromEnumInterfaceInterface(IEnumInterfaceSubscriber& subscriber) override;

    long subscribeToProp0Changed(EnumInterfaceProp0PropertyCb callback) override;
    void unsubscribeFromProp0Changed(long handleId) override;

    long subscribeToProp1Changed(EnumInterfaceProp1PropertyCb callback) override;
    void unsubscribeFromProp1Changed(long handleId) override;

    long subscribeToProp2Changed(EnumInterfaceProp2PropertyCb callback) override;
    void unsubscribeFromProp2Changed(long handleId) override;

    long subscribeToProp3Changed(EnumInterfaceProp3PropertyCb callback) override;
    void unsubscribeFromProp3Changed(long handleId) override;

    long subscribeToSig0(EnumInterfaceSig0SignalCb callback) override;
    void unsubscribeFromSig0(long handleId) override;

    long subscribeToSig1(EnumInterfaceSig1SignalCb callback) override;
    void unsubscribeFromSig1(long handleId) override;

    long subscribeToSig2(EnumInterfaceSig2SignalCb callback) override;
    void unsubscribeFromSig2(long handleId) override;

    long subscribeToSig3(EnumInterfaceSig3SignalCb callback) override;
    void unsubscribeFromSig3(long handleId) override;

    void publishSig0(const Enum0Enum& param0) const override;
    void publishSig1(const Enum1Enum& param1) const override;
    void publishSig2(const Enum2Enum& param2) const override;
    void publishSig3(const Enum3Enum& param3) const override;
protected:
    void publishProp0Changed(const Enum0Enum& prop0) const override;
    void publishProp1Changed(const Enum1Enum& prop1) const override;
    void publishProp2Changed(const Enum2Enum& prop2) const override;
    void publishProp3Changed(const Enum3Enum& prop3) const override;
private:
    std::shared_ptr<IEnumInterfacePublisher> m_impl;
};

} // namespace TbEnum
} // namespace Test
