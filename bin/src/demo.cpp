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
	DemoViewer viewer("ICOND");
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
	ICOND<DemoParticle, MouseDetector, DemoViewer> filter(&mouseDet, 500, 0.001, 0.5);
	filter.init(obs);
	filterSIR.init(obs);

	for (;;)
	{
		cap >> frame;
		obs.update(frame); //update observation
		viewer.updateImage(frame); //update viewer
		filter.update(obs, viewer); //update filter

		viewerSIR.updateImage(frame);
		filterSIR.update(obs, viewerSIR);


		short key = cv::waitKey(60);
		if (key == 27) break;
	}


	return 0;
}
