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

#include "tb_same1/generated/api/datastructs.api.h"
#include "tb_same1/generated/api/samestruct1interface.api.h"
#include "tb_same1/generated/api/common.h"

#include <vector>
#include <map>
#include <functional>

namespace Test {
namespace TbSame1 {

/**
 * The implementation of a SameStruct1InterfacePublisher.
 * Use this class to store clients of the SameStruct1Interface and inform them about the change
 * on call of the appropriate publish function.
 */
class TEST_TB_SAME1_EXPORT SameStruct1InterfacePublisher : public ISameStruct1InterfacePublisher
{
public:
    /**
    * Implementation of ISameStruct1InterfacePublisher::subscribeToAllChanges
    */
    void subscribeToAllChanges(ISameStruct1InterfaceSubscriber& subscriber) override;
    /**
    * Implementation of ISameStruct1InterfacePublisher::unsubscribeFromAllChanges
    */
    void unsubscribeFromAllChanges(ISameStruct1InterfaceSubscriber& subscriber) override;

    /**
    * Implementation of ISameStruct1InterfacePublisher::subscribeToProp1Changed
    */
    long subscribeToProp1Changed(SameStruct1InterfaceProp1PropertyCb callback) override;
    /**
    * Implementation of ISameStruct1InterfacePublisher::subscribeToProp1Changed
    */
    void unsubscribeFromProp1Changed(long handleId) override;

    /**
    * Implementation of ISameStruct1InterfacePublisher::subscribeToSig1
    */
    long subscribeToSig1(SameStruct1InterfaceSig1SignalCb callback) override;
    /**
    * Implementation of ISameStruct1InterfacePublisher::unsubscribeFromSig1
    */
    void unsubscribeFromSig1(long handleId) override;

    /**
    * Implementation of ISameStruct1InterfacePublisher::publishProp1Changed
    */
    void publishProp1Changed(const Struct1& prop1) const override;
    /**
    * Implementation of ISameStruct1InterfacePublisher::publishSig1
    */
    void publishSig1(const Struct1& param1) const override;
private:
    // Subscribers informed about any property change or singal emited in SameStruct1Interface
    std::vector<std::reference_wrapper<ISameStruct1InterfaceSubscriber>> m_allChangesSubscribers;
    // Next free unique identifier to subscribe for the Prop1 change.
    long m_prop1ChangedCallbackNextId = 0;
    // Subscribed callbacks for the Prop1 change.
    std::map<long, SameStruct1InterfaceProp1PropertyCb> m_prop1Callbacks;
    // Next free unique identifier to subscribe for the Sig1 emission.
    long m_sig1SignalCallbackNextId = 0;
    // Subscribed callbacks for the Sig1 emission.
    std::map<long, SameStruct1InterfaceSig1SignalCb > m_sig1Callbacks;
};

} // namespace TbSame1
} // namespace Test
