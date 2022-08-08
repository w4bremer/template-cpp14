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
#include "tb_same1/generated/api/sameenum1interface.api.h"
#include "tb_same1/generated/api/common.h"

namespace Test {
namespace TbSame1 {
/**
 * Implementation SameEnum1InterfacePublisher
 */
class TEST_TB_SAME1_EXPORT SameEnum1InterfacePublisher: public ISameEnum1InterfacePublisher
{
public:
    explicit SameEnum1InterfacePublisher();
    virtual ~SameEnum1InterfacePublisher();

    // SameEnum1InterfacePublisher is not copyable
    SameEnum1InterfacePublisher(const SameEnum1InterfacePublisher& a) = delete;
    SameEnum1InterfacePublisher& operator=(const SameEnum1InterfacePublisher& a) = delete;
    // SameEnum1InterfacePublisher is not movable
    SameEnum1InterfacePublisher(SameEnum1InterfacePublisher&& a) = delete;
    SameEnum1InterfacePublisher& operator=(SameEnum1InterfacePublisher&& a) = delete;

    void subscribeToSameEnum1InterfaceInterface(ISameEnum1InterfaceSubscriber& subscriber) override;
    void unsubscribeFromSameEnum1InterfaceInterface(ISameEnum1InterfaceSubscriber& subscriber) override;

    long subscribeToProp1Changed(SameEnum1InterfaceProp1PropertyCb callback) override;
    void unsubscribeFromProp1Changed(long handleId) override;

    long subscribeToSig1(SameEnum1InterfaceSig1SignalCb callback) override;
    void unsubscribeFromSig1(long handleId) override;

    void publishSig1(const Enum1Enum& param1) const override;
protected:
    void publishProp1Changed(const Enum1Enum& prop1) const override;
private:
    std::shared_ptr<ISameEnum1InterfacePublisher> m_impl;
};

} // namespace TbSame1
} // namespace Test
