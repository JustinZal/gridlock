#ifndef GRIDLOCK_MATERIAL_HPP
#define GRIDLOCK_MATERIAL_HPP

#include <stdexcept>
#include <string>
#include <array>
#include "constants.hpp"

#include "material.hpp"

#define ABUNDANCE_CAP 100;
#define STANDARD_SPREAD 4
class Material{

private:
	std::string name;
	/**
	 * @brief determines how often a material is generated
	 * value is capped from 0 to 100  for now (100 being maximum abundance)
	 * this value also determines the cluster spread of a given material
	 */

	unsigned int abundance;
	/**
	 * @brief how hard a material is to mine
	 * materials can be of the same type but have a different accessibility
	 */

	unsigned int accessibility;
	/**
	 * @brief how hard the material is to store in a container
	 */

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