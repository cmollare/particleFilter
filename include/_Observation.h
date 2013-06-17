#ifndef _OBSERVATION_H
#define _OBSERVATION_H

#include "_Particle.h"

class _Observation
{
    public:
        _Observation();
        ~_Observation();

		virtual double computeLikelihood(_Particle& particle)=0;
};

#endif // _OBSERVATION_H
