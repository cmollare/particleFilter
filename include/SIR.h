//!
//! \file SIR.h
//! \brief ICondensation particle filter
//! \author Christophe Mollaret
//! \date June 2013
//!
//! This implementation is inspired from the paper or Isard and al.
//! "conditionnal density propagation for visual tracking"
//! It is actually the Condensation version of the SIR algorithm.
//!


#ifndef SIR_H
#define SIR_H

#include "_Filter.h"
#include "_Viewer.h"

template <class Particle, class Viewer>
class SIR : public _Filter<Particle, Viewer>
{
    public:
        SIR(int nbParticles);
        ~SIR();

		virtual void init(_Observation& observation);
		virtual void update(_Observation& observation);
		virtual void update(_Observation& observation, Viewer& viewer);
		virtual void step();
};

#include "SIR.tpp"

#endif // SIR_H
