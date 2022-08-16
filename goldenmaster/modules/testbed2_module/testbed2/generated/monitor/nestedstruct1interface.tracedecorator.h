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
#include "testbed2/generated/api/testbed2.h"
#include "testbed2/generated/api/common.h"
#include <memory>

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace Testbed2 {

class NestedStruct1InterfaceTracer;

class TEST_TESTBED2_EXPORT NestedStruct1InterfaceTraceDecorator : public INestedStruct1Interface, public INestedStruct1InterfaceSubscriber
{
protected:
    /** 
    * ctor
    * Subscribes for singal emmission.
    * @param impl The NestedStruct1Interface object to trace.
    * @param tracer A Poco tracer to which traces are put, wrapped with relevant object info.
    */
    explicit NestedStruct1InterfaceTraceDecorator(INestedStruct1Interface& impl, ApiGear::PocoImpl::Tracer& tracer);
public:
    /** 
    * Use this function to get the NestedStruct1InterfaceTraceDecorator object.
    * @param impl The NestedStruct1Interface object to trace.
    * @param tracer A Poco tracer to which traces are put, wrapped with relevant object info.
    */
    static std::unique_ptr<NestedStruct1InterfaceTraceDecorator> connect(INestedStruct1Interface& impl, ApiGear::PocoImpl::Tracer& tracer);
    /**
    * dtor
    * Unsubscribes from signal emision.
    */
    virtual ~NestedStruct1InterfaceTraceDecorator();

    /** Traces func1 and forwards call to NestedStruct1Interface implementation. */
    NestedStruct1 func1(const NestedStruct1& param1) override;
    /** Traces func1 and forwards call to NestedStruct1Interface implementation. */
    std::future<NestedStruct1> func1Async(const NestedStruct1& param1) override;
    
    /** Forwards call to NestedStruct1Interface implementation. */
    void setProp1(const NestedStruct1& prop1) override;
    /** Forwards call to NestedStruct1Interface implementation. */
    const NestedStruct1& prop1() const override;
    
    /**
    Traces sig1 emission.
    */
    void onSig1(const NestedStruct1& param1) override;
    /**
    Traces prop1 changed.
    */
    void onProp1Changed(const NestedStruct1& prop1) override;

    /**
    * Access to a publisher, use it to subscribe for NestedStruct1Interface changes and signal emission.
    * @return The publisher for NestedStruct1Interface.
    */
    INestedStruct1InterfacePublisher& _getPublisher() const override;
private:
    /** A tracer that provides the traces for given NestedStruct1Interface object. */
    std::unique_ptr<NestedStruct1InterfaceTracer> m_tracer;
    /** The NestedStruct1Interface object which is traced */
    INestedStruct1Interface& m_impl;
};
} // namespace Testbed2
} // namespace Test
