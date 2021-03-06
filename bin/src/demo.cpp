//!
//! \file demo.cpp
//! \brief Demo programm for particle filter
//! \author Christophe Mollaret
//! \date June 2013
//!
//!
//! This programm show how to use particle filter SIR and ICOND with a viewer, a detector and an observation model
//!


#include "SIR.h"
#include "ICOND.h"
#include "DemoObs.h"
#include "DemoParticle.h"
#include "DemoViewer.h"
#include "MouseDetector.h"

#include <opencv2/opencv.hpp>

int main()
{

	cv::VideoCapture cap(0);
	cv::Mat frame;
	DemoViewer viewer("ICOND", "CTRL");
	DemoViewer viewerSIR("SIR");

	if(!cap.isOpened())
	{
		std::cout << "no device to open" << std::endl;
		return 0;
	}

	cap >> frame;

	cv::Vec3b vec(0, 0, 0);
	DemoObs obs(frame, vec);

	viewer.updateImage(frame);
	viewerSIR.updateImage(frame);

	MouseDetector mouseDet("ICOND");

	SIR<DemoParticle, DemoViewer> filterSIR(500);
	ICOND<DemoParticle, MouseDetector, DemoViewer> filter(&mouseDet, 500, 0.1, 0.2);
	filter.init(obs);
	filterSIR.init(obs);

	for (;;)
	{
		cap >> frame;

		viewer.updateImage(frame); //update viewer
		obs.update(frame); //update observation
		obs.setColorModel(viewer.getCurrentObs());

		filter.update(obs, viewer); //update filter

		viewerSIR.updateImage(frame);
		filterSIR.update(obs, viewerSIR);


		short key = cv::waitKey(60);
		if (key == 27) break;
	}


	return 0;
}
