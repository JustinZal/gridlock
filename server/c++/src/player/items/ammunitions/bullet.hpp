#ifndef bullet_h
#define bullet_h

#include <stdexcept>
#include <string>
#include "constants.hpp"

#include "item.hpp"
#include "itemType.hpp"
#include "damage.hpp"
#include "physicsObject.hpp"

class Bullet:public ItemType{
private:
	Damage damage;
public:
	Bullet();
};

class BulletItem:public Item{
private:
	Bullet * type;
public:
};

class BulletProjectile:public PhysicsObject{
private:
	Bullet * type;
public:
	BulletProjectile();
};

#endif