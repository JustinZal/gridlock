#ifndef GRIDLOCK_BULLET_HPP
#define GRIDLOCK_BULLET_HPP

#include <stdexcept>
#include <string>
#include <array>
#include "constants.hpp"

#include "item.hpp"
#include "itemType.hpp"
#include "movement.hpp"
#include "damage.hpp"
#include "physicsObject.hpp"
#include "nonOccupyingObject.hpp"

#include "bullet.hpp"

class Bullet:public ItemType{

private:
	Damage damage;
	unsigned int diameter;
	
public:
	Bullet(
		Damage _damage);

	Damage getDamage();

	unsigned int getDiameter();
};

class BulletItem:public Item{
	
private:
	Bullet * type;

public:
};

class BulletProjectile:public NonOccupyingObject{

private:
	Bullet * type;
	std::array<Movement,MOVESPERTURN> moves;

public:
	BulletProjectile(
		Bullet *_type,
		std::array<Movement,
		MOVESPERTURN> _moves);

	Action getAction(
		int _t) override;

	unsigned int getMass() override;

	Damage giveDamage() override;

	bool takeDamage(
		Damage _damage) override;
};

#endif