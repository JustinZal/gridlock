#include <stdexcept>

#include "vector.h"

Vector operator+ (const Vector & in) const{
	return Vector(x+in.x,y+in.y);
}