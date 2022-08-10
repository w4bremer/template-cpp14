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

#include "tb_enum/generated/api/datastructs.api.h"
#include "tb_enum/generated/api/enuminterface.api.h"
#include "tb_enum/generated/api/common.h"

#include <vector>
#include <map>
#include <functional>

namespace Test {
namespace TbEnum {

/**
 * The implementation of a EnumInterfacePublisher.
 * Use this class to store clients of the EnumInterface and inform them about the change
 * on call of the appropriate publish function.
 */
class TEST_TB_ENUM_EXPORT EnumInterfacePublisher : public IEnumInterfacePublisher
{
public:
    /**
    * Implementation of IEnumInterfacePublisher::subscribeToAllChanges
    */
    void subscribeToAllChanges(IEnumInterfaceSubscriber& subscriber) override;
    /**
    * Implementation of IEnumInterfacePublisher::unsubscribeFromAllChanges
    */
    void unsubscribeFromAllChanges(IEnumInterfaceSubscriber& subscriber) override;

    /**
    * Implementation of IEnumInterfacePublisher::subscribeToProp0Changed
    */
    long subscribeToProp0Changed(EnumInterfaceProp0PropertyCb callback) override;
    /**
    * Implementation of IEnumInterfacePublisher::subscribeToProp0Changed
    */
    void unsubscribeFromProp0Changed(long handleId) override;

    /**
    * Implementation of IEnumInterfacePublisher::subscribeToProp1Changed
    */
    long subscribeToProp1Changed(EnumInterfaceProp1PropertyCb callback) override;
    /**
    * Implementation of IEnumInterfacePublisher::subscribeToProp1Changed
    */
    void unsubscribeFromProp1Changed(long handleId) override;

    /**
    * Implementation of IEnumInterfacePublisher::subscribeToProp2Changed
    */
    long subscribeToProp2Changed(EnumInterfaceProp2PropertyCb callback) override;
    /**
    * Implementation of IEnumInterfacePublisher::subscribeToProp2Changed
    */
    void unsubscribeFromProp2Changed(long handleId) override;

    /**
    * Implementation of IEnumInterfacePublisher::subscribeToProp3Changed
    */
    long subscribeToProp3Changed(EnumInterfaceProp3PropertyCb callback) override;
    /**
    * Implementation of IEnumInterfacePublisher::subscribeToProp3Changed
    */
    void unsubscribeFromProp3Changed(long handleId) override;

    /**
    * Implementation of IEnumInterfacePublisher::subscribeToSig0
    */
    long subscribeToSig0(EnumInterfaceSig0SignalCb callback) override;
    /**
    * Implementation of IEnumInterfacePublisher::unsubscribeFromSig0
    */
    void unsubscribeFromSig0(long handleId) override;

    /**
    * Implementation of IEnumInterfacePublisher::subscribeToSig1
    */
    long subscribeToSig1(EnumInterfaceSig1SignalCb callback) override;
    /**
    * Implementation of IEnumInterfacePublisher::unsubscribeFromSig1
    */
    void unsubscribeFromSig1(long handleId) override;

    /**
    * Implementation of IEnumInterfacePublisher::subscribeToSig2
    */
    long subscribeToSig2(EnumInterfaceSig2SignalCb callback) override;
    /**
    * Implementation of IEnumInterfacePublisher::unsubscribeFromSig2
    */
    void unsubscribeFromSig2(long handleId) override;

    /**
    * Implementation of IEnumInterfacePublisher::subscribeToSig3
    */
    long subscribeToSig3(EnumInterfaceSig3SignalCb callback) override;
    /**
    * Implementation of IEnumInterfacePublisher::unsubscribeFromSig3
    */
    void unsubscribeFromSig3(long handleId) override;

    /**
    * Implementation of IEnumInterfacePublisher::publishProp0Changed
    */
    void publishProp0Changed(const Enum0Enum& prop0) const override;
    /**
    * Implementation of IEnumInterfacePublisher::publishProp1Changed
    */
    void publishProp1Changed(const Enum1Enum& prop1) const override;
    /**
    * Implementation of IEnumInterfacePublisher::publishProp2Changed
    */
    void publishProp2Changed(const Enum2Enum& prop2) const override;
    /**
    * Implementation of IEnumInterfacePublisher::publishProp3Changed
    */
    void publishProp3Changed(const Enum3Enum& prop3) const override;
    /**
    * Implementation of IEnumInterfacePublisher::publishSig0
    */
    void publishSig0(const Enum0Enum& param0) const override;
    /**
    * Implementation of IEnumInterfacePublisher::publishSig1
    */
    void publishSig1(const Enum1Enum& param1) const override;
    /**
    * Implementation of IEnumInterfacePublisher::publishSig2
    */
    void publishSig2(const Enum2Enum& param2) const override;
    /**
    * Implementation of IEnumInterfacePublisher::publishSig3
    */
    void publishSig3(const Enum3Enum& param3) const override;
private:
    // Subscribers informed about any property change or singal emited in EnumInterface
    std::vector<std::reference_wrapper<IEnumInterfaceSubscriber>> m_allChangesSubscribers;
    // Next free unique identifier to subscribe for the Prop0 change.
    long m_prop0ChangedCallbackNextId = 0;
    // Subscribed callbacks for the Prop0 change.
    std::map<long, EnumInterfaceProp0PropertyCb> m_prop0Callbacks;
    // Next free unique identifier to subscribe for the Prop1 change.
    long m_prop1ChangedCallbackNextId = 0;
    // Subscribed callbacks for the Prop1 change.
    std::map<long, EnumInterfaceProp1PropertyCb> m_prop1Callbacks;
    // Next free unique identifier to subscribe for the Prop2 change.
    long m_prop2ChangedCallbackNextId = 0;
    // Subscribed callbacks for the Prop2 change.
    std::map<long, EnumInterfaceProp2PropertyCb> m_prop2Callbacks;
    // Next free unique identifier to subscribe for the Prop3 change.
    long m_prop3ChangedCallbackNextId = 0;
    // Subscribed callbacks for the Prop3 change.
    std::map<long, EnumInterfaceProp3PropertyCb> m_prop3Callbacks;
    // Next free unique identifier to subscribe for the Sig0 emission.
    long m_sig0SignalCallbackNextId = 0;
    // Subscribed callbacks for the Sig0 emission.
    std::map<long, EnumInterfaceSig0SignalCb > m_sig0Callbacks;
    // Next free unique identifier to subscribe for the Sig1 emission.
    long m_sig1SignalCallbackNextId = 0;
    // Subscribed callbacks for the Sig1 emission.
    std::map<long, EnumInterfaceSig1SignalCb > m_sig1Callbacks;
    // Next free unique identifier to subscribe for the Sig2 emission.
    long m_sig2SignalCallbackNextId = 0;
    // Subscribed callbacks for the Sig2 emission.
    std::map<long, EnumInterfaceSig2SignalCb > m_sig2Callbacks;
    // Next free unique identifier to subscribe for the Sig3 emission.
    long m_sig3SignalCallbackNextId = 0;
    // Subscribed callbacks for the Sig3 emission.
    std::map<long, EnumInterfaceSig3SignalCb > m_sig3Callbacks;
};

} // namespace TbEnum
} // namespace Test
