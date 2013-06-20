//!
//! \file FilterEnv.h
//! \brief Class to encapsulate global variables
//! \author Christophe Mollaret
//! \date June 2013
//!
//! For now, it only encapsulates the random seed.
//! It has to be used more.
//!


#ifndef FILTERENV_H
#define FILTERENV_H

#include <boost/random.hpp>
#include <vector>

//!
//! \class FilterEnv
//! \brief Filter global variables
//!

class FilterEnv
{
    public:

		//!
		//! \fn FilterEnv()
		//! \brief Constructor
		//!
        FilterEnv();

		//!
		//! \fn ~FilterEnv()
		//! \brief Destructor
		//!
        ~FilterEnv();

		//!
		//! \fn inline boost::random::mt19937* getRngSeed()
		//! \brief Get random seed
		//! \return Pointer on random seed
		//!
        inline boost::random::mt19937* getRngSeed()
        {
            return _rng;
        }

		//!
		//! \fn inline int* getImageSize()
		//! \brief Get image size as a 2 dim vector
		//! \return image size
		//!
        inline int* getImageSize()
        {
            return _imageSize;
        }

    protected:
		boost::random::mt19937 *_rng; //!< Pointer on random seed

		int _imageSize[2]; //!< Image size 2-dim vector : [x, y]

};

#endif // FILTERENV_H
