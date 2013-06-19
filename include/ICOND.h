#ifndef ICOND_H
#define ICOND_H

#include "_Filter.h"

template<class Particle, class Detector, class Viewer>
class ICOND : public _Filter<Particle, Viewer>
{
    public:
		ICOND(int nbParticles, double q, double r); //q = prior percent, r = importance sampling percent, dynamics = 1-q-r
		ICOND(Detector* detector, int nbParticles, double q, double r);
		~ICOND();
		virtual void init(_Observation& observation);
		virtual void update(_Observation& observation);
		virtual void update(_Observation& observation, Viewer& viewer);
		virtual void updateWeights(_Observation& observation);
		virtual void step();

    protected:
        double _q, _r;
		std::vector<double> _vLambda;
		Detector* _detector;

		bool _isDetectorAllocated;
};

#include "ICOND.tpp"

#endif // ICOND_H
