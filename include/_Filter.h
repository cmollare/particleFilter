//!
//! \file _Filter.h
//! \brief Abstract class for particle filter
//! \author Christophe Mollaret
//! \date June 2013
//!
//! If you have to implement a new filter, derive this class.
//!

#ifndef FILTER_H
#define FILTER_H

#include <vector>
#include <boost/random.hpp>
#include "_Observation.h"
#include "_Viewer.h"
#include "FilterEnv.h"

//!
//! \class _Filter
//! \brief Abstract class for particle filter
//!
//! If you have to implement a new filter, derive this class.
//!

template <class Particle, class Viewer>
class _Filter
{
	public:

		//!
		//! \fn _Filter(int nbPaticles)
		//! \brief Constructor
		//! \param nbParticles the number of particles used for filtering
		//!
		_Filter(int nbParticles);

		//!
		//! \fn ~_Filter()
		//! \brief Destructor
		//!
		~_Filter();

		//!
		//! \fn virtual void init(_Observation& observation)
		//! \brief filter initialisation
		//! \param observation Observation model
		//!
		//! Init weights, particles, and sample particles from prior law.
		//!
		virtual void init(_Observation& observation);

		//!
		//! \fn virtual void update(_Observation& observation)=0
		//! \brief update of filter's state
		//! \param observation Observation model
		//!
		//! Abstract function to implement in derived class. This function is meant to update filter's state.
		//!
		virtual void update(_Observation& observation)=0;

		//!
		//! \fn virtual void update(_Observation& observation, Viewer& viewer)=0
		//! \brief update of filter's state
		//! \param observation Observation model
		//! \param viewer Filter's viewer
		//!
		//! It's mainly the same function as virtual void update(_Observation& observation)=0, but meant to include observation class if you need to see something.
		//!
		virtual void update(_Observation& observation, Viewer& viewer)=0;

		//!
		//! \fn virtual void step()=0
		//! \brief update particles
		//!
		//! Abstract class meant to sample particles' next state.
		//!
		virtual void step()=0;

		//!
		//! \fn virtual void updateWeights(_Observation& observation)
		//! \brief update weights of particles
		//! \param observation Observation model
		//!
		//! This function updates particles' weights and weights cumulative distribution function (for resampling)
		//!
		virtual void updateWeights(_Observation& observation);

		//!
		//! \fn virtual void resample()
		//! \brief resampling function
		//!
		//! Resample particles function of weights. Use the importance sampling algorithm.
		//!
		virtual void resample();

		//!
		//! \fn virtual void computeMMSE()
		//! \brief Compute filter MMSE estimate
		//!
		//! Compute the MMSE estimate of the filter
		//!
		virtual void computeMMSE();

		//!
		//! \fn virtual void calcNeff()
		//! \brief Compute Neff
		//!
		//! Compute the number of efficient particles (to avoid degenerecency).
		//!
		virtual void calcNeff();

		//!
		//! \fn inline std::vector<Particle*>& getParticleVector()
		//! \brief Getter
		//! \return Vector of particles
		//! \return all particles of the filter
		//!
		inline std::vector<Particle*>& getParticleVector()
		{
			return _vParticles;
		}

		//!
		//! \fn inline std::vector<double>& getWeightVector()
		//! \brief Getter
		//! \return all weights associated to particles
		//!
		inline std::vector<double>& getWeightVector()
		{
			return _vWeights;
		}

		//!
		//! \fn inline Particle* getParticleMMSE()
		//! \brief Getter
		//! \return MMSE estimate
		//!
		inline Particle* getParticleMMSE()
		{
			return _mmseParticle;
		}

	protected:
		FilterEnv* _pFilterEnv; //!< Pointer on FilterEnv class

		std::vector<Particle*> _vParticles; //!< Vector of particles used for filtering
		Particle* _mmseParticle; //!< MMSE estimate of the filter
		int _nbParticles; //!< Number of particles == _vParticles.size()

		std::vector<double> _vWeights; //!< Vector of weights used for filtering
		std::vector<double> _cdf; //!< cdf used for resampling
		double _weightNorm; //!< Used for weights normalisation

		double _Neff; //!< Number of efficient particles
		double _Ns; //!< Threshold to launch resampling
};

#include "_Filter.tpp"

#endif
