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
	virtual std::unique_ptr<Action> getAction(
		int _t)=0;

	//Mass of the object
	virtual unsigned int getMass()=0;

	//Damage the objects gives when colliding
	virtual Damage giveDamage()=0;

	//Give collision damage (_damage) and output if object was destroyed
	virtual bool takeDamage(
		Damage _damage)=0;
};

#endif