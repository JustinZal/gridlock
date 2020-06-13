#include "material.hpp"

Material::Material(
		std::string _name,
		unsigned int _abundance,
		unsigned int _accessibility,
		unsigned int _mass){
	name=_name;
	abundance=_abundance;
	accessibility=_accessibility;
	mass=_mass;
}

std::string Material::getName(){
	return name;
}