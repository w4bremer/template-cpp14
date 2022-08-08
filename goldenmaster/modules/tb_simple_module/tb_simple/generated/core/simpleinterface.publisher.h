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
#include "tb_simple/generated/api/datastructs.api.h"
#include "tb_simple/generated/api/simpleinterface.api.h"
#include "tb_simple/generated/api/common.h"

namespace Test {
namespace TbSimple {
/**
 * Implementation SimpleInterfacePublisher
 */
class TEST_TB_SIMPLE_EXPORT SimpleInterfacePublisher: public ISimpleInterfacePublisher
{
public:
    explicit SimpleInterfacePublisher();
    virtual ~SimpleInterfacePublisher();

    // SimpleInterfacePublisher is not copyable
    SimpleInterfacePublisher(const SimpleInterfacePublisher& a) = delete;
    SimpleInterfacePublisher& operator=(const SimpleInterfacePublisher& a) = delete;
    // SimpleInterfacePublisher is not movable
    SimpleInterfacePublisher(SimpleInterfacePublisher&& a) = delete;
    SimpleInterfacePublisher& operator=(SimpleInterfacePublisher&& a) = delete;

    void subscribeToSimpleInterfaceInterface(ISimpleInterfaceSubscriber& subscriber) override;
    void unsubscribeFromSimpleInterfaceInterface(ISimpleInterfaceSubscriber& subscriber) override;

    long subscribeToPropBoolChanged(SimpleInterfacePropBoolPropertyCb callback) override;
    void unsubscribeFromPropBoolChanged(long handleId) override;

    long subscribeToPropIntChanged(SimpleInterfacePropIntPropertyCb callback) override;
    void unsubscribeFromPropIntChanged(long handleId) override;

    long subscribeToPropFloatChanged(SimpleInterfacePropFloatPropertyCb callback) override;
    void unsubscribeFromPropFloatChanged(long handleId) override;

    long subscribeToPropStringChanged(SimpleInterfacePropStringPropertyCb callback) override;
    void unsubscribeFromPropStringChanged(long handleId) override;

    long subscribeToSigBool(SimpleInterfaceSigBoolSignalCb callback) override;
    void unsubscribeFromSigBool(long handleId) override;

    long subscribeToSigInt(SimpleInterfaceSigIntSignalCb callback) override;
    void unsubscribeFromSigInt(long handleId) override;

    long subscribeToSigFloat(SimpleInterfaceSigFloatSignalCb callback) override;
    void unsubscribeFromSigFloat(long handleId) override;

    long subscribeToSigString(SimpleInterfaceSigStringSignalCb callback) override;
    void unsubscribeFromSigString(long handleId) override;

    void publishSigBool(bool paramBool) const override;
    void publishSigInt(int paramInt) const override;
    void publishSigFloat(float paramFloat) const override;
    void publishSigString(const std::string& paramString) const override;
protected:
    void publishPropBoolChanged(bool propBool) const override;
    void publishPropIntChanged(int propInt) const override;
    void publishPropFloatChanged(float propFloat) const override;
    void publishPropStringChanged(const std::string& propString) const override;
private:
    std::shared_ptr<ISimpleInterfacePublisher> m_impl;
};

} // namespace TbSimple
} // namespace Test
