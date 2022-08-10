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

#include "tb_same2/generated/api/datastructs.api.h"
#include "tb_same2/generated/api/sameenum1interface.api.h"
#include "tb_same2/generated/api/common.h"

#include <vector>
#include <map>
#include <functional>

namespace Test {
namespace TbSame2 {

/**
 * The implementation of a SameEnum1InterfacePublisher.
 * Use this class to store clients of the SameEnum1Interface and inform them about the change
 * on call of the appropriate publish function.
 */
class TEST_TB_SAME2_EXPORT SameEnum1InterfacePublisher : public ISameEnum1InterfacePublisher
{
public:
    /**
    * Implementation of ISameEnum1InterfacePublisher::subscribeToAllChanges
    */
    void subscribeToAllChanges(ISameEnum1InterfaceSubscriber& subscriber) override;
    /**
    * Implementation of ISameEnum1InterfacePublisher::unsubscribeFromAllChanges
    */
    void unsubscribeFromAllChanges(ISameEnum1InterfaceSubscriber& subscriber) override;

    /**
    * Implementation of ISameEnum1InterfacePublisher::subscribeToProp1Changed
    */
    long subscribeToProp1Changed(SameEnum1InterfaceProp1PropertyCb callback) override;
    /**
    * Implementation of ISameEnum1InterfacePublisher::subscribeToProp1Changed
    */
    void unsubscribeFromProp1Changed(long handleId) override;

    /**
    * Implementation of ISameEnum1InterfacePublisher::subscribeToSig1
    */
    long subscribeToSig1(SameEnum1InterfaceSig1SignalCb callback) override;
    /**
    * Implementation of ISameEnum1InterfacePublisher::unsubscribeFromSig1
    */
    void unsubscribeFromSig1(long handleId) override;

    /**
    * Implementation of ISameEnum1InterfacePublisher::publishProp1Changed
    */
    void publishProp1Changed(const Enum1Enum& prop1) const override;
    /**
    * Implementation of ISameEnum1InterfacePublisher::publishSig1
    */
    void publishSig1(const Enum1Enum& param1) const override;
private:
    // Subscribers informed about any property change or singal emited in SameEnum1Interface
    std::vector<std::reference_wrapper<ISameEnum1InterfaceSubscriber>> m_allChangesSubscribers;
    // Next free unique identifier to subscribe for the Prop1 change.
    long m_prop1ChangedCallbackNextId = 0;
    // Subscribed callbacks for the Prop1 change.
    std::map<long, SameEnum1InterfaceProp1PropertyCb> m_prop1Callbacks;
    // Next free unique identifier to subscribe for the Sig1 emission.
    long m_sig1SignalCallbackNextId = 0;
    // Subscribed callbacks for the Sig1 emission.
    std::map<long, SameEnum1InterfaceSig1SignalCb > m_sig1Callbacks;
};

} // namespace TbSame2
} // namespace Test
