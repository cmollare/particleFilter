#include "DemoParticle.h"

DemoParticle::DemoParticle(FilterEnv* pFilterEnv) : _Particle(pFilterEnv)
{
    _stateVector.resize(2, 0);
	_varDetector=5;
	_varDynamic=10;
}

void DemoParticle::sampleFromPrior()
{
	_oldStateVector = _stateVector;


	boost::random::uniform_int_distribution<int> unifX(0, _pFilterEnv->getImageSize()[0]);
	boost::random::uniform_int_distribution<int> unifY(0, _pFilterEnv->getImageSize()[1]);
	_stateVector[0] = unifX(*_rng);
	_stateVector[1] = unifY(*_rng);

	if (_stateVector[0] >= _pFilterEnv->getImageSize()[0]) _stateVector[0]=_pFilterEnv->getImageSize()[0]-1;
	else if (_stateVector[0] < 0) _stateVector[0]=0;

	if (_stateVector[1] >= _pFilterEnv->getImageSize()[1]) _stateVector[1]=_pFilterEnv->getImageSize()[1]-1;
	else if (_stateVector[1] < 0) _stateVector[1]=1;
}

void DemoParticle::sampleFromDynamic()
{
    _oldStateVector = _stateVector;

	boost::random::normal_distribution<double> gauss(0, _varDynamic);
	_stateVector[0] = _oldStateVector[0] + (int)gauss(*_rng);
	_stateVector[1] = _oldStateVector[1] + (int)gauss(*_rng);

	if (_stateVector[0] >= _pFilterEnv->getImageSize()[0]) _stateVector[0]=_pFilterEnv->getImageSize()[0]-1;
	else if (_stateVector[0] < 0) _stateVector[0]=0;

	if (_stateVector[1] >= _pFilterEnv->getImageSize()[1]) _stateVector[1]=_pFilterEnv->getImageSize()[1]-1;
	else if (_stateVector[1] < 0) _stateVector[1]=1;
}

void DemoParticle::sampleFromDetector(std::vector<double>& detection)
{
	_prevDetection = detection;
	_oldStateVector = _stateVector;

	boost::random::normal_distribution<double> gauss(0, _varDetector);
	_stateVector[0] = detection[0] + (int)gauss(*_rng);
	_stateVector[1] = detection[1] + (int)gauss(*_rng);

	if (_stateVector[0] >= _pFilterEnv->getImageSize()[0]) _stateVector[0]=_pFilterEnv->getImageSize()[0]-1;
	else if (_stateVector[0] < 0) _stateVector[0]=0;

	if (_stateVector[1] >= _pFilterEnv->getImageSize()[1]) _stateVector[1]=_pFilterEnv->getImageSize()[1]-1;
	else if (_stateVector[1] < 0) _stateVector[1]=1;
}

double DemoParticle::evaluateFromDynamic()
{
	return this->evaluateGaussian(_stateVector, _oldStateVector, _varDynamic*_varDynamic);
}

double DemoParticle::evaluateFromDetector()
{
	return this->evaluateGaussian(_stateVector, _prevDetection, _varDetector*_varDetector);
}

double DemoParticle::evaluateFromPrior()
{
	return 1./(_pFilterEnv->getImageSize()[1]*_pFilterEnv->getImageSize()[0]);
}
