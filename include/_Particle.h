#ifndef PARTICLE_H
#define PARTICLE_H

#include <vector>
#include <boost/random.hpp>
#include "FilterEnv.h"

class _Particle
{
    public:
		_Particle(FilterEnv* pFilterEnv);

		virtual void sampleFromPrior()=0;
		virtual void sampleFromDynamic()=0;

		void setLikelihood(double& likelihood);

		inline double& getLikelihood()
		{
			return _likelihood;
		}

        inline std::vector<double>& getStateVector()
        {
            return _stateVector;
        }

		inline void setStateVector(std::vector<double>& stateVec)
		{
			_stateVector = stateVec;
		}

    protected:
		FilterEnv* _pFilterEnv;

        std::vector<double> _stateVector;
        std::vector<double> _oldStateVector;
		boost::random::mt19937 *_rng;
		double _likelihood;
};

#endif // PARTICLE_H
