#ifndef GRIDLOCK_PHYSICSOBJECT_HPP
#define GRIDLOCK_PHYSICSOBJECT_HPP

#include <stdexcept>
#include <string>

#include "action.hpp"
#include "damage.hpp"

#include "physicsObject.hpp"

class PhysicsObject{

private:

public:
	//Get objects action at time (_t)
	virtual Action getAction(
		int _t);

	//Mass of the object
	virtual unsigned int getMass();

	//Damage the objects gives when coliding
	virtual Damage giveDamage();

	//Give collision damage (_damage) and output if object was destroyed
	virtual bool takeDamage(
		Damage _damage);
};

#endif