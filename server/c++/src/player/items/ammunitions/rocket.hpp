#ifndef rocket_h
#define rocket_h

#include <stdexcept>
#include <string>
#include "constants.hpp"

#include "item.hpp"
#include "itemType.hpp"
#include "physicsObject.hpp"

#include "rocket.hpp"

class Rocket:public ItemType{
private:
	Damage dmagae;
	unsigned int diameter;
public:
	Rocket(Damage _damage);
};

class RocketItem:public Item{
private:
	Rocket * type;
public:
};

class RocketProjectile:public PhysicsObject{
private:
	Rocket * type;
	Movement moves[MOVESPERTURN];
public:
	RocketProjectile();
};

#endif