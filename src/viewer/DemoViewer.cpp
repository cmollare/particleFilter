#include "DemoViewer.h"

DemoViewer::DemoViewer(std::string outputName) : Viewer(), _outputName(outputName)
{
	cv::namedWindow(_outputName.c_str());
}

DemoViewer::~DemoViewer()
{
}

void DemoViewer::updateImage(cv::Mat &newImage)
{
	_currentImage = newImage.clone();
	_outputImage = newImage.clone();
}

void DemoViewer::displaySampling(std::vector<DemoParticle*>& particles)
{
	for (int i=0 ; i<particles.size() ; i++)
	{
		cv::Point pt;
		pt.x = particles[i]->getStateVector()[0];
		pt.y = particles[i]->getStateVector()[1];
		cv::circle(_outputImage, pt, 0, cv::Scalar(255, 0, 0), 2);
	}
}

void DemoViewer::displayWeightedParticles(std::vector<DemoParticle*>& particles, std::vector<double>& weights)
{
	for (int i=0 ; i<particles.size() ; i++)
	{
		cv::Point pt;
		pt.x = particles[i]->getStateVector()[0];
		pt.y = particles[i]->getStateVector()[1];
		int radius = int(weights[i]*1000);
		cv::circle(_outputImage, pt, radius, cv::Scalar(0, 0, 255), 1);
	}
}

void DemoViewer::displayResampling(std::vector<DemoParticle*>& particles)
{
	for (int i=0 ; i<particles.size() ; i++)
	{
		cv::Point pt;
		pt.x = particles[i]->getStateVector()[0];
		pt.y = particles[i]->getStateVector()[1];
		cv::circle(_outputImage, pt, 0, cv::Scalar(255, 0, 0), 5);
	}
}

void DemoViewer::displayEstimatedParticle(DemoParticle* estimatedParticle)
{
	cv::Point pt;
	pt.x = estimatedParticle->getStateVector()[0];
	pt.y = estimatedParticle->getStateVector()[1];

	cv::circle(_outputImage, pt, 10, cv::Scalar(0, 0, 255), 10);
}

void DemoViewer::updateDisplay()
{
	cv::imshow(_outputName.c_str(), _outputImage);
}
