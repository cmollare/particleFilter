//!
//! \file DemoViewer.h
//! \brief Demonstration class for viewer implementation
//! \author Christophe Mollaret
//! \date June 2013
//!
//! Demonstration of how a viewer could be used.
//!

#ifndef DEMOVIEWER_H
#define DEMOVIEWER_H

#include <opencv2/opencv.hpp>
#include "_Viewer.h"
#include "DemoParticle.h"

//!
//! \class DemoViewer
//! \brief Demonstration class for viewer implementation
//!

class DemoViewer : public _Viewer<DemoParticle>
{
    public:

		//!
		//! \fn DemoViewer(std::string outputName)
		//! \brief Constructor for viewer only
		//! \param outputName Window's name
		//!
		DemoViewer(std::string outputName);

		//!
		//! \fn DemoViewer(std::string outputName, std::string controllerName)
		//! \brief Constructor for viewer + observation model change
		//! \param outputName Window's name
		//! \param controllerName Controller window's name
		//!
		DemoViewer(std::string outputName, std::string controllerName);

		//!
		//! \fn ~DemoViewer()
		//! \brief Destructor
		//!
        ~DemoViewer();

		//!
		//! \fn void updateImage(cv::Mat& newImage)
		//! \brief Update image for current display
		//! \param newImage New image
		//!
		void updateImage(cv::Mat& newImage);

		//!
		//! \fn virtual void displaySampling(std::vector<Particle*>& particles)
		//! \brief Display sampled particles
		//! \param particles Particle vector
		//!
		void displaySampling(std::vector<DemoParticle*>& particles);

		//!
		//! \fn virtual void displayWeightedParticles(std::vector<Particle*>& particles, std::vector<double>& weights)
		//! \brief Display particles with their weights
		//! \param particles Particle vector
		//! \param weights Associated weights
		//!
		void displayWeightedParticles(std::vector<DemoParticle*>& particles, std::vector<double>& weights);

		//!
		//! \fn virtual void displayResampling(std::vector<Particle*>& particles)
		//! \brief Display particles after resampling step
		//! \param particles Particle vector
		//!
        void displayResampling(std::vector<DemoParticle*>& particles);

		//!
		//! \fn virtual void displayEstimatedParticle(Particle* estimatedParticle)
		//! \brief Display estimated particle
		//! \param estimatedParticle Pointer on estimated particle
		//!
		void displayEstimatedParticle(DemoParticle* estimatedParticle);

		//!
		//! \fn virtual void updateDisplay()
		//! \brief Update viewer state
		//!
		void updateDisplay();

		//!
		//! \fn inline cv::Vec3b& getCurrentObs()
		//! \brief Get current observation model
		//! \return Current observation model
		//!
		inline cv::Vec3b& getCurrentObs()
		{
			return _currentObs;
		}

    protected:

		//!
		//! \fn void updateCtrlImage()
		//! \brief Update display of controller part
		//!
		void updateCtrlImage();

		std::string _outputName; //!< filter output window's name
		std::string _controllerName; //!< controller view window's name
		cv::Mat _currentImage; //!< original image
		cv::Mat _outputImage; //!< display of filter
		cv::Mat _controllerImage; //!< display of controller
		cv::Vec3b _currentObs; //!< current observation model

};

#endif // DEMOVIEWER_H
