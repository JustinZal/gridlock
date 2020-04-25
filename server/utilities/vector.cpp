#include <stdexcept>

#include "vector.hpp"

Vector operator+ (const Vector & in) const{
	return Vector(x+in.x,y+in.y);
}
