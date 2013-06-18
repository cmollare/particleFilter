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

double _Particle::evaluateGaussian(std::vector<double>& x, std::vector<double>& mean, std::vector<double>& var)
{
	double factor = pow(2*PI, -mean.size()/2.);
	double factorCov=1;
	double factorExp=0;

	for (int i=0 ; i<mean.size() ; i++)
	{
		factorCov *= var[i];
		factorExp += (x[i]-mean[i])*(x[i]-mean[i])/var[i];
	}

	factorExp = exp(-factorExp/2.);
	factorCov = 1./sqrt(factorCov);
	factor*=factorCov; // == (1/sqrt((2pi)^k|sigma|))

	return factor*factorExp;
}

double _Particle::evaluateGaussian(std::vector<double>& x, std::vector<double>& mean, double var)
{
	double power = mean.size()/2.;
	double factor = pow(2*PI, -power);
	double factorCov=1;
	double factorExp=0;

	for (int i=0 ; i<mean.size() ; i++)
	{
		factorCov *= var;
		factorExp += (x[i]-mean[i])*(x[i]-mean[i])/var;
	}

	factorExp = exp(-factorExp/2.);
	factorCov = 1./sqrt(factorCov);

	factor*=factorCov; // == (1/sqrt((2pi)^k|sigma|))

	return factor*factorExp;
}
