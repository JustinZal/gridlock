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
	virtual Action getAction(int t);
	//Damage the objects gives when coliding
	virtual Damage getDamage();
	//Give collision damage (d) and output if object was destroyed
	virtual bool collide(unsigned int d);
};

#endif