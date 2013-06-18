#ifndef _DETECTOR_H
#define _DETECTOR_H

#include <vector>
#include "_Observation.h"

class _Detector
{
    public:
        _Detector();

        virtual void init(_Observation& obs)=0;
        virtual std::vector<double>& detect(_Observation& obs)=0;

    protected:
        std::vector<double> _currentDetection;
};

#endif // _DETECTOR_H
