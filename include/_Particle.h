//!
//! \file _Particle.h
//! \brief Abstract class for particle (state vector)
//! \author Christophe Mollaret
//! \date June 2013
//!
//! To create your own particle, derive this class
//!

#ifndef PARTICLE_H
#define PARTICLE_H

//!
//! \def PI
//! \brief pi constant
//!
#define PI 3.14159265359

#include <vector>
#include <boost/random.hpp>
#include "FilterEnv.h"

//!
//! \class _Particle
//! \brief Abstract class for particles
//!
//! To create your own particle, derive this class
//!
class _Particle
{
    public:

		//!
		//! \fn _Particle(FilterEnv* pFilterEnv)
		//! \brief Constructor
		//! \param pFilterEnv Pointer to FilterEnv class
		//!
		_Particle(FilterEnv* pFilterEnv);

		//!
		//! \fn virtual void sampleFromPrior()=0
		//! \brief Function to sample a particle from prior law
		//!
		virtual void sampleFromPrior()=0;

		//!
		//! \fn virtual void sampleFromDynamic()=0
		//! \brief Function to sample a particle from dynamic model
		//!
		virtual void sampleFromDynamic()=0;

		//!
		//! \fn virtual void sampleFromDetector(std::vector<double>& detection)=0
		//! \brief Function to sample a particle from detection
		//! \param detection State vector of detection
		//!
		virtual void sampleFromDetector(std::vector<double>& detection)=0;

		//!
		//! \fn virtual double evaluateFromDynamic()=0
		//! \brief evaluate sample from dynamic distribution
		//!
		virtual double evaluateFromDynamic()=0;

		//!
		//! \fn virtual double evaluateFromDetector()=0
		//! \brief evaluate sample from detector distribution
		//!
		virtual double evaluateFromDetector()=0;

		//!
		//! \fn virtual double evaluateFromPrior()=0
		//! \brief evaluate sample from prior distribution
		//!
		virtual double evaluateFromPrior()=0;

		//!
		//! \fn void setLikelihood(double& likelihood)
		//! \brief Set particle likelihood
		//! \param likelihood Likelihood
		//!
		void setLikelihood(double& likelihood);

		//!
		//! \fn inline double& getLikelihood()
		//! \brief Get particle likelihood
		//! \return Likelihood
		//!
		inline double& getLikelihood()
		{
			return _likelihood;
		}

		//!
		//! \fn inline std::vector<double>& getStateVector()
		//! \brief Get particle state vector
		//! \return State vector
		//!
        inline std::vector<double>& getStateVector()
        {
            return _stateVector;
        }

		//!
		//! \fn inline void setStateVector(std::vector<double>& stateVec)
		//! \brief Set particle state vector
		//! \param stateVec new state vector
		//!
		inline void setStateVector(std::vector<double>& stateVec)
		{
			_stateVector = stateVec;
		}

    protected:
		//!
		//! \fn double evaluateGaussian(std::vector<double>& x, std::vector<double>& mean, std::vector<double>& var)
		//! \brief Evaluate a sample on a specified gaussian multivariate distribution
		//! \param x sample to evaluate
		//! \param mean mean vector of the multivariate gaussian
		//! \param var diagonal of the covariance matrix of the multivariate gaussian
		//! \return computed value
		//!
		double evaluateGaussian(std::vector<double>& x, std::vector<double>& mean, std::vector<double>& var);//Consider that cov matrix is  diagonal

		//!
		//! \fn evaluateGaussian(std::vector<double>& x, std::vector<double>& mean, double var)
		//! \brief Evaluate a sample on a specified gaussian multivariate distribution
		//! \param x sample to evaluate
		//! \param mean mean vector of the multivariate gaussian
		//! \param var diagonal of the covariance matrix of the multivariate gaussian (in case of all variances on diagonal are equal)
		//! \return computed value
		//!
		double evaluateGaussian(std::vector<double>& x, std::vector<double>& mean, double var);//Consider that var is constant for all dimensions


		FilterEnv* _pFilterEnv; //!< Pointer on FilterEnv instance

		std::vector<double> _stateVector; //!< Particle state vector
		std::vector<double> _oldStateVector; //!< Particle old state vector
		std::vector<double> _prevDetection; //!< Last detection
		boost::random::mt19937 *_rng; //!< Pointer on random seed
		double _likelihood; //!< Particle likelihood
};

#endif // PARTICLE_H
