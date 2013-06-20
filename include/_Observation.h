//!
//! \file _Observation.h
//! \brief Abstract class for observation model
//! \author Christophe Mollaret
//! \date June 2013
//!
//! If you have to implement a new observation model, derive this class
//!

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
