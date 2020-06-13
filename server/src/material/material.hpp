#ifndef GRIDLOCK_MATERIAL_HPP
#define GRIDLOCK_MATERIAL_HPP

#include <stdexcept>
#include <string>
#include <array>
#include "constants.hpp"

#include "material.hpp"

class Material{

private:
	std::string name;

	unsigned int abundance;

	unsigned int accessibility;

	unsigned int mass;

public:
	Material(
		std::string _name,
		unsigned int _abundance,
		unsigned int _accessibility,
		unsigned int _mass);
	
	std::string getName();

	unsigned int getAbundance();

	unsigned int getAccessibility();

	unsigned int getMass();

};

#endif