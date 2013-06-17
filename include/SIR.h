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

		virtual void init();
		virtual void update(_Observation& observation);
		virtual void update(_Observation& observation, Viewer& viewer);
		virtual void step();
};

#include "SIR.tpp"

#endif // SIR_H
