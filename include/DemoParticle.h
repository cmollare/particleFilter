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

class DemoParticle : public _Particle
{
    public:
		DemoParticle(FilterEnv* pFilterEnv);

        virtual void sampleFromPrior();
		virtual void sampleFromDynamic();
		virtual void sampleFromDetector(std::vector<double>& detection);

		virtual double evaluateFromDynamic();
		virtual double evaluateFromImportance();
		virtual double evaluateFromPrior();

	protected:
		double _varDetector, _varDynamic;

};

#endif // DEMOPARTICLE_H
