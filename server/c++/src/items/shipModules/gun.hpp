#ifndef gun_h
#define gun_h

#include <stdexcept>
#include <string>
#include "constants.hpp"

#include "item.hpp"
#include "itemType.hpp"
#include "module.hpp"

#include "gun.hpp"

class Gun:public ItemType{
private:
	unsigned int magazineSize;
	unsigned int maxPower;
	unsigned int efficiency;
	unsigned int projectileSize;
public:
	Gun();
};

class GunItem:public Module{
private:
	Gun *type;

public:
	GunItem(Gun *_type);
	unsigned int getSize() override;
};

#endif