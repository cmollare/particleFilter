#include "DemoObs.h"

DemoObs::DemoObs(cv::Mat& firstObs, cv::Vec3b colorModel) : _Observation(), _colorModel(colorModel)
{
    _obs = firstObs.clone();
}

DemoObs::~DemoObs()
{
}

double DemoObs::computeLikelihood(_Particle& particle)
{
    std::vector<double> pos = particle.getStateVector();
	cv::Vec3b posParticle = _obs.at<cv::Vec3b>((int)pos[1], (int)pos[0]);

	cv::Vec3d res = cv::Vec3d(posParticle) - cv::Vec3d(_colorModel);
	double distance = 1/(sqrt(res[0]*res[0] + res[1]*res[1] + res[2]*res[2])+1);
    particle.setLikelihood(distance);

    return distance;
}

void DemoObs::update(cv::Mat& newObs)
{
	_obs = newObs.clone();
}
