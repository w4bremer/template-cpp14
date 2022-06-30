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
#include "generated/api/testbed2_nestedstruct3interface.api.h"
#include "generated/api/testbed2_common.h"

namespace Test {
namespace Testbed2 {
/**
 * Implementation NestedStruct3InterfacePublisher
 */
class TEST_TESTBED2_EXPORT NestedStruct3InterfacePublisher: public INestedStruct3InterfacePublisher
{
public:
    explicit NestedStruct3InterfacePublisher();
    virtual ~NestedStruct3InterfacePublisher();

    // NestedStruct3InterfacePublisher is not copyable
    NestedStruct3InterfacePublisher(const NestedStruct3InterfacePublisher& a) = delete;
    NestedStruct3InterfacePublisher& operator=(const NestedStruct3InterfacePublisher& a) = delete;
    // NestedStruct3InterfacePublisher is not movable
    NestedStruct3InterfacePublisher(NestedStruct3InterfacePublisher&& a) = delete;
    NestedStruct3InterfacePublisher& operator=(NestedStruct3InterfacePublisher&& a) = delete;

    void subscribeToNestedStruct3InterfaceInterface(INestedStruct3InterfaceSubscriber& subscriber) override;
    void unsubscribeFromNestedStruct3InterfaceInterface(INestedStruct3InterfaceSubscriber& subscriber) override;

    long subscribeToProp1Changed(NestedStruct3InterfaceProp1PropertyCb callback) override;
    void unsubscribeFromProp1Changed(long handleId) override;

    long subscribeToProp2Changed(NestedStruct3InterfaceProp2PropertyCb callback) override;
    void unsubscribeFromProp2Changed(long handleId) override;

    long subscribeToProp3Changed(NestedStruct3InterfaceProp3PropertyCb callback) override;
    void unsubscribeFromProp3Changed(long handleId) override;

    long subscribeToSig1(NestedStruct3InterfaceSig1SignalCb callback) override;
    void unsubscribeFromSig1(long handleId) override;

    long subscribeToSig2(NestedStruct3InterfaceSig2SignalCb callback) override;
    void unsubscribeFromSig2(long handleId) override;

    long subscribeToSig3(NestedStruct3InterfaceSig3SignalCb callback) override;
    void unsubscribeFromSig3(long handleId) override;

    void publishSig1(const NestedStruct1& param1) const override;
    void publishSig2(const NestedStruct1& param1,const NestedStruct2& param2) const override;
    void publishSig3(const NestedStruct1& param1,const NestedStruct2& param2,const NestedStruct3& param3) const override;
protected:
    void publishProp1Changed(const NestedStruct1& prop1) const override;
    void publishProp2Changed(const NestedStruct2& prop2) const override;
    void publishProp3Changed(const NestedStruct3& prop3) const override;
private:
    std::shared_ptr<INestedStruct3InterfacePublisher> m_impl;
};

} // namespace Testbed2
} // namespace Test
