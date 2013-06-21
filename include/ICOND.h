//!
//! \file ICOND.h
//! \brief ICondensation particle filter
//! \author Christophe Mollaret
//! \date June 2013
//!
//! This implementation is inspired from the paper or Isard and al.\n
//! "unifying low-level and high-level tracking in a stochastic framework"
//!

#ifndef ICOND_H
#define ICOND_H

#include "_Filter.h"

//!
//! \class ICOND
//! \brief ICONDensation algorithm
//!
//! This implementation is inspired from the paper or Isard and al.\n
//! "unifying low-level and high-level tracking in a stochastic framework"\n
//!

template<class Particle, class Detector, class Viewer>
class ICOND : public _Filter<Particle, Viewer>
{
    public:
		//!
		//! \fn ICOND(int nbParticles, double q, double r)
		//! \brief Constructor
		//! \param nbParticles Number of particles used during filtering
		//! \param q Prior percentage during update
		//! \param r Importance sampling (detector) percentage used during filtering
		//!
		ICOND(int nbParticles, double q, double r); //q = prior percent, r = importance sampling percent, dynamics = 1-q-r

		//!
		//! \fn ICOND(Detector* detector, int nbParticles, double q, double r)
		//! \brief Constructor
		//! \param detector pointer on Detector instance
		//! \param nbParticles Number of particles used during filtering
		//! \param q Prior percentage during update
		//! \param r Importance sampling (detector) percentage used during filtering
		//!
		//! Constructor used if detector instanciation has to be exterior from the class.
		//! This instance won't be destroyed inside the class.
		//!
		ICOND(Detector* detector, int nbParticles, double q, double r);

		//!
		//! \fn ~ICOND()
		//! \brief Destructor
		//!
		~ICOND();

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
		//! \fn virtual void updateWeights(_Observation& observation)
		//! \brief update weights of particles
		//! \param observation Observation model
		//!
		//! This function updates particles' weights and weights cumulative distribution function (for resampling)
		//!
		virtual void updateWeights(_Observation& observation);

		//!
		//! \fn virtual void step()
		//! \brief update particles
		//!
		//! Sample new particles from prior, importance function and dynamic.
		//!
		virtual void step();

    protected:
		double _q; //!< Percentage of prior sampling
		double _r; //!< Percentage of importance sampling
		std::vector<double> _vLambda; //!< Weight factor
		Detector* _detector; //!< pointer on detector

		bool _isDetectorAllocated; //!< If detector has been allocated in class or outside
};

#include "ICOND.tpp"

#endif // ICOND_H
