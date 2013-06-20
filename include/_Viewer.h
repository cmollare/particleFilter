//!
//! \file _Viewer.h
//! \brief Abstract class for viewer
//! \author Christophe Mollaret
//! \date June 2013
//!
//! If you have to implement a new filter, derive this class
//!

#ifndef _VIEWER_H
#define _VIEWER_H

#include <vector>

//!
//! \class _Viewer
//! \brief Abstract class for viewer
//!
//! If you have to implement a new filter, derive this class
//!

template <class Particle>
class _Viewer
{
    public:
		//!
		//! \fn _Viewer()
		//! \brief Constructor
		//!
		_Viewer();

		//!
		//! \fn virtual void displaySampling(std::vector<Particle*>& particles)=0
		//! \brief Display sampled particles
		//! \param particles Particle vector
		//!
        virtual void displaySampling(std::vector<Particle*>& particles)=0;

		//!
		//! \fn virtual void displayWeightedParticles(std::vector<Particle*>& particles, std::vector<double>& weights)=0
		//! \brief Display particles with their weights
		//! \param particles Particle vector
		//! \param weights Associated weights
		//!
        virtual void displayWeightedParticles(std::vector<Particle*>& particles, std::vector<double>& weights)=0;

		//!
		//! \fn virtual void displayResampling(std::vector<Particle*>& particles)=0
		//! \brief Display particles after resampling step
		//! \param particles Particle vector
		//!
        virtual void displayResampling(std::vector<Particle*>& particles)=0;

		//!
		//! \fn virtual void displayEstimatedParticle(Particle* estimatedParticle)=0
		//! \brief Display estimated particle
		//! \param estimatedParticle Pointer on estimated particle
		//!
		virtual void displayEstimatedParticle(Particle* estimatedParticle)=0;

		//!
		//! \fn virtual void updateDisplay()=0
		//! \brief Update viewer state
		//!
		virtual void updateDisplay()=0;
};

#include "_Viewer.tpp"

#endif // _VIEWER_H
