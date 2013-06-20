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

class DemoViewer : public Viewer<DemoParticle>
{
    public:
		DemoViewer(std::string outputName);
		DemoViewer(std::string outputName, std::string controllerName);
        ~DemoViewer();

		void updateImage(cv::Mat& newImage);
        void displaySampling(std::vector<DemoParticle*>& particles);
		void displayWeightedParticles(std::vector<DemoParticle*>& particles, std::vector<double>& weights);
        void displayResampling(std::vector<DemoParticle*>& particles);
		void displayEstimatedParticle(DemoParticle* estimatedParticle);
		void updateDisplay();

		inline cv::Vec3b& getCurrentObs()
		{
			return _currentObs;
		}

    protected:
		void updateCtrlImage();

		std::string _outputName;
		std::string _controllerName;
        cv::Mat _currentImage;
        cv::Mat _outputImage;
		cv::Mat _controllerImage;
		cv::Vec3b _currentObs;

};

#endif // DEMOVIEWER_H
