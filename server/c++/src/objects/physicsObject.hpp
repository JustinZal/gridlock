#ifndef physicsObject_h
#define physicsObject_h

#include <stdexcept>
#include <string>

#include "action.hpp"
#include "damage.hpp"

#include "physicsObject.hpp"

class PhysicsObject{
private:
public:
	//Get objects action at time (t)
	Action getAction(int t);
	//Damage the objects gives when coliding
	Damage getDamage();
	//Give collision damage (d) and output if object was destroyed
	bool colide(unsigned int d);
};

#endif