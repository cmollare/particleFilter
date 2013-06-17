#include "SIR.h"
#include "DemoObs.h"
#include "DemoParticle.h"
#include "DemoViewer.h"

#include <opencv2/opencv.hpp>

int main()
{

	cv::VideoCapture cap(0);
	cv::Mat frame;
	DemoViewer viewer;

	if(!cap.isOpened())
	{
		std::cout << "no device to open" << std::endl;
		return 0;
	}

	cap >> frame;
	cv::imshow("SRC", frame);

	SIR<DemoParticle, DemoViewer> filter(500);
	filter.init();

	cv::Vec3b vec(255, 255, 255);
	DemoObs obs(frame, vec);

	viewer.updateImage(frame);

	for (;;)
	{
		cap >> frame;
		obs.update(frame); //update observation
		viewer.updateImage(frame); //update viewer
		filter.update(obs, viewer); //update filter


		if (cv::waitKey(60) >= 0) break;
	}


	return 0;
}
