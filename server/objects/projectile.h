#ifndef projectile_h
#define projectile_h

#include <stdexcept>
#include "constants.h"

#include "object.h"

class Projectile:public object{
	private:
		unsigned int damage=0;
};

#endif