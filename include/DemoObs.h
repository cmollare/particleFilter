//!
//! \file DemoObs.h
//! \brief Demo class for observation model
//! \author Christophe Mollaret
//! \date June 2013
//!
//! This class demonstrate how to implement an observation model.
//! It mesures a pixel value and compute a norm 2 distance between current value and tracked value.
//!

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

		inline void setColorModel(cv::Vec3b cm)
		{
			_colorModel = cm;
		}

		inline cv::Mat& getCurrentObs()
		{
			return _obs;
		}

    protected:
        cv::Mat _obs;
		cv::Vec3b _colorModel;
};

#endif
