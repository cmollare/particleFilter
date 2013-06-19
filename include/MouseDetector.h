#ifndef MOUSEDETECTOR_H
#define MOUSEDETECTOR_H

#include "_Detector.h"
#include "DemoObs.h"
#include <opencv2/opencv.hpp>

typedef struct MouseEvent
{
    int x;
    int y;
	bool isDetection;
}MouseEvent;

static void onMouse(int evt, int x, int y, int flags, void* params)
{
    MouseEvent *mouseEvt = (MouseEvent*) params;

	mouseEvt->isDetection = false;

	if(evt==CV_EVENT_MOUSEMOVE && (flags & CV_EVENT_FLAG_CTRLKEY))
    {
		mouseEvt->x = x;
		mouseEvt->y = y;
		mouseEvt->isDetection = true;
    }
}

class MouseDetector : public _Detector
{
    public:
		MouseDetector(std::string windowName="RES");
        ~MouseDetector();

        virtual void init(_Observation& obs);
        virtual std::vector<double>& detect(_Observation& obs);

    protected:
        MouseEvent* _mouseEvent;
		std::string _windowName;
};

#endif // MOUSEDETECTOR_H
