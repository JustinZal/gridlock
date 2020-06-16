#include "deposit.hpp"

Deposit::Deposit(
	std::shared_ptr<Material> _material,
	unsigned int _volume,
	unsigned int _accessibility){
	
	material=_material;
	volume=_volume;
	accessibility=_accessibility;
}

/*Material * getMaterial(){
	return material;
}*/

unsigned int Deposit::getVolume(){
	return volume;
}

unsigned int Deposit::getAccessibility(){
	return accessibility;
}