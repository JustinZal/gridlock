#include "bullet.hpp"

//Initialize bullet
BulletProjectile::BulletProjectile(Bullet *_type,std::array<Movement,MOVESPERTURN> _moves){
	type=_type;
	moves=_moves;
}

//Get objects action at time (t)
Action BulletProjectile::getAction(int t){
	return moves.at(t);
}

//Damage the objects gives when coliding
Damage BulletProjectile::getDamage(){
	return type->getDamage();
}

//Give collision damage (d) and output if object was destroyed
bool BulletProjectile::collide(unsigned int d){
	return true;
}