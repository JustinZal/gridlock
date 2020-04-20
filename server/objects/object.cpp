#include <stdexcept>

#include "vector.h"

#include "object.h"

void object::accelerate(Vector vIn){
	v+=vIn;
}