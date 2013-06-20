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

//!
//! \class DemoObs
//! \brief Example class for observation model
//!

class DemoObs : public _Observation
{
    public:

		//!
		//! \fn DemoObs(cv::Mat& firstObs, cv::Vec3b colorModel)
		//! \brief Constructor
		//! \param firstObs image for first observation
		//! \param colorModel color to track
		//!
		DemoObs(cv::Mat& firstObs, cv::Vec3b colorModel);

		//!
		//! \fn ~DemoObs()
		//! \brief Destructor
		//!
		~DemoObs();

		//!
		//! \fn virtual double computeLikelihood(_Particle& particle)
		//! \brief Compute likelihood
		//! \param particle Particle to compute likelihood from
		//! \return Computed likelihood
		//!
		//! Compute likelihood with 2-norm beetween the colorModel and the pixel of the particle.
		//!
        virtual double computeLikelihood(_Particle& particle);

		//!
		//! \fn void update(cv::Mat& newObs)
		//! \brief Update image
		//! \param newObs New image
		//!
		void update(cv::Mat& newObs);

		//!
		//! \fn inline void setColorModel(cv::Vec3b cm)
		//! \brief Change the color to track
		//! \param cm New color model
		//!
		inline void setColorModel(cv::Vec3b cm)
		{
			_colorModel = cm;
		}

		//!
		//! \fn inline cv::Mat& getCurrentObs()
		//! \brief Get current image
		//! \return Current image
		//!
		inline cv::Mat& getCurrentObs()
		{
			return _obs;
		}

    protected:
		cv::Mat _obs; //!< Current image
		cv::Vec3b _colorModel; //!< Current color model
};

#endif
