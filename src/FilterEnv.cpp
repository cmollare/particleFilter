#include "FilterEnv.h"

FilterEnv::FilterEnv()
{
    _rng = new boost::random::mt19937();
    _imageSize[0] = 640;
    _imageSize[1] = 480;
}

FilterEnv::~FilterEnv()
{
    delete _rng;
}

