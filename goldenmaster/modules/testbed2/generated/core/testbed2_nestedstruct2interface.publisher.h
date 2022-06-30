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
#include "generated/api/testbed2_datastructs.api.h"
#include "generated/api/testbed2_nestedstruct2interface.api.h"
#include "generated/api/testbed2_common.h"

namespace Test {
namespace Testbed2 {
/**
 * Implementation NestedStruct2InterfacePublisher
 */
class TEST_TESTBED2_EXPORT NestedStruct2InterfacePublisher: public INestedStruct2InterfacePublisher
{
public:
    explicit NestedStruct2InterfacePublisher();
    virtual ~NestedStruct2InterfacePublisher();

    // NestedStruct2InterfacePublisher is not copyable
    NestedStruct2InterfacePublisher(const NestedStruct2InterfacePublisher& a) = delete;
    NestedStruct2InterfacePublisher& operator=(const NestedStruct2InterfacePublisher& a) = delete;
    // NestedStruct2InterfacePublisher is not movable
    NestedStruct2InterfacePublisher(NestedStruct2InterfacePublisher&& a) = delete;
    NestedStruct2InterfacePublisher& operator=(NestedStruct2InterfacePublisher&& a) = delete;

    void subscribeToNestedStruct2InterfaceInterface(INestedStruct2InterfaceSubscriber& subscriber) override;
    void unsubscribeFromNestedStruct2InterfaceInterface(INestedStruct2InterfaceSubscriber& subscriber) override;

    long subscribeToProp1Changed(NestedStruct2InterfaceProp1PropertyCb callback) override;
    void unsubscribeFromProp1Changed(long handleId) override;

    long subscribeToProp2Changed(NestedStruct2InterfaceProp2PropertyCb callback) override;
    void unsubscribeFromProp2Changed(long handleId) override;

    long subscribeToSig1(NestedStruct2InterfaceSig1SignalCb callback) override;
    void unsubscribeFromSig1(long handleId) override;

    long subscribeToSig2(NestedStruct2InterfaceSig2SignalCb callback) override;
    void unsubscribeFromSig2(long handleId) override;

    void publishSig1(const NestedStruct1& param1) const override;
    void publishSig2(const NestedStruct1& param1,const NestedStruct2& param2) const override;
protected:
    void publishProp1Changed(const NestedStruct1& prop1) const override;
    void publishProp2Changed(const NestedStruct2& prop2) const override;
private:
    std::shared_ptr<INestedStruct2InterfacePublisher> m_impl;
};

} // namespace Testbed2
} // namespace Test
