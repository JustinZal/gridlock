#include "bullet.hpp"

//Initialize bullet
BulletProjectile::BulletProjectile(Bullet _type){
	type=_type;
}

//Get objects action at time (t)
Action getAction(int t){

}

//Damage the objects gives when coliding
int BulletProjectile::getDamage(){
	return type.damage;
}

//Give collision damage (d) and output if object was destroyed
bool BulletProjectile::colide(unsigned int d){
	return true;
}