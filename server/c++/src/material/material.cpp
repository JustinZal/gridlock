#include "material.hpp"

Material::Material(std::string _name){
	name=_name;
}

std::string Material::getName(){
	return name;
}