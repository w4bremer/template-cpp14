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
#include "testbed1/generated/api/structarrayinterface.api.h"
#include "testbed1/generated/api/common.h"

namespace Test {
namespace Testbed1 {
/**
 * Implementation StructArrayInterfacePublisher
 */
class TEST_TESTBED1_EXPORT StructArrayInterfacePublisher: public IStructArrayInterfacePublisher
{
public:
    explicit StructArrayInterfacePublisher();
    virtual ~StructArrayInterfacePublisher();

    // StructArrayInterfacePublisher is not copyable
    StructArrayInterfacePublisher(const StructArrayInterfacePublisher& a) = delete;
    StructArrayInterfacePublisher& operator=(const StructArrayInterfacePublisher& a) = delete;
    // StructArrayInterfacePublisher is not movable
    StructArrayInterfacePublisher(StructArrayInterfacePublisher&& a) = delete;
    StructArrayInterfacePublisher& operator=(StructArrayInterfacePublisher&& a) = delete;

    void subscribeToStructArrayInterfaceInterface(IStructArrayInterfaceSubscriber& subscriber) override;
    void unsubscribeFromStructArrayInterfaceInterface(IStructArrayInterfaceSubscriber& subscriber) override;

    long subscribeToPropBoolChanged(StructArrayInterfacePropBoolPropertyCb callback) override;
    void unsubscribeFromPropBoolChanged(long handleId) override;

    long subscribeToPropIntChanged(StructArrayInterfacePropIntPropertyCb callback) override;
    void unsubscribeFromPropIntChanged(long handleId) override;

    long subscribeToPropFloatChanged(StructArrayInterfacePropFloatPropertyCb callback) override;
    void unsubscribeFromPropFloatChanged(long handleId) override;

    long subscribeToPropStringChanged(StructArrayInterfacePropStringPropertyCb callback) override;
    void unsubscribeFromPropStringChanged(long handleId) override;

    long subscribeToSigBool(StructArrayInterfaceSigBoolSignalCb callback) override;
    void unsubscribeFromSigBool(long handleId) override;

    long subscribeToSigInt(StructArrayInterfaceSigIntSignalCb callback) override;
    void unsubscribeFromSigInt(long handleId) override;

    long subscribeToSigFloat(StructArrayInterfaceSigFloatSignalCb callback) override;
    void unsubscribeFromSigFloat(long handleId) override;

    long subscribeToSigString(StructArrayInterfaceSigStringSignalCb callback) override;
    void unsubscribeFromSigString(long handleId) override;

    void publishSigBool(const std::list<StructBool>& paramBool) const override;
    void publishSigInt(const std::list<StructInt>& paramInt) const override;
    void publishSigFloat(const std::list<StructFloat>& paramFloat) const override;
    void publishSigString(const std::list<StructString>& paramString) const override;
protected:
    void publishPropBoolChanged(const std::list<StructBool>& propBool) const override;
    void publishPropIntChanged(const std::list<StructInt>& propInt) const override;
    void publishPropFloatChanged(const std::list<StructFloat>& propFloat) const override;
    void publishPropStringChanged(const std::list<StructString>& propString) const override;
private:
    std::shared_ptr<IStructArrayInterfacePublisher> m_impl;
};

} // namespace Testbed1
} // namespace Test
