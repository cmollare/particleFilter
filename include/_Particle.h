#ifndef PARTICLE_H
#define PARTICLE_H

#define PI 3.14159265359

#include <vector>
#include <boost/random.hpp>
#include "FilterEnv.h"

class _Particle
{
    public:
		_Particle(FilterEnv* pFilterEnv);

		virtual void sampleFromPrior()=0;
		virtual void sampleFromDynamic()=0;
		virtual void sampleFromDetector(std::vector<double>& detection)=0;
		virtual double evaluateFromDynamic()=0;
		virtual double evaluateFromImportance()=0;
		virtual double evaluateFromPrior()=0;

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
		double evaluateGaussian(std::vector<double>& x, std::vector<double>& mean, std::vector<double>& var);//Consider that cov matrix is  diagonal
		double evaluateGaussian(std::vector<double>& x, std::vector<double>& mean, double var);//Consider that var is constant for all dimensions


		FilterEnv* _pFilterEnv;

        std::vector<double> _stateVector;
        std::vector<double> _oldStateVector;
		std::vector<double> _prevDetection;
		boost::random::mt19937 *_rng;
		double _likelihood;
};

#endif // PARTICLE_H
