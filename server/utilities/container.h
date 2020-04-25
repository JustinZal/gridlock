#ifndef conatiner_h
#define conatiner_h

#include <stdexcept>
#include "constants.h"

#include "conatiner.h"

class Conatiner{
	public:
		unsigned int volume=1;
		unsigned int content=0;
		Material *material=NULL;
};

#endif