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

//!
//! \class SIR
//! \brief SIR algorithm
//!
//! This implementation is inspired from the paper or Isard and al.
//! "conditionnal density propagation for visual tracking"
//! It is actually the Condensation version of the SIR algorithm.
//!

template <class Particle, class Viewer>
class SIR : public _Filter<Particle, Viewer>
{
    public:
		//!
		//! \fn SIR(int nbParticles)
		//! \brief Constructor
		//! \param nbParticles Number of particles used during filtering
		//!
        SIR(int nbParticles);

		//!
		//! \fn ~SIR()
		//! \brief Destructor
		//!
        ~SIR();

		//!
		//! \fn virtual void init(_Observation& observation)
		//! \brief filter initialisation
		//! \param observation Observation model
		//!
		//! Call init from _Filter class and initiate detector, sample particles from prior law.
		//!
		virtual void init(_Observation& observation);

		//!
		//! \fn virtual void update(_Observation& observation)
		//! \brief update of filter's state
		//! \param observation Observation model
		//!
		//! Call functions :
		//!  - step()
		//!  - updateWeights()
		//!  - calcNeff()
		//!  - computeMMSE()
		//!  - resample() (if needed)
		//!
		virtual void update(_Observation& observation);

		//!
		//! \fn virtual void update(_Observation& observation, Viewer& viewer)
		//! \brief update of filter's state
		//! \param observation Observation model
		//! \param viewer Filter's viewer
		//!
		//! It's mainly the same function as virtual void update(_Observation& observation)
		//! Call viewer functions
		//!
		virtual void update(_Observation& observation, Viewer& viewer);

		//!
		//! \fn virtual void step()
		//! \brief update particles
		//!
		//! Sample new particles from dynamic.
		//!
		virtual void step();
};

#include "SIR.tpp"

#endif // SIR_H
