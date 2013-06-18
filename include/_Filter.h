#ifndef FILTER_H
#define FILTER_H

#include <vector>
#include <boost/random.hpp>
#include "_Observation.h"
#include "_Viewer.h"
#include "FilterEnv.h"

template <class Particle, class Viewer>
class _Filter
{
	public:
		_Filter(int nbPaticles);
		~_Filter();

		virtual void init(_Observation& observation);
		virtual void update(_Observation& observation)=0;
		virtual void update(_Observation& observation, Viewer& viewer)=0;
		virtual void step()=0;
		virtual void updateWeights(_Observation& observation);
		virtual void resample();
		virtual void computeMMSE();
		virtual void calcNeff();

		inline std::vector<Particle*>& getParticleVector()
		{
			return _vParticles;
		}

		inline std::vector<double>& getWeightVector()
		{
			return _vWeights;
		}

		inline Particle* getParticleMMSE()
		{
			return _mmseParticle;
		}

	protected:
		FilterEnv* _pFilterEnv;

		std::vector<Particle*> _vParticles;
		Particle* _mmseParticle;
		int _nbParticles;

		std::vector<double> _vWeights;
		std::vector<double> _cdf;
		double _weightNorm;

		double _Neff;
		double _Ns;

		boost::random::mt19937_64 _rng;
};

#include "_Filter.tpp"

#endif
