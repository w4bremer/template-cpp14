
#pragma once
#include "tb_enum/generated/api/tb_enum.h"
#include "tb_enum/generated/api/common.h"
#include <memory>

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace TbEnum {

class EnumInterfaceTracer;

class TEST_TB_ENUM_EXPORT EnumInterfaceTraceDecorator : public IEnumInterface, public IEnumInterfaceSubscriber
{
protected:
    /** 
    * ctor
    * Subscribes for singal emmission.
    * @param impl The EnumInterface object to trace.
    * @param tracer A Poco tracer to which traces are put, wrapped with relevant object info.
    */
    explicit EnumInterfaceTraceDecorator(IEnumInterface& impl, ApiGear::PocoImpl::Tracer& tracer);
public:
    /** 
    * Use this function to get the EnumInterfaceTraceDecorator object.
    * @param impl The EnumInterface object to trace.
    * @param tracer A Poco tracer to which traces are put, wrapped with relevant object info.
    */
    static std::unique_ptr<EnumInterfaceTraceDecorator> connect(IEnumInterface& impl, ApiGear::PocoImpl::Tracer& tracer);
    /**
    * dtor
    * Unsubscribes from signal emision.
    */
    virtual ~EnumInterfaceTraceDecorator();

    /** Traces func0 and forwards call to EnumInterface implementation. */
    Enum0Enum func0(const Enum0Enum& param0) override;
    /** Traces func0 and forwards call to EnumInterface implementation. */
    std::future<Enum0Enum> func0Async(const Enum0Enum& param0) override;
    
    /** Traces func1 and forwards call to EnumInterface implementation. */
    Enum1Enum func1(const Enum1Enum& param1) override;
    /** Traces func1 and forwards call to EnumInterface implementation. */
    std::future<Enum1Enum> func1Async(const Enum1Enum& param1) override;
    
    /** Traces func2 and forwards call to EnumInterface implementation. */
    Enum2Enum func2(const Enum2Enum& param2) override;
    /** Traces func2 and forwards call to EnumInterface implementation. */
    std::future<Enum2Enum> func2Async(const Enum2Enum& param2) override;
    
    /** Traces func3 and forwards call to EnumInterface implementation. */
    Enum3Enum func3(const Enum3Enum& param3) override;
    /** Traces func3 and forwards call to EnumInterface implementation. */
    std::future<Enum3Enum> func3Async(const Enum3Enum& param3) override;
    
    /** Forwards call to EnumInterface implementation. */
    void setProp0(const Enum0Enum& prop0) override;
    /** Forwards call to EnumInterface implementation. */
    const Enum0Enum& getProp0() const override;
    
    /** Forwards call to EnumInterface implementation. */
    void setProp1(const Enum1Enum& prop1) override;
    /** Forwards call to EnumInterface implementation. */
    const Enum1Enum& getProp1() const override;
    
    /** Forwards call to EnumInterface implementation. */
    void setProp2(const Enum2Enum& prop2) override;
    /** Forwards call to EnumInterface implementation. */
    const Enum2Enum& getProp2() const override;
    
    /** Forwards call to EnumInterface implementation. */
    void setProp3(const Enum3Enum& prop3) override;
    /** Forwards call to EnumInterface implementation. */
    const Enum3Enum& getProp3() const override;
    
    /**
    Traces sig0 emission.
    */
    void onSig0(const Enum0Enum& param0) override;
    /**
    Traces sig1 emission.
    */
    void onSig1(const Enum1Enum& param1) override;
    /**
    Traces sig2 emission.
    */
    void onSig2(const Enum2Enum& param2) override;
    /**
    Traces sig3 emission.
    */
    void onSig3(const Enum3Enum& param3) override;
    /**
    Traces prop0 changed.
    */
    void onProp0Changed(const Enum0Enum& prop0) override;
    /**
    Traces prop1 changed.
    */
    void onProp1Changed(const Enum1Enum& prop1) override;
    /**
    Traces prop2 changed.
    */
    void onProp2Changed(const Enum2Enum& prop2) override;
    /**
    Traces prop3 changed.
    */
    void onProp3Changed(const Enum3Enum& prop3) override;

    /**
    * Access to a publisher, use it to subscribe for EnumInterface changes and signal emission.
    * @return The publisher for EnumInterface.
    */
    IEnumInterfacePublisher& _getPublisher() const override;
private:
    /** A tracer that provides the traces for given EnumInterface object. */
    std::unique_ptr<EnumInterfaceTracer> m_tracer;
    /** The EnumInterface object which is traced */
    IEnumInterface& m_impl;
};
} // namespace TbEnum
} // namespace Test
