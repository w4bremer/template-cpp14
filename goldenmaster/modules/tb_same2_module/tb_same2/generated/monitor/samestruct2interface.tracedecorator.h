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
#include "tb_same2/generated/api/tb_same2.h"
#include "tb_same2/generated/api/common.h"
#include <memory>

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace TbSame2 {

class SameStruct2InterfaceTracer;

class TEST_TB_SAME2_EXPORT SameStruct2InterfaceTraceDecorator : public ISameStruct2Interface, public ISameStruct2InterfaceSubscriber
{
protected:
    /** 
    * ctor
    * Subscribes for singal emmission.
    * @param impl The SameStruct2Interface object to trace.
    * @param tracer A Poco tracer to which traces are put, wrapped with relevant object info.
    */
    explicit SameStruct2InterfaceTraceDecorator(ISameStruct2Interface& impl, ApiGear::PocoImpl::Tracer& tracer);
public:
    /** 
    * Use this function to get the SameStruct2InterfaceTraceDecorator object.
    * @param impl The SameStruct2Interface object to trace.
    * @param tracer A Poco tracer to which traces are put, wrapped with relevant object info.
    */
    static std::unique_ptr<SameStruct2InterfaceTraceDecorator> connect(ISameStruct2Interface& impl, ApiGear::PocoImpl::Tracer& tracer);
    /**
    * dtor
    * Unsubscribes from signal emision.
    */
    virtual ~SameStruct2InterfaceTraceDecorator();

    /** Traces func1 and forwards call to SameStruct2Interface implementation. */
    Struct1 func1(const Struct1& param1) override;
    /** Traces func1 and forwards call to SameStruct2Interface implementation. */
    std::future<Struct1> func1Async(const Struct1& param1) override;
    
    /** Traces func2 and forwards call to SameStruct2Interface implementation. */
    Struct1 func2(const Struct1& param1, const Struct2& param2) override;
    /** Traces func2 and forwards call to SameStruct2Interface implementation. */
    std::future<Struct1> func2Async(const Struct1& param1, const Struct2& param2) override;
    
    /** Forwards call to SameStruct2Interface implementation. */
    void setProp1(const Struct2& prop1) override;
    /** Forwards call to SameStruct2Interface implementation. */
    const Struct2& prop1() const override;
    
    /** Forwards call to SameStruct2Interface implementation. */
    void setProp2(const Struct2& prop2) override;
    /** Forwards call to SameStruct2Interface implementation. */
    const Struct2& prop2() const override;
    
    /**
    Traces sig1 emission.
    */
    void onSig1(const Struct1& param1) override;
    /**
    Traces sig2 emission.
    */
    void onSig2(const Struct1& param1,const Struct2& param2) override;
    /**
    Traces prop1 changed.
    */
    void onProp1Changed(const Struct2& prop1) override;
    /**
    Traces prop2 changed.
    */
    void onProp2Changed(const Struct2& prop2) override;

    /**
    * Access to a publisher, use it to subscribe for SameStruct2Interface changes and signal emission.
    * @return The publisher for SameStruct2Interface.
    */
    ISameStruct2InterfacePublisher& _getPublisher() const override;
private:
    /** A tracer that provides the traces for given SameStruct2Interface object. */
    std::unique_ptr<SameStruct2InterfaceTracer> m_tracer;
    /** The SameStruct2Interface object which is traced */
    ISameStruct2Interface& m_impl;
};
} // namespace TbSame2
} // namespace Test
