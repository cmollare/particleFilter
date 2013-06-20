//!
//! \file _Detector.h
//! \brief Abstract class for detector
//! \author Christophe Mollaret
//! \date June 2013
//!


#ifndef _DETECTOR_H
#define _DETECTOR_H

#include <vector>
#include "_Observation.h"

//!
//! \class _Detector
//! \brief Abstract class for detector
//!
//! Has to be reimplemented if detector is needed
//!

class _Detector
{
    public:

		//!
		//! \fn _Detector()
		//! \brief Constructor
		//!
        _Detector();

		//!
		//! \fn virtual void init(_Observation& obs)=0
		//! \brief Detector initialisation
		//! \param obs Observation model
		//!
		//! Pure virtual function
		//!
        virtual void init(_Observation& obs)=0;

		//!
		//! \fn virtual std::vector<double>& detect(_Observation& obs)=0
		//! \brief Process detection
		//! \param obs Observation model
		//! \return return _currenDetection (state vector of detection)
		//!
        virtual std::vector<double>& detect(_Observation& obs)=0;

		//!
		//! \fn inline std::vector<double>& getDetection()
		//! \brief Getter
		//! \return _currentDetection, state vector of detection
		//!
		inline std::vector<double>& getDetection()
		{
			return _currentDetection;
		}

		//!
		//! \fn inline bool isDetected()
		//! \brief Test if there was a detection
		//! \return True if something was detected, else, return false
		//!
		inline bool isDetected()
		{
			return _isDetected;
		}

    protected:
		std::vector<double> _currentDetection; //!< detection state vector
		bool _isDetected; //!< True if something is currently detected
};

#endif // _DETECTOR_H
