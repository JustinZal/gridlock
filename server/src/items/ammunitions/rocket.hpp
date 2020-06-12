#ifndef GRIDLOCK_ROCKET_HPP
#define GRIDLOCK_ROCKET_HPP

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
	Rocket(
		Damage _damage);

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
	RocketProjectile(
		Rocket *_type,std::array<Movement,
		MOVESPERTURN> _moves);

	Action getAction(
		int _t) override;

	unsigned int getMass() override;
	
	Damage giveDamage() override;

	bool takeDamage(
		Damage _damage) override;
};

#endif