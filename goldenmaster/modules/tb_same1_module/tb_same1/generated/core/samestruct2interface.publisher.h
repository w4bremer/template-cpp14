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
#include "tb_same1/generated/api/samestruct2interface.api.h"
#include "tb_same1/generated/api/common.h"

namespace Test {
namespace TbSame1 {
/**
 * Implementation SameStruct2InterfacePublisher
 */
class TEST_TB_SAME1_EXPORT SameStruct2InterfacePublisher: public ISameStruct2InterfacePublisher
{
public:
    explicit SameStruct2InterfacePublisher();
    virtual ~SameStruct2InterfacePublisher();

    // SameStruct2InterfacePublisher is not copyable
    SameStruct2InterfacePublisher(const SameStruct2InterfacePublisher& a) = delete;
    SameStruct2InterfacePublisher& operator=(const SameStruct2InterfacePublisher& a) = delete;
    // SameStruct2InterfacePublisher is not movable
    SameStruct2InterfacePublisher(SameStruct2InterfacePublisher&& a) = delete;
    SameStruct2InterfacePublisher& operator=(SameStruct2InterfacePublisher&& a) = delete;

    void subscribeToSameStruct2InterfaceInterface(ISameStruct2InterfaceSubscriber& subscriber) override;
    void unsubscribeFromSameStruct2InterfaceInterface(ISameStruct2InterfaceSubscriber& subscriber) override;

    long subscribeToProp1Changed(SameStruct2InterfaceProp1PropertyCb callback) override;
    void unsubscribeFromProp1Changed(long handleId) override;

    long subscribeToProp2Changed(SameStruct2InterfaceProp2PropertyCb callback) override;
    void unsubscribeFromProp2Changed(long handleId) override;

    long subscribeToSig1(SameStruct2InterfaceSig1SignalCb callback) override;
    void unsubscribeFromSig1(long handleId) override;

    long subscribeToSig2(SameStruct2InterfaceSig2SignalCb callback) override;
    void unsubscribeFromSig2(long handleId) override;

    void publishSig1(const Struct1& param1) const override;
    void publishSig2(const Struct1& param1,const Struct2& param2) const override;
protected:
    void publishProp1Changed(const Struct2& prop1) const override;
    void publishProp2Changed(const Struct2& prop2) const override;
private:
    std::shared_ptr<ISameStruct2InterfacePublisher> m_impl;
};

} // namespace TbSame1
} // namespace Test
