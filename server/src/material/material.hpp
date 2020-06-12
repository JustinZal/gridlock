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
	unsigned int mass;

public:
	Material(
		std::string _name);
	
	std::string getName();
};

#endif