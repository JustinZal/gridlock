#ifndef material_h
#define material_h

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
	Material(std::string _name);
	std::string getName();
};

#endif