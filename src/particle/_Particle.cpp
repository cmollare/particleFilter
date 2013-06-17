#include "_Particle.h"

_Particle::_Particle(FilterEnv* pFilterEnv) : _pFilterEnv(pFilterEnv)
{
	_likelihood = 0;
	_rng = _pFilterEnv->getRngSeed();
}

void _Particle::setLikelihood(double& likelihood)
{
	_likelihood = likelihood;
}

