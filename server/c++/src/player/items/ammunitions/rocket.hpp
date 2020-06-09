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
public:
};

class RocketItem:public Item{
private:
public:
};

class RocketProjectile:public PhysicsObject{
private:
public:
};

#endif