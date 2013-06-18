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
