#include "bullet.hpp"

//Initialize bullet
BulletProjectile::BulletProjectile(Bullet *_type,std::array<Movement,MOVESPERTURN> _moves){
	type=_type;
	moves=_moves;
}

//Get objects action at time (_t)
Action BulletProjectile::getAction(int _t){
	return moves.at(_t);
}

//Mass of the bullet
unsigned int BulletProjectile::getMass(){
	return 1;
}

//Damage the objects gives when coliding
Damage BulletProjectile::giveDamage(){
	return type->getDamage();
}

//Give collision damage (_damage) and output if object was destroyed
bool BulletProjectile::takeDamage(Damage _damage){
	return true;
}