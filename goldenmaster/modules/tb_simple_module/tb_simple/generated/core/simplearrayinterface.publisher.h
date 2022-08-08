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
#include "tb_simple/generated/api/simplearrayinterface.api.h"
#include "tb_simple/generated/api/common.h"

namespace Test {
namespace TbSimple {
/**
 * Implementation SimpleArrayInterfacePublisher
 */
class TEST_TB_SIMPLE_EXPORT SimpleArrayInterfacePublisher: public ISimpleArrayInterfacePublisher
{
public:
    explicit SimpleArrayInterfacePublisher();
    virtual ~SimpleArrayInterfacePublisher();

    // SimpleArrayInterfacePublisher is not copyable
    SimpleArrayInterfacePublisher(const SimpleArrayInterfacePublisher& a) = delete;
    SimpleArrayInterfacePublisher& operator=(const SimpleArrayInterfacePublisher& a) = delete;
    // SimpleArrayInterfacePublisher is not movable
    SimpleArrayInterfacePublisher(SimpleArrayInterfacePublisher&& a) = delete;
    SimpleArrayInterfacePublisher& operator=(SimpleArrayInterfacePublisher&& a) = delete;

    void subscribeToSimpleArrayInterfaceInterface(ISimpleArrayInterfaceSubscriber& subscriber) override;
    void unsubscribeFromSimpleArrayInterfaceInterface(ISimpleArrayInterfaceSubscriber& subscriber) override;

    long subscribeToPropBoolChanged(SimpleArrayInterfacePropBoolPropertyCb callback) override;
    void unsubscribeFromPropBoolChanged(long handleId) override;

    long subscribeToPropIntChanged(SimpleArrayInterfacePropIntPropertyCb callback) override;
    void unsubscribeFromPropIntChanged(long handleId) override;

    long subscribeToPropFloatChanged(SimpleArrayInterfacePropFloatPropertyCb callback) override;
    void unsubscribeFromPropFloatChanged(long handleId) override;

    long subscribeToPropStringChanged(SimpleArrayInterfacePropStringPropertyCb callback) override;
    void unsubscribeFromPropStringChanged(long handleId) override;

    long subscribeToSigBool(SimpleArrayInterfaceSigBoolSignalCb callback) override;
    void unsubscribeFromSigBool(long handleId) override;

    long subscribeToSigInt(SimpleArrayInterfaceSigIntSignalCb callback) override;
    void unsubscribeFromSigInt(long handleId) override;

    long subscribeToSigFloat(SimpleArrayInterfaceSigFloatSignalCb callback) override;
    void unsubscribeFromSigFloat(long handleId) override;

    long subscribeToSigString(SimpleArrayInterfaceSigStringSignalCb callback) override;
    void unsubscribeFromSigString(long handleId) override;

    void publishSigBool(const std::list<bool>& paramBool) const override;
    void publishSigInt(const std::list<int>& paramInt) const override;
    void publishSigFloat(const std::list<float>& paramFloat) const override;
    void publishSigString(const std::list<std::string>& paramString) const override;
protected:
    void publishPropBoolChanged(const std::list<bool>& propBool) const override;
    void publishPropIntChanged(const std::list<int>& propInt) const override;
    void publishPropFloatChanged(const std::list<float>& propFloat) const override;
    void publishPropStringChanged(const std::list<std::string>& propString) const override;
private:
    std::shared_ptr<ISimpleArrayInterfacePublisher> m_impl;
};

} // namespace TbSimple
} // namespace Test
