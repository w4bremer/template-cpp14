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

#include "testbed2/generated/api/datastructs.api.h"
#include "testbed2/generated/api/manyparaminterface.api.h"
#include "testbed2/generated/api/common.h"

#include <vector>
#include <map>
#include <functional>

namespace Test {
namespace Testbed2 {

/**
 * The implementation of a ManyParamInterfacePublisher.
 * Use this class to store clients of the ManyParamInterface and inform them about the change
 * on call of the appropriate publish function.
 */
class TEST_TESTBED2_EXPORT ManyParamInterfacePublisher : public IManyParamInterfacePublisher
{
public:
    /**
    * Implementation of IManyParamInterfacePublisher::subscribeToAllChanges
    */
    void subscribeToAllChanges(IManyParamInterfaceSubscriber& subscriber) override;
    /**
    * Implementation of IManyParamInterfacePublisher::unsubscribeFromAllChanges
    */
    void unsubscribeFromAllChanges(IManyParamInterfaceSubscriber& subscriber) override;

    /**
    * Implementation of IManyParamInterfacePublisher::subscribeToProp1Changed
    */
    long subscribeToProp1Changed(ManyParamInterfaceProp1PropertyCb callback) override;
    /**
    * Implementation of IManyParamInterfacePublisher::subscribeToProp1Changed
    */
    void unsubscribeFromProp1Changed(long handleId) override;

    /**
    * Implementation of IManyParamInterfacePublisher::subscribeToProp2Changed
    */
    long subscribeToProp2Changed(ManyParamInterfaceProp2PropertyCb callback) override;
    /**
    * Implementation of IManyParamInterfacePublisher::subscribeToProp2Changed
    */
    void unsubscribeFromProp2Changed(long handleId) override;

    /**
    * Implementation of IManyParamInterfacePublisher::subscribeToProp3Changed
    */
    long subscribeToProp3Changed(ManyParamInterfaceProp3PropertyCb callback) override;
    /**
    * Implementation of IManyParamInterfacePublisher::subscribeToProp3Changed
    */
    void unsubscribeFromProp3Changed(long handleId) override;

    /**
    * Implementation of IManyParamInterfacePublisher::subscribeToProp4Changed
    */
    long subscribeToProp4Changed(ManyParamInterfaceProp4PropertyCb callback) override;
    /**
    * Implementation of IManyParamInterfacePublisher::subscribeToProp4Changed
    */
    void unsubscribeFromProp4Changed(long handleId) override;

    /**
    * Implementation of IManyParamInterfacePublisher::subscribeToSig1
    */
    long subscribeToSig1(ManyParamInterfaceSig1SignalCb callback) override;
    /**
    * Implementation of IManyParamInterfacePublisher::unsubscribeFromSig1
    */
    void unsubscribeFromSig1(long handleId) override;

    /**
    * Implementation of IManyParamInterfacePublisher::subscribeToSig2
    */
    long subscribeToSig2(ManyParamInterfaceSig2SignalCb callback) override;
    /**
    * Implementation of IManyParamInterfacePublisher::unsubscribeFromSig2
    */
    void unsubscribeFromSig2(long handleId) override;

    /**
    * Implementation of IManyParamInterfacePublisher::subscribeToSig3
    */
    long subscribeToSig3(ManyParamInterfaceSig3SignalCb callback) override;
    /**
    * Implementation of IManyParamInterfacePublisher::unsubscribeFromSig3
    */
    void unsubscribeFromSig3(long handleId) override;

    /**
    * Implementation of IManyParamInterfacePublisher::subscribeToSig4
    */
    long subscribeToSig4(ManyParamInterfaceSig4SignalCb callback) override;
    /**
    * Implementation of IManyParamInterfacePublisher::unsubscribeFromSig4
    */
    void unsubscribeFromSig4(long handleId) override;

    /**
    * Implementation of IManyParamInterfacePublisher::publishProp1Changed
    */
    void publishProp1Changed(int prop1) const override;
    /**
    * Implementation of IManyParamInterfacePublisher::publishProp2Changed
    */
    void publishProp2Changed(int prop2) const override;
    /**
    * Implementation of IManyParamInterfacePublisher::publishProp3Changed
    */
    void publishProp3Changed(int prop3) const override;
    /**
    * Implementation of IManyParamInterfacePublisher::publishProp4Changed
    */
    void publishProp4Changed(int prop4) const override;
    /**
    * Implementation of IManyParamInterfacePublisher::publishSig1
    */
    void publishSig1(int param1) const override;
    /**
    * Implementation of IManyParamInterfacePublisher::publishSig2
    */
    void publishSig2(int param1,int param2) const override;
    /**
    * Implementation of IManyParamInterfacePublisher::publishSig3
    */
    void publishSig3(int param1,int param2,int param3) const override;
    /**
    * Implementation of IManyParamInterfacePublisher::publishSig4
    */
    void publishSig4(int param1,int param2,int param3,int param4) const override;
private:
    // Subscribers informed about any property change or singal emited in ManyParamInterface
    std::vector<std::reference_wrapper<IManyParamInterfaceSubscriber>> m_allChangesSubscribers;
    // Next free unique identifier to subscribe for the Prop1 change.
    long m_prop1ChangedCallbackNextId = 0;
    // Subscribed callbacks for the Prop1 change.
    std::map<long, ManyParamInterfaceProp1PropertyCb> m_prop1Callbacks;
    // Next free unique identifier to subscribe for the Prop2 change.
    long m_prop2ChangedCallbackNextId = 0;
    // Subscribed callbacks for the Prop2 change.
    std::map<long, ManyParamInterfaceProp2PropertyCb> m_prop2Callbacks;
    // Next free unique identifier to subscribe for the Prop3 change.
    long m_prop3ChangedCallbackNextId = 0;
    // Subscribed callbacks for the Prop3 change.
    std::map<long, ManyParamInterfaceProp3PropertyCb> m_prop3Callbacks;
    // Next free unique identifier to subscribe for the Prop4 change.
    long m_prop4ChangedCallbackNextId = 0;
    // Subscribed callbacks for the Prop4 change.
    std::map<long, ManyParamInterfaceProp4PropertyCb> m_prop4Callbacks;
    // Next free unique identifier to subscribe for the Sig1 emission.
    long m_sig1SignalCallbackNextId = 0;
    // Subscribed callbacks for the Sig1 emission.
    std::map<long, ManyParamInterfaceSig1SignalCb > m_sig1Callbacks;
    // Next free unique identifier to subscribe for the Sig2 emission.
    long m_sig2SignalCallbackNextId = 0;
    // Subscribed callbacks for the Sig2 emission.
    std::map<long, ManyParamInterfaceSig2SignalCb > m_sig2Callbacks;
    // Next free unique identifier to subscribe for the Sig3 emission.
    long m_sig3SignalCallbackNextId = 0;
    // Subscribed callbacks for the Sig3 emission.
    std::map<long, ManyParamInterfaceSig3SignalCb > m_sig3Callbacks;
    // Next free unique identifier to subscribe for the Sig4 emission.
    long m_sig4SignalCallbackNextId = 0;
    // Subscribed callbacks for the Sig4 emission.
    std::map<long, ManyParamInterfaceSig4SignalCb > m_sig4Callbacks;
};

} // namespace Testbed2
} // namespace Test
