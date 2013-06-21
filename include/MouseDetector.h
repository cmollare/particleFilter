//!
//! \file MouseDetector.h
//! \brief Detect the mouse position
//! \author Christophe Mollaret
//! \date June 2013
//!
//! This detector return the position of the mouse in the specified window.
//! To detect, you have to hold the "ctrl" key when moving the mouse.
//!

#ifndef MOUSEDETECTOR_H
#define MOUSEDETECTOR_H

#include "_Detector.h"
#include "DemoObs.h"
#include <opencv2/opencv.hpp>

//!
//! \struct MouseEvent
//! \brief Structure that manages mouse events
//!
typedef struct MouseEvent
{
	int x; //!< x mouse position int the image
	int y; //!< y mouse position int the image
	bool isDetection; //!< True if there is a detection
}MouseEvent;

//!
//! \fn static void onMouse(int evt, int x, int y, int flags, void* params)
//! \brief callback function for mouse events (see opencv callback functions)
//! \param evt Event type
//! \param x Mouse x position
//! \param y Mouse y position
//! \param flags Key pressed flags
//! \param params Pointer on user defined paramaters
//!

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

//!
//! \class MouseDetector
//! \brief Implementation of detector of mouse in the image
//!

class MouseDetector : public _Detector
{
    public:

		//!
		//! \fn MouseDetector(std::string windowName="RES")
		//! \brief Constructor
		//! \param windowName Name of window where detector is active
		//!
		MouseDetector(std::string windowName="RES");

		//!
		//! \fn ~MouseDetector()
		//! \brief Destructor
		//!
        ~MouseDetector();

		//!
		//! \fn virtual void init(_Observation& obs)
		//! \brief Initialisation of detector
		//! \param obs Current observation model
		//!
		virtual void init(_Observation& obs);

		//!
		//! \fn virtual std::vector<double>& detect(_Observation& obs)
		//! \brief Launch detection
		//! \param obs Current observation model
		//! \return Return current detection
		//!
        virtual std::vector<double>& detect(_Observation& obs);

    protected:
		MouseEvent* _mouseEvent; //!< pointer on MouseEvent structure
		std::string _windowName; //!< Name of window used for detection
};

#endif // MOUSEDETECTOR_H
