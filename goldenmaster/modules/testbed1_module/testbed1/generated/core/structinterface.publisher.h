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
#include "testbed1/generated/api/datastructs.api.h"
#include "testbed1/generated/api/structinterface.api.h"
#include "testbed1/generated/api/common.h"

namespace Test {
namespace Testbed1 {
/**
 * Implementation StructInterfacePublisher
 */
class TEST_TESTBED1_EXPORT StructInterfacePublisher: public IStructInterfacePublisher
{
public:
    explicit StructInterfacePublisher();
    virtual ~StructInterfacePublisher();

    // StructInterfacePublisher is not copyable
    StructInterfacePublisher(const StructInterfacePublisher& a) = delete;
    StructInterfacePublisher& operator=(const StructInterfacePublisher& a) = delete;
    // StructInterfacePublisher is not movable
    StructInterfacePublisher(StructInterfacePublisher&& a) = delete;
    StructInterfacePublisher& operator=(StructInterfacePublisher&& a) = delete;

    void subscribeToStructInterfaceInterface(IStructInterfaceSubscriber& subscriber) override;
    void unsubscribeFromStructInterfaceInterface(IStructInterfaceSubscriber& subscriber) override;

    long subscribeToPropBoolChanged(StructInterfacePropBoolPropertyCb callback) override;
    void unsubscribeFromPropBoolChanged(long handleId) override;

    long subscribeToPropIntChanged(StructInterfacePropIntPropertyCb callback) override;
    void unsubscribeFromPropIntChanged(long handleId) override;

    long subscribeToPropFloatChanged(StructInterfacePropFloatPropertyCb callback) override;
    void unsubscribeFromPropFloatChanged(long handleId) override;

    long subscribeToPropStringChanged(StructInterfacePropStringPropertyCb callback) override;
    void unsubscribeFromPropStringChanged(long handleId) override;

    long subscribeToSigBool(StructInterfaceSigBoolSignalCb callback) override;
    void unsubscribeFromSigBool(long handleId) override;

    long subscribeToSigInt(StructInterfaceSigIntSignalCb callback) override;
    void unsubscribeFromSigInt(long handleId) override;

    long subscribeToSigFloat(StructInterfaceSigFloatSignalCb callback) override;
    void unsubscribeFromSigFloat(long handleId) override;

    long subscribeToSigString(StructInterfaceSigStringSignalCb callback) override;
    void unsubscribeFromSigString(long handleId) override;

    void publishSigBool(const StructBool& paramBool) const override;
    void publishSigInt(const StructInt& paramInt) const override;
    void publishSigFloat(const StructFloat& paramFloat) const override;
    void publishSigString(const StructString& paramString) const override;
protected:
    void publishPropBoolChanged(const StructBool& propBool) const override;
    void publishPropIntChanged(const StructInt& propInt) const override;
    void publishPropFloatChanged(const StructFloat& propFloat) const override;
    void publishPropStringChanged(const StructString& propString) const override;
private:
    std::shared_ptr<IStructInterfacePublisher> m_impl;
};

} // namespace Testbed1
} // namespace Test
