#ifndef object_h
#define object_h

#include <stdexcept>

#include "vector.hpp"
#include "object.hpp"

class Object{
	private:
		Vector velocity;
		Move moves

	public:
		void Object();

		Vector getVelocity();
		int getMass();
		int getDensity();
		int getVolume();

		void impact(Vector);

};

#endif