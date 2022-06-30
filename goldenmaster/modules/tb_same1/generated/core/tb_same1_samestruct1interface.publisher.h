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
#include "generated/api/tb_same1_datastructs.api.h"
#include "generated/api/tb_same1_samestruct1interface.api.h"
#include "generated/api/tb_same1_common.h"

namespace Test {
namespace TbSame1 {
/**
 * Implementation SameStruct1InterfacePublisher
 */
class TEST_TB_SAME1_EXPORT SameStruct1InterfacePublisher: public ISameStruct1InterfacePublisher
{
public:
    explicit SameStruct1InterfacePublisher();
    virtual ~SameStruct1InterfacePublisher();

    // SameStruct1InterfacePublisher is not copyable
    SameStruct1InterfacePublisher(const SameStruct1InterfacePublisher& a) = delete;
    SameStruct1InterfacePublisher& operator=(const SameStruct1InterfacePublisher& a) = delete;
    // SameStruct1InterfacePublisher is not movable
    SameStruct1InterfacePublisher(SameStruct1InterfacePublisher&& a) = delete;
    SameStruct1InterfacePublisher& operator=(SameStruct1InterfacePublisher&& a) = delete;

    void subscribeToSameStruct1InterfaceInterface(ISameStruct1InterfaceSubscriber& subscriber) override;
    void unsubscribeFromSameStruct1InterfaceInterface(ISameStruct1InterfaceSubscriber& subscriber) override;

    long subscribeToProp1Changed(SameStruct1InterfaceProp1PropertyCb callback) override;
    void unsubscribeFromProp1Changed(long handleId) override;

    long subscribeToSig1(SameStruct1InterfaceSig1SignalCb callback) override;
    void unsubscribeFromSig1(long handleId) override;

    void publishSig1(const Struct1& param1) const override;
protected:
    void publishProp1Changed(const Struct1& prop1) const override;
private:
    std::shared_ptr<ISameStruct1InterfacePublisher> m_impl;
};

} // namespace TbSame1
} // namespace Test
