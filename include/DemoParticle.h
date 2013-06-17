#ifndef DEMOPARTICLE_H
#define DEMOPARTICLE_H

#include "_Particle.h"

class DemoParticle : public _Particle
{
    public:
		DemoParticle(FilterEnv* pFilterEnv);

        virtual void sampleFromPrior();
        virtual void sampleFromDynamic();
};

#endif // DEMOPARTICLE_H
