#include "DemoViewer.h"

DemoViewer::DemoViewer(std::string outputName) : _Viewer(), _outputName(outputName)
{
	cv::namedWindow(_outputName.c_str());
}

DemoViewer::DemoViewer(std::string outputName, std::string controllerName) : _Viewer(), _outputName(outputName), _controllerName(controllerName)
{
	cv::namedWindow(_outputName.c_str());
	cv::namedWindow(_controllerName.c_str());

	_currentObs = cv::Vec3b(0, 0, 0);
	cv::createTrackbar("BLUE", _controllerName.c_str(), NULL, 255);
	cv::createTrackbar("GREEN", _controllerName.c_str(), NULL, 255);
	cv::createTrackbar("RED", _controllerName.c_str(), NULL, 255);
}

DemoViewer::~DemoViewer()
{
}

void DemoViewer::updateImage(cv::Mat &newImage)
{
	_currentImage = newImage.clone();
	_outputImage = newImage.clone();
	if (!_controllerName.empty())
	{
		_controllerImage = newImage.clone();
		this->updateCtrlImage();
	}
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

	if (!_controllerName.empty()) cv::imshow(_controllerName.c_str(), _controllerImage);
}

void DemoViewer::updateCtrlImage()
{
	std::vector<cv::Mat> channels;
	cv::split(_controllerImage, channels);
	_currentObs[0]=cv::getTrackbarPos("BLUE", _controllerName.c_str());
	channels[0] = 255-cv::abs(channels[0]-_currentObs[0]);
	_currentObs[1]= cv::getTrackbarPos("GREEN", _controllerName.c_str());
	channels[1] = 255-cv::abs(channels[1]-_currentObs[1]);
	_currentObs[2]= cv::getTrackbarPos("RED", _controllerName.c_str());
	channels[2] = 255-cv::abs(channels[2]-_currentObs[2]);


	cv::merge(channels, _controllerImage);
	cv::applyColorMap(_controllerImage, _controllerImage, cv::COLORMAP_JET);
}
