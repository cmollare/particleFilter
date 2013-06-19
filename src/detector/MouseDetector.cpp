#include "MouseDetector.h"

MouseDetector::MouseDetector(std::string windowName) : _Detector(), _windowName(windowName)
{
    _currentDetection.resize(2, 0);
    _mouseEvent = new MouseEvent;
    _mouseEvent->x=0;
    _mouseEvent->y=0;
	_mouseEvent->isDetection=false;
}

MouseDetector::~MouseDetector()
{
    delete _mouseEvent;
}

void MouseDetector::init(_Observation &obs)
{
    DemoObs& observation = (DemoObs&) obs;
	cv::setMouseCallback("ICOND", onMouse, _mouseEvent);
    _currentDetection[0] = _mouseEvent->x;
    _currentDetection[1] = _mouseEvent->y;
}

std::vector<double>& MouseDetector::detect(_Observation& obs)
{	
    DemoObs& observation = (DemoObs&) obs;

    _currentDetection[0] = _mouseEvent->x;
    _currentDetection[1] = _mouseEvent->y;
	_isDetected = _mouseEvent->isDetection;

    return _currentDetection;
}
