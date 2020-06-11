#include "rocket.hpp"

//Initialize Rocket
RocketProjectile::RocketProjectile(Rocket *_type,std::array<Movement,MOVESPERTURN> _moves){
	type=_type;
	moves=_moves;
}

//Get objects action at time (_t)
Action RocketProjectile::getAction(int _t){
	return moves.at(_t);
}

//Mass of the rocket
unsigned int RocketProjectile::getMass(){
	return 1;
}

//Damage the objects gives when coliding
Damage RocketProjectile::giveDamage(){
	return type->getDamage();
}

//Give collision damage (_damage) and output if object was destroyed
bool RocketProjectile::takeDamage(Damage _damage){
	return true;
}