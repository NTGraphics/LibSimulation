//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
//    .--------------------------------------------------.
//    |  This file is part of NTCodeBase                 |
//    |  Created 2018 by NT (https://ttnghia.github.io)  |
//    '--------------------------------------------------'
//                            \o/
//                             |
//                            / |
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

#pragma once
#include <LibSimulation/SimulationObjects/SimulationObject.h>

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
namespace SimulationObjects {
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
template<Int N, class Real_t>
class ParticleGenerator : public SimulationObject<N, Real_t> {
    ////////////////////////////////////////////////////////////////////////////////
    __NT_TYPE_ALIAS __NT_DECLARE_PARTICLE_SOLVER_ACCESSORS
    ////////////////////////////////////////////////////////////////////////////////
public:
    ParticleGenerator() = delete;
    ParticleGenerator(const String& desc_, const JParams& jParams_, const SharedPtr<Logger>& logger_,
                      ParameterManager& parameterManager_, PropertyManager& propertyManager_) :
        SimulationObject<N, Real_t>(desc_, jParams_, logger_, parameterManager_, propertyManager_) { initializeParameters(jParams_); }
    ////////////////////////////////////////////////////////////////////////////////
    virtual void initializeParameters(const JParams& jParams) override;
    virtual UInt generateParticles(PropertyGroup& propertyGroup, StdVT<SharedPtr<SimulationObject<N, Real_t>>>& otherObjects,
                                   bool bIgnoreOverlapped = false) override;

protected:
    StdVT_VecN generateParticles(StdVT<SharedPtr<SimulationObject<N, Real_t>>>& otherObjects, bool bIgnoreOverlapped = false);
    ////////////////////////////////////////////////////////////////////////////////
    Real_t m_MaterialDensity = Real_t(1000);
    Real_t m_ParticleMass    = Real_t(0);
    Real_t m_JitterRatio     = Real_t(0);
    VecN   m_SamplingRatio   = VecN(1.0);
    VecN   m_v0 = VecN(0);
    bool   m_bCrashIfNoParticle = true;
};

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
} // end namespace SimulationObjects
