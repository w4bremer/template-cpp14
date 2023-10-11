
#pragma once
#include "tb_names/generated/api/tb_names.h"
#include "tb_names/generated/api/common.h"
#include <memory>

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace TbNames {

class NamesTracer;

class TEST_TB_NAMES_EXPORT NamesTraceDecorator : public INames, public INamesSubscriber
{
protected:
    /** 
    * ctor
    * Subscribes for signal emission.
    * @param impl The Names object to trace.
    * @param tracer A Poco tracer to which traces are put, wrapped with relevant object info.
    */
    explicit NamesTraceDecorator(INames& impl, ApiGear::PocoImpl::Tracer& tracer);
public:
    /** 
    * Use this function to get the NamesTraceDecorator object.
    * @param impl The Names object to trace.
    * @param tracer A Poco tracer to which traces are put, wrapped with relevant object info.
    */
    static std::unique_ptr<NamesTraceDecorator> connect(INames& impl, ApiGear::PocoImpl::Tracer& tracer);
    /**
    * dtor
    * Unsubscribes from signal emission.
    */
    virtual ~NamesTraceDecorator();

    /** Forwards call to Names implementation. */
    void setSwitch(bool Switch) override;
    /** Forwards call to Names implementation. */
    bool getSwitch() const override;
    
    /**
    Traces Switch changed.
    */
    void onSwitchChanged(bool Switch) override;

    /**
    * Access to a publisher, use it to subscribe for Names changes and signal emission.
    * @return The publisher for Names.
    */
    INamesPublisher& _getPublisher() const override;
private:
    /** A tracer that provides the traces for given Names object. */
    std::unique_ptr<NamesTracer> m_tracer;
    /** The Names object which is traced */
    INames& m_impl;
};
} // namespace TbNames
} // namespace Test
