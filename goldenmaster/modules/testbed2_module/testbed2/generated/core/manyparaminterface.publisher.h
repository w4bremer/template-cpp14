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
#include "testbed2/generated/api/datastructs.api.h"
#include "testbed2/generated/api/manyparaminterface.api.h"
#include "testbed2/generated/api/common.h"

namespace Test {
namespace Testbed2 {
/**
 * Implementation ManyParamInterfacePublisher
 */
class TEST_TESTBED2_EXPORT ManyParamInterfacePublisher: public IManyParamInterfacePublisher
{
public:
    explicit ManyParamInterfacePublisher();
    virtual ~ManyParamInterfacePublisher();

    // ManyParamInterfacePublisher is not copyable
    ManyParamInterfacePublisher(const ManyParamInterfacePublisher& a) = delete;
    ManyParamInterfacePublisher& operator=(const ManyParamInterfacePublisher& a) = delete;
    // ManyParamInterfacePublisher is not movable
    ManyParamInterfacePublisher(ManyParamInterfacePublisher&& a) = delete;
    ManyParamInterfacePublisher& operator=(ManyParamInterfacePublisher&& a) = delete;

    void subscribeToManyParamInterfaceInterface(IManyParamInterfaceSubscriber& subscriber) override;
    void unsubscribeFromManyParamInterfaceInterface(IManyParamInterfaceSubscriber& subscriber) override;

    long subscribeToProp1Changed(ManyParamInterfaceProp1PropertyCb callback) override;
    void unsubscribeFromProp1Changed(long handleId) override;

    long subscribeToProp2Changed(ManyParamInterfaceProp2PropertyCb callback) override;
    void unsubscribeFromProp2Changed(long handleId) override;

    long subscribeToProp3Changed(ManyParamInterfaceProp3PropertyCb callback) override;
    void unsubscribeFromProp3Changed(long handleId) override;

    long subscribeToProp4Changed(ManyParamInterfaceProp4PropertyCb callback) override;
    void unsubscribeFromProp4Changed(long handleId) override;

    long subscribeToSig1(ManyParamInterfaceSig1SignalCb callback) override;
    void unsubscribeFromSig1(long handleId) override;

    long subscribeToSig2(ManyParamInterfaceSig2SignalCb callback) override;
    void unsubscribeFromSig2(long handleId) override;

    long subscribeToSig3(ManyParamInterfaceSig3SignalCb callback) override;
    void unsubscribeFromSig3(long handleId) override;

    long subscribeToSig4(ManyParamInterfaceSig4SignalCb callback) override;
    void unsubscribeFromSig4(long handleId) override;

    void publishSig1(int param1) const override;
    void publishSig2(int param1,int param2) const override;
    void publishSig3(int param1,int param2,int param3) const override;
    void publishSig4(int param1,int param2,int param3,int param4) const override;
protected:
    void publishProp1Changed(int prop1) const override;
    void publishProp2Changed(int prop2) const override;
    void publishProp3Changed(int prop3) const override;
    void publishProp4Changed(int prop4) const override;
private:
    std::shared_ptr<IManyParamInterfacePublisher> m_impl;
};

} // namespace Testbed2
} // namespace Test
