#ifndef bullet_h
#define bullet_h

#include <stdexcept>
#include <string>
#include <array>
#include "constants.hpp"

#include "item.hpp"
#include "itemType.hpp"
#include "movement.hpp"
#include "damage.hpp"
#include "physicsObject.hpp"

#include "bullet.hpp"

class Bullet:public ItemType{
private:
	Damage damage;
	unsigned int diameter;
public:
	Bullet(Damage _damage);

	Damage getDamage();
	unsigned int getDiameter();
};

class BulletItem:public Item{
private:
	Bullet * type;
public:
};

class BulletProjectile:public PhysicsObject{
private:
	Bullet * type;
	std::array<Movement,MOVESPERTURN> moves;
public:
	BulletProjectile(Bullet *_type,std::array<Movement,MOVESPERTURN> _moves);

	Action getAction(int t) override;
	Damage getDamage() override;
	bool collide(unsigned int d) override;
};

#endif