#include "rocket.hpp"

//Initialize rocekt
RocketProjectile::RocketProjectile(Rocket _type){
	type=_type;
}

//Get objects action at time (t)
Action getAction(int t){

}

//Damage the objects gives when coliding
int RocketProjectile::getDamage(){
	return type.damage;
}

//Give collision damage (d) and output if object was destroyed
bool RocketProjectile::colide(unsigned int d){
	return true;
}