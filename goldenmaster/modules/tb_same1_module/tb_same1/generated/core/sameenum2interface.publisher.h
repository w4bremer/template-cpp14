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
#include "tb_same1/generated/api/datastructs.api.h"
#include "tb_same1/generated/api/sameenum2interface.api.h"
#include "tb_same1/generated/api/common.h"

namespace Test {
namespace TbSame1 {
/**
 * Implementation SameEnum2InterfacePublisher
 */
class TEST_TB_SAME1_EXPORT SameEnum2InterfacePublisher: public ISameEnum2InterfacePublisher
{
public:
    explicit SameEnum2InterfacePublisher();
    virtual ~SameEnum2InterfacePublisher();

    // SameEnum2InterfacePublisher is not copyable
    SameEnum2InterfacePublisher(const SameEnum2InterfacePublisher& a) = delete;
    SameEnum2InterfacePublisher& operator=(const SameEnum2InterfacePublisher& a) = delete;
    // SameEnum2InterfacePublisher is not movable
    SameEnum2InterfacePublisher(SameEnum2InterfacePublisher&& a) = delete;
    SameEnum2InterfacePublisher& operator=(SameEnum2InterfacePublisher&& a) = delete;

    void subscribeToSameEnum2InterfaceInterface(ISameEnum2InterfaceSubscriber& subscriber) override;
    void unsubscribeFromSameEnum2InterfaceInterface(ISameEnum2InterfaceSubscriber& subscriber) override;

    long subscribeToProp1Changed(SameEnum2InterfaceProp1PropertyCb callback) override;
    void unsubscribeFromProp1Changed(long handleId) override;

    long subscribeToProp2Changed(SameEnum2InterfaceProp2PropertyCb callback) override;
    void unsubscribeFromProp2Changed(long handleId) override;

    long subscribeToSig1(SameEnum2InterfaceSig1SignalCb callback) override;
    void unsubscribeFromSig1(long handleId) override;

    long subscribeToSig2(SameEnum2InterfaceSig2SignalCb callback) override;
    void unsubscribeFromSig2(long handleId) override;

    void publishSig1(const Enum1Enum& param1) const override;
    void publishSig2(const Enum1Enum& param1,const Enum2Enum& param2) const override;
protected:
    void publishProp1Changed(const Enum1Enum& prop1) const override;
    void publishProp2Changed(const Enum2Enum& prop2) const override;
private:
    std::shared_ptr<ISameEnum2InterfacePublisher> m_impl;
};

} // namespace TbSame1
} // namespace Test
