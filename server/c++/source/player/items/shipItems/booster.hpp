#ifndef booster_h
#define booster_h

#include <stdexcept>
#include "constants.hpp"

#include "item.hpp"
#include "itemType.hpp"
#include "shipItem.hpp"
#include "internalItem.hpp"

#include "booster.hpp"

class Booster:public ItemType{
	private:
		unsigned int maxPower;
		unsigned int efficiency;

	public:
		Booster();

		unsigned int getMaxPower();

		unsigned int getEfficinecy();

};

class BoosterItem:public Item,public ShipItem{
	private:
		Booster *type;

	public:
		BoosterItem(Booster *_type);
};

#endif
