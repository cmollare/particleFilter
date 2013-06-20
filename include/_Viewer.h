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

template <class Particle>
class Viewer
{
    public:

        Viewer();

        virtual void displaySampling(std::vector<Particle*>& particles)=0;
        virtual void displayWeightedParticles(std::vector<Particle*>& particles, std::vector<double>& weights)=0;
        virtual void displayResampling(std::vector<Particle*>& particles)=0;
        virtual void displayEstimatedParticle(Particle* estimatedParticle)=0;
        virtual void updateDisplay()=0;
};

#include "_Viewer.tpp"

#endif // _VIEWER_H
