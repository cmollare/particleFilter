#ifndef MOUSEDETECTOR_H
#define MOUSEDETECTOR_H

#include "_Detector.h"
#include "DemoObs.h"
#include <opencv2/opencv.hpp>

typedef struct MouseEvent
{
    int x;
    int y;
}MouseEvent;

static void onMouse(int evt, int x, int y, int flags, void* params)
{
    MouseEvent *mouseEvt = (MouseEvent*) params;

    if(evt==CV_EVENT_MOUSEMOVE && flags==CV_EVENT_FLAG_CTRLKEY)
    {
        std::cout << x << " " << y << std::endl;
    }
}

class MouseDetector : public _Detector
{
    public:
        MouseDetector();
        ~MouseDetector();

        virtual void init(_Observation& obs);
        virtual std::vector<double>& detect(_Observation& obs);

    protected:
        MouseEvent* _mouseEvent;
};

#endif // MOUSEDETECTOR_H
