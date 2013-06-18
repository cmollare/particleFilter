#ifndef DEMOOBS_H
#define DEMOOBS_H

#include "_Observation.h"
#include <opencv2/opencv.hpp>

class DemoObs : public _Observation
{
    public:
		DemoObs(cv::Mat& firstObs, cv::Vec3b colorModel);
        ~DemoObs();

        virtual double computeLikelihood(_Particle& particle);
        void update(cv::Mat& newObs);

		inline cv::Mat& getCurrentObs()
		{
			return _obs;
		}

    protected:
        cv::Mat _obs;
		cv::Vec3b _colorModel;
};

#endif
