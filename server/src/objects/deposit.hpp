#ifndef GRIDLOCK_DEPOSIT_HPP
#define GRIDLOCK_DEPOSIT_HPP

#include <stdexcept>
#include <vector>
#include "constants.hpp"
#include "material.hpp"

#include "deposit.hpp"

class Deposit{

private:
	//Material contained
	Material *material;

	//How much of the material is present
	unsigned int volume;
	
	//How accisible is the material
	unsigned int accessibility;

public:
	Deposit(
		/*Material * _material,*/
		unsigned int _volume,
		unsigned int _accessibility);

	Material * getMaterial();

	unsigned int getVolume();

	unsigned int getAccessibility();
};

#endif