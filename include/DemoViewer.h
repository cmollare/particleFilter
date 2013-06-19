#ifndef DEMOVIEWER_H
#define DEMOVIEWER_H

#include <opencv2/opencv.hpp>
#include "_Viewer.h"
#include "DemoParticle.h"

class DemoViewer : public Viewer<DemoParticle>
{
    public:
		DemoViewer(std::string outputName);
        ~DemoViewer();

		void updateImage(cv::Mat& newImage);
        void displaySampling(std::vector<DemoParticle*>& particles);
		void displayWeightedParticles(std::vector<DemoParticle*>& particles, std::vector<double>& weights);
        void displayResampling(std::vector<DemoParticle*>& particles);
		void displayEstimatedParticle(DemoParticle* estimatedParticle);
		void updateDisplay();

    protected:
		std::string _outputName;
        cv::Mat _currentImage;
        cv::Mat _outputImage;

};

#endif // DEMOVIEWER_H
