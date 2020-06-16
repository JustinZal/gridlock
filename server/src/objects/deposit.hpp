#ifndef GRIDLOCK_DEPOSIT_HPP
#define GRIDLOCK_DEPOSIT_HPP

#include <stdexcept>
#include <vector>

#include "constants.hpp"
#include "material.hpp"
#include "nonPhysicsObject.hpp"

#include "deposit.hpp"

class Deposit:public NonPhysicsObject{

private:
	//Material contained
	std::shared_ptr<Material> material;

	//How much of the material is present
	unsigned int volume;
	
	//How accesible is the material
	unsigned int accessibility;

public:
	Deposit(
		std::shared_ptr<Material> _material,
		unsigned int _volume,
		unsigned int _accessibility);

	Material * getMaterial();

	unsigned int getVolume();

	unsigned int getAccessibility();
};

#endif