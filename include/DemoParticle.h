//!
//! \file DemoParticle.h
//! \brief Demonstration class for particle implementation
//! \author Christophe Mollaret
//! \date June 2013
//!
//! This class shows how to implement a particle.
//! The state vector is [u, v], the position in an image.
//! The dynamic is a random walk and the prior low is uniform in the image.
//!


#ifndef DEMOPARTICLE_H
#define DEMOPARTICLE_H

#include "_Particle.h"


//!
//! \class DemoParticle
//! \brief Demonstration class for particle implementation
//!
//! This class shows how to implement a particle.
//! The state vector is [u, v], the position in an image.
//! The dynamic is a random walk and the prior low is uniform in the image.
//!
class DemoParticle : public _Particle
{
    public:

		//!
		//! \fn DemoParticle(FilterEnv* pFilterEnv)
		//! \brief Constructor
		//! \param Pointer to FilterEnv instance
		//!
		DemoParticle(FilterEnv* pFilterEnv);

		//!
		//! \fn virtual void sampleFromPrior()
		//! \brief Sample from prior law
		//!
		//! Sample from a uniform law on all image.
		//!
        virtual void sampleFromPrior();

		//!
		//! \fn virtual void sampleFromDynamic()
		//! \brief Sample from dynamic
		//!
		//! Sample from random walk around the previous particle with variance _varDynamic
		//!
		virtual void sampleFromDynamic();

		//!
		//! \fn virtual void sampleFromDetector(std::vector<double>& detection)
		//! \brief Sample from detection
		//! \param detection Detector state vector
		//!
		//! Sample from a random qalk around the detector state with variance _varDetector
		//!
		virtual void sampleFromDetector(std::vector<double>& detection);

		//!
		//! \fn virtual double evaluateFromDynamic()
		//! \brief Evaluate sample from dynamic multivariate gaussian
		//!
		virtual double evaluateFromDynamic();

		//!
		//! \fn virtual double evaluateFromImportance()
		//! \brief Evaluate sample from detector multivariate gaussian
		//!
		virtual double evaluateFromDetector();

		//!
		//! \fn virtual double evaluateFromPrior()
		//! \brief Evaluate sample from prior uniform law
		//!
		virtual double evaluateFromPrior();

	protected:
		double _varDetector; //!< Variance of detector multivariate gaussian
		double _varDynamic; //!< Variance of dynamic multivariate gaussian

};

#endif // DEMOPARTICLE_H
