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

#include "testbed1/generated/api/datastructs.api.h"
#include "testbed1/generated/api/structinterface.api.h"
#include "testbed1/generated/api/common.h"

#include <vector>
#include <map>
#include <functional>

namespace Test {
namespace Testbed1 {

/**
 * The implementation of a StructInterfacePublisher.
 * Use this class to store clients of the StructInterface and inform them about the change
 * on call of the appropriate publish function.
 */
class TEST_TESTBED1_EXPORT StructInterfacePublisher : public IStructInterfacePublisher
{
public:
    /**
    * Implementation of IStructInterfacePublisher::subscribeToAllChanges
    */
    void subscribeToAllChanges(IStructInterfaceSubscriber& subscriber) override;
    /**
    * Implementation of IStructInterfacePublisher::unsubscribeFromAllChanges
    */
    void unsubscribeFromAllChanges(IStructInterfaceSubscriber& subscriber) override;

    /**
    * Implementation of IStructInterfacePublisher::subscribeToPropBoolChanged
    */
    long subscribeToPropBoolChanged(StructInterfacePropBoolPropertyCb callback) override;
    /**
    * Implementation of IStructInterfacePublisher::subscribeToPropBoolChanged
    */
    void unsubscribeFromPropBoolChanged(long handleId) override;

    /**
    * Implementation of IStructInterfacePublisher::subscribeToPropIntChanged
    */
    long subscribeToPropIntChanged(StructInterfacePropIntPropertyCb callback) override;
    /**
    * Implementation of IStructInterfacePublisher::subscribeToPropIntChanged
    */
    void unsubscribeFromPropIntChanged(long handleId) override;

    /**
    * Implementation of IStructInterfacePublisher::subscribeToPropFloatChanged
    */
    long subscribeToPropFloatChanged(StructInterfacePropFloatPropertyCb callback) override;
    /**
    * Implementation of IStructInterfacePublisher::subscribeToPropFloatChanged
    */
    void unsubscribeFromPropFloatChanged(long handleId) override;

    /**
    * Implementation of IStructInterfacePublisher::subscribeToPropStringChanged
    */
    long subscribeToPropStringChanged(StructInterfacePropStringPropertyCb callback) override;
    /**
    * Implementation of IStructInterfacePublisher::subscribeToPropStringChanged
    */
    void unsubscribeFromPropStringChanged(long handleId) override;

    /**
    * Implementation of IStructInterfacePublisher::subscribeToSigBool
    */
    long subscribeToSigBool(StructInterfaceSigBoolSignalCb callback) override;
    /**
    * Implementation of IStructInterfacePublisher::unsubscribeFromSigBool
    */
    void unsubscribeFromSigBool(long handleId) override;

    /**
    * Implementation of IStructInterfacePublisher::subscribeToSigInt
    */
    long subscribeToSigInt(StructInterfaceSigIntSignalCb callback) override;
    /**
    * Implementation of IStructInterfacePublisher::unsubscribeFromSigInt
    */
    void unsubscribeFromSigInt(long handleId) override;

    /**
    * Implementation of IStructInterfacePublisher::subscribeToSigFloat
    */
    long subscribeToSigFloat(StructInterfaceSigFloatSignalCb callback) override;
    /**
    * Implementation of IStructInterfacePublisher::unsubscribeFromSigFloat
    */
    void unsubscribeFromSigFloat(long handleId) override;

    /**
    * Implementation of IStructInterfacePublisher::subscribeToSigString
    */
    long subscribeToSigString(StructInterfaceSigStringSignalCb callback) override;
    /**
    * Implementation of IStructInterfacePublisher::unsubscribeFromSigString
    */
    void unsubscribeFromSigString(long handleId) override;

    /**
    * Implementation of IStructInterfacePublisher::publishPropBoolChanged
    */
    void publishPropBoolChanged(const StructBool& propBool) const override;
    /**
    * Implementation of IStructInterfacePublisher::publishPropIntChanged
    */
    void publishPropIntChanged(const StructInt& propInt) const override;
    /**
    * Implementation of IStructInterfacePublisher::publishPropFloatChanged
    */
    void publishPropFloatChanged(const StructFloat& propFloat) const override;
    /**
    * Implementation of IStructInterfacePublisher::publishPropStringChanged
    */
    void publishPropStringChanged(const StructString& propString) const override;
    /**
    * Implementation of IStructInterfacePublisher::publishSigBool
    */
    void publishSigBool(const StructBool& paramBool) const override;
    /**
    * Implementation of IStructInterfacePublisher::publishSigInt
    */
    void publishSigInt(const StructInt& paramInt) const override;
    /**
    * Implementation of IStructInterfacePublisher::publishSigFloat
    */
    void publishSigFloat(const StructFloat& paramFloat) const override;
    /**
    * Implementation of IStructInterfacePublisher::publishSigString
    */
    void publishSigString(const StructString& paramString) const override;
private:
    // Subscribers informed about any property change or singal emited in StructInterface
    std::vector<std::reference_wrapper<IStructInterfaceSubscriber>> m_allChangesSubscribers;
    // Next free unique identifier to subscribe for the PropBool change.
    long m_propBoolChangedCallbackNextId = 0;
    // Subscribed callbacks for the PropBool change.
    std::map<long, StructInterfacePropBoolPropertyCb> m_propBoolCallbacks;
    // Next free unique identifier to subscribe for the PropInt change.
    long m_propIntChangedCallbackNextId = 0;
    // Subscribed callbacks for the PropInt change.
    std::map<long, StructInterfacePropIntPropertyCb> m_propIntCallbacks;
    // Next free unique identifier to subscribe for the PropFloat change.
    long m_propFloatChangedCallbackNextId = 0;
    // Subscribed callbacks for the PropFloat change.
    std::map<long, StructInterfacePropFloatPropertyCb> m_propFloatCallbacks;
    // Next free unique identifier to subscribe for the PropString change.
    long m_propStringChangedCallbackNextId = 0;
    // Subscribed callbacks for the PropString change.
    std::map<long, StructInterfacePropStringPropertyCb> m_propStringCallbacks;
    // Next free unique identifier to subscribe for the SigBool emission.
    long m_sigBoolSignalCallbackNextId = 0;
    // Subscribed callbacks for the SigBool emission.
    std::map<long, StructInterfaceSigBoolSignalCb > m_sigBoolCallbacks;
    // Next free unique identifier to subscribe for the SigInt emission.
    long m_sigIntSignalCallbackNextId = 0;
    // Subscribed callbacks for the SigInt emission.
    std::map<long, StructInterfaceSigIntSignalCb > m_sigIntCallbacks;
    // Next free unique identifier to subscribe for the SigFloat emission.
    long m_sigFloatSignalCallbackNextId = 0;
    // Subscribed callbacks for the SigFloat emission.
    std::map<long, StructInterfaceSigFloatSignalCb > m_sigFloatCallbacks;
    // Next free unique identifier to subscribe for the SigString emission.
    long m_sigStringSignalCallbackNextId = 0;
    // Subscribed callbacks for the SigString emission.
    std::map<long, StructInterfaceSigStringSignalCb > m_sigStringCallbacks;
};

} // namespace Testbed1
} // namespace Test
