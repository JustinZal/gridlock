#include "rocket.hpp"

//Initialize Rocket
RocketProjectile::RocketProjectile(Rocket *_type,std::array<Movement,MOVESPERTURN> _moves){
	type=_type;
	moves=_moves;
}

//Get objects action at time (t)
Action RocketProjectile::getAction(int t){
	return moves.at(t);
}

//Damage the objects gives when coliding
Damage RocketProjectile::getDamage(){
	return type->getDamage();
}

//Give collision damage (d) and output if object was destroyed
bool RocketProjectile::collide(unsigned int d){
	return true;
}