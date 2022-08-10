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

#include "tb_simple/generated/api/datastructs.api.h"
#include "tb_simple/generated/api/simplearrayinterface.api.h"
#include "tb_simple/generated/api/common.h"

#include <vector>
#include <map>
#include <functional>

namespace Test {
namespace TbSimple {

/**
 * The implementation of a SimpleArrayInterfacePublisher.
 * Use this class to store clients of the SimpleArrayInterface and inform them about the change
 * on call of the appropriate publish function.
 */
class TEST_TB_SIMPLE_EXPORT SimpleArrayInterfacePublisher : public ISimpleArrayInterfacePublisher
{
public:
    /**
    * Implementation of ISimpleArrayInterfacePublisher::subscribeToAllChanges
    */
    void subscribeToAllChanges(ISimpleArrayInterfaceSubscriber& subscriber) override;
    /**
    * Implementation of ISimpleArrayInterfacePublisher::unsubscribeFromAllChanges
    */
    void unsubscribeFromAllChanges(ISimpleArrayInterfaceSubscriber& subscriber) override;

    /**
    * Implementation of ISimpleArrayInterfacePublisher::subscribeToPropBoolChanged
    */
    long subscribeToPropBoolChanged(SimpleArrayInterfacePropBoolPropertyCb callback) override;
    /**
    * Implementation of ISimpleArrayInterfacePublisher::subscribeToPropBoolChanged
    */
    void unsubscribeFromPropBoolChanged(long handleId) override;

    /**
    * Implementation of ISimpleArrayInterfacePublisher::subscribeToPropIntChanged
    */
    long subscribeToPropIntChanged(SimpleArrayInterfacePropIntPropertyCb callback) override;
    /**
    * Implementation of ISimpleArrayInterfacePublisher::subscribeToPropIntChanged
    */
    void unsubscribeFromPropIntChanged(long handleId) override;

    /**
    * Implementation of ISimpleArrayInterfacePublisher::subscribeToPropFloatChanged
    */
    long subscribeToPropFloatChanged(SimpleArrayInterfacePropFloatPropertyCb callback) override;
    /**
    * Implementation of ISimpleArrayInterfacePublisher::subscribeToPropFloatChanged
    */
    void unsubscribeFromPropFloatChanged(long handleId) override;

    /**
    * Implementation of ISimpleArrayInterfacePublisher::subscribeToPropStringChanged
    */
    long subscribeToPropStringChanged(SimpleArrayInterfacePropStringPropertyCb callback) override;
    /**
    * Implementation of ISimpleArrayInterfacePublisher::subscribeToPropStringChanged
    */
    void unsubscribeFromPropStringChanged(long handleId) override;

    /**
    * Implementation of ISimpleArrayInterfacePublisher::subscribeToSigBool
    */
    long subscribeToSigBool(SimpleArrayInterfaceSigBoolSignalCb callback) override;
    /**
    * Implementation of ISimpleArrayInterfacePublisher::unsubscribeFromSigBool
    */
    void unsubscribeFromSigBool(long handleId) override;

    /**
    * Implementation of ISimpleArrayInterfacePublisher::subscribeToSigInt
    */
    long subscribeToSigInt(SimpleArrayInterfaceSigIntSignalCb callback) override;
    /**
    * Implementation of ISimpleArrayInterfacePublisher::unsubscribeFromSigInt
    */
    void unsubscribeFromSigInt(long handleId) override;

    /**
    * Implementation of ISimpleArrayInterfacePublisher::subscribeToSigFloat
    */
    long subscribeToSigFloat(SimpleArrayInterfaceSigFloatSignalCb callback) override;
    /**
    * Implementation of ISimpleArrayInterfacePublisher::unsubscribeFromSigFloat
    */
    void unsubscribeFromSigFloat(long handleId) override;

    /**
    * Implementation of ISimpleArrayInterfacePublisher::subscribeToSigString
    */
    long subscribeToSigString(SimpleArrayInterfaceSigStringSignalCb callback) override;
    /**
    * Implementation of ISimpleArrayInterfacePublisher::unsubscribeFromSigString
    */
    void unsubscribeFromSigString(long handleId) override;

    /**
    * Implementation of ISimpleArrayInterfacePublisher::publishPropBoolChanged
    */
    void publishPropBoolChanged(const std::list<bool>& propBool) const override;
    /**
    * Implementation of ISimpleArrayInterfacePublisher::publishPropIntChanged
    */
    void publishPropIntChanged(const std::list<int>& propInt) const override;
    /**
    * Implementation of ISimpleArrayInterfacePublisher::publishPropFloatChanged
    */
    void publishPropFloatChanged(const std::list<float>& propFloat) const override;
    /**
    * Implementation of ISimpleArrayInterfacePublisher::publishPropStringChanged
    */
    void publishPropStringChanged(const std::list<std::string>& propString) const override;
    /**
    * Implementation of ISimpleArrayInterfacePublisher::publishSigBool
    */
    void publishSigBool(const std::list<bool>& paramBool) const override;
    /**
    * Implementation of ISimpleArrayInterfacePublisher::publishSigInt
    */
    void publishSigInt(const std::list<int>& paramInt) const override;
    /**
    * Implementation of ISimpleArrayInterfacePublisher::publishSigFloat
    */
    void publishSigFloat(const std::list<float>& paramFloat) const override;
    /**
    * Implementation of ISimpleArrayInterfacePublisher::publishSigString
    */
    void publishSigString(const std::list<std::string>& paramString) const override;
private:
    // Subscribers informed about any property change or singal emited in SimpleArrayInterface
    std::vector<std::reference_wrapper<ISimpleArrayInterfaceSubscriber>> m_allChangesSubscribers;
    // Next free unique identifier to subscribe for the PropBool change.
    long m_propBoolChangedCallbackNextId = 0;
    // Subscribed callbacks for the PropBool change.
    std::map<long, SimpleArrayInterfacePropBoolPropertyCb> m_propBoolCallbacks;
    // Next free unique identifier to subscribe for the PropInt change.
    long m_propIntChangedCallbackNextId = 0;
    // Subscribed callbacks for the PropInt change.
    std::map<long, SimpleArrayInterfacePropIntPropertyCb> m_propIntCallbacks;
    // Next free unique identifier to subscribe for the PropFloat change.
    long m_propFloatChangedCallbackNextId = 0;
    // Subscribed callbacks for the PropFloat change.
    std::map<long, SimpleArrayInterfacePropFloatPropertyCb> m_propFloatCallbacks;
    // Next free unique identifier to subscribe for the PropString change.
    long m_propStringChangedCallbackNextId = 0;
    // Subscribed callbacks for the PropString change.
    std::map<long, SimpleArrayInterfacePropStringPropertyCb> m_propStringCallbacks;
    // Next free unique identifier to subscribe for the SigBool emission.
    long m_sigBoolSignalCallbackNextId = 0;
    // Subscribed callbacks for the SigBool emission.
    std::map<long, SimpleArrayInterfaceSigBoolSignalCb > m_sigBoolCallbacks;
    // Next free unique identifier to subscribe for the SigInt emission.
    long m_sigIntSignalCallbackNextId = 0;
    // Subscribed callbacks for the SigInt emission.
    std::map<long, SimpleArrayInterfaceSigIntSignalCb > m_sigIntCallbacks;
    // Next free unique identifier to subscribe for the SigFloat emission.
    long m_sigFloatSignalCallbackNextId = 0;
    // Subscribed callbacks for the SigFloat emission.
    std::map<long, SimpleArrayInterfaceSigFloatSignalCb > m_sigFloatCallbacks;
    // Next free unique identifier to subscribe for the SigString emission.
    long m_sigStringSignalCallbackNextId = 0;
    // Subscribed callbacks for the SigString emission.
    std::map<long, SimpleArrayInterfaceSigStringSignalCb > m_sigStringCallbacks;
};

} // namespace TbSimple
} // namespace Test
