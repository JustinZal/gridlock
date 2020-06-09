#ifndef projectile_h
#define projectile_h

#include <stdexcept>
#include "constants.hpp"

#include "object.hpp"
#include "projectile.hpp"

class Projectile:public object{
private:
	unsigned int damage=0;
};

#endif
