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


//!
//! \class _Observation
//! \brief Abstract class for observation model
//!

class _Observation
{
    public:

		//!
		//! \fn _Observation()
		//! \brief Constructor
		//!
        _Observation();

		//!
		//! \fn ~_Observation()
		//! \brief Destructor
		//!
        ~_Observation();

		//!
		//! \fn virtual double computeLikelihood(_Particle& particle)=0
		//! \brief Function to compute particle likelihood
		//! \param particle Particle to compute likelihood from
		//! \return Likelihood value
		//!
		virtual double computeLikelihood(_Particle& particle)=0;
};

#endif // _OBSERVATION_H
