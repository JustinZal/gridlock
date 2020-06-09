#ifndef rocket_h
#define rocket_h

#include <stdexcept>
#include <string>
#include <array>
#include "constants.hpp"

#include "item.hpp"
#include "itemType.hpp"
#include "movement.hpp"
#include "damage.hpp"
#include "physicsObject.hpp"

#include "rocket.hpp"

class Rocket:public ItemType{
private:
	Damage damage;
	unsigned int diameter;
public:
	Rocket(Damage _damage);

	Damage getDamage();
	unsigned int getDiameter();
};

class RocketItem:public Item{
private:
	Rocket * type;
public:
};

class RocketProjectile:public PhysicsObject{
private:
	Rocket * type;
	std::array<Movement,MOVESPERTURN> moves;
public:
	RocketProjectile(Rocket *_type,std::array<Movement,MOVESPERTURN> _moves);

	Action getAction(int t) override;
	Damage getDamage() override;
	bool collide(unsigned int d) override;
};

#endif