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
#include "tb_same1/generated/api/tb_same1.h"
#include "tb_same1/generated/api/common.h"
#include <memory>

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace TbSame1 {

class SameEnum1InterfaceTracer;

class TEST_TB_SAME1_EXPORT SameEnum1InterfaceTraceDecorator : public ISameEnum1Interface, public ISameEnum1InterfaceSubscriber
{
protected:
    /** 
    * ctor
    * Subscribes for singal emmission.
    * @param impl The SameEnum1Interface object to trace.
    * @param tracer A Poco tracer to which traces are put, wrapped with relevant object info.
    */
    explicit SameEnum1InterfaceTraceDecorator(ISameEnum1Interface& impl, ApiGear::PocoImpl::Tracer& tracer);
public:
    /** 
    * Use this function to get the SameEnum1InterfaceTraceDecorator object.
    * @param impl The SameEnum1Interface object to trace.
    * @param tracer A Poco tracer to which traces are put, wrapped with relevant object info.
    */
    static std::unique_ptr<SameEnum1InterfaceTraceDecorator> connect(ISameEnum1Interface& impl, ApiGear::PocoImpl::Tracer& tracer);
    /**
    * dtor
    * Unsubscribes from signal emision.
    */
    virtual ~SameEnum1InterfaceTraceDecorator();

    /** Traces func1 and forwards call to SameEnum1Interface implementation. */
    Enum1Enum func1(const Enum1Enum& param1) override;
    /** Traces func1 and forwards call to SameEnum1Interface implementation. */
    std::future<Enum1Enum> func1Async(const Enum1Enum& param1) override;
    
    /** Forwards call to SameEnum1Interface implementation. */
    void setProp1(const Enum1Enum& prop1) override;
    /** Forwards call to SameEnum1Interface implementation. */
    const Enum1Enum& prop1() const override;
    
    /**
    Traces sig1 emission.
    */
    void onSig1(const Enum1Enum& param1) override;
    /**
    Traces prop1 changed.
    */
    void onProp1Changed(const Enum1Enum& prop1) override;

    /**
    * Access to a publisher, use it to subscribe for SameEnum1Interface changes and signal emission.
    * @return The publisher for SameEnum1Interface.
    */
    ISameEnum1InterfacePublisher& _getPublisher() const override;
private:
    /** A tracer that provides the traces for given SameEnum1Interface object. */
    std::unique_ptr<SameEnum1InterfaceTracer> m_tracer;
    /** The SameEnum1Interface object which is traced */
    ISameEnum1Interface& m_impl;
};
} // namespace TbSame1
} // namespace Test
