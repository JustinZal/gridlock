#include "deposit.hpp"

Deposit::Deposit(/*Material * _material*/,unsigned int _volume,unsigned int _accessibility){
	//material=_material;
	volume=_volume;
	accessibility=_accessibility;
}

/*Material * getMaterial(){
	return material;
}*/

unsigned int getVolume(){
	return volume;
}

unsigned int getAccessibility(){
	return accessibility;
}