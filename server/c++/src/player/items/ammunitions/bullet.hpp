#ifndef bullet_h
#define bullet_h

#include <stdexcept>
#include <string>
#include "constants.hpp"

#include "item.hpp"
#include "itemType.hpp"
#include "movement.hpp"
#include "damage.hpp"
#include "physicsObject.hpp"

class Bullet:public ItemType{
private:
	Damage damage;
	unsigned int diameter;
public:
	Bullet(Damage _damage);
};

class BulletItem:public Item{
private:
	Bullet * type;
public:
};

class BulletProjectile:public PhysicsObject{
private:
	Bullet * type;
	Movement moves[MOVESPERTURN];
public:
	BulletProjectile();
};

#endif