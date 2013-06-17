#ifndef FILTERENV_H
#define FILTERENV_H

#include <boost/random.hpp>
#include <vector>

class FilterEnv
{
    public:
        FilterEnv();
        ~FilterEnv();

        inline boost::random::mt19937* getRngSeed()
        {
            return _rng;
        }

        inline int* getImageSize()
        {
            return _imageSize;
        }

    protected:
        boost::random::mt19937 *_rng;

        int _imageSize[2]; //[x, y]

};

#endif // FILTERENV_H
