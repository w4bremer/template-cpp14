
#pragma once
#include "tb_simple/generated/api/tb_simple.h"
#include "tb_simple/generated/api/common.h"
#include <memory>

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace TbSimple {

class NoOperationsInterfaceTracer;

class TEST_TB_SIMPLE_EXPORT NoOperationsInterfaceTraceDecorator : public INoOperationsInterface, public INoOperationsInterfaceSubscriber
{
protected:
    /** 
    * ctor
    * Subscribes for signal emission.
    * @param impl The NoOperationsInterface object to trace.
    * @param tracer A Poco tracer to which traces are put, wrapped with relevant object info.
    */
    explicit NoOperationsInterfaceTraceDecorator(INoOperationsInterface& impl, ApiGear::PocoImpl::Tracer& tracer);
public:
    /** 
    * Use this function to get the NoOperationsInterfaceTraceDecorator object.
    * @param impl The NoOperationsInterface object to trace.
    * @param tracer A Poco tracer to which traces are put, wrapped with relevant object info.
    */
    static std::unique_ptr<NoOperationsInterfaceTraceDecorator> connect(INoOperationsInterface& impl, ApiGear::PocoImpl::Tracer& tracer);
    /**
    * dtor
    * Unsubscribes from signal emission.
    */
    virtual ~NoOperationsInterfaceTraceDecorator();

    /** Forwards call to NoOperationsInterface implementation. */
    void setPropBool(bool propBool) override;
    /** Forwards call to NoOperationsInterface implementation. */
    bool getPropBool() const override;
    
    /** Forwards call to NoOperationsInterface implementation. */
    void setPropInt(int propInt) override;
    /** Forwards call to NoOperationsInterface implementation. */
    int getPropInt() const override;
    
    /**
    Traces sigVoid emission.
    */
    void onSigVoid() override;
    /**
    Traces sigBool emission.
    */
    void onSigBool(bool paramBool) override;
    /**
    Traces propBool changed.
    */
    void onPropBoolChanged(bool propBool) override;
    /**
    Traces propInt changed.
    */
    void onPropIntChanged(int propInt) override;

    /**
    * Access to a publisher, use it to subscribe for NoOperationsInterface changes and signal emission.
    * @return The publisher for NoOperationsInterface.
    */
    INoOperationsInterfacePublisher& _getPublisher() const override;
private:
    /** A tracer that provides the traces for given NoOperationsInterface object. */
    std::unique_ptr<NoOperationsInterfaceTracer> m_tracer;
    /** The NoOperationsInterface object which is traced */
    INoOperationsInterface& m_impl;
};
} // namespace TbSimple
} // namespace Test
