#ifndef shield_h
#define shield_h

#include <stdexcept>
#include "constants.hpp"

#include "item.hpp"
#include "itemType.hpp"
#include "shipItem.hpp"
#include "internalItem.hpp"

#include "shield.hpp"

class Shield:public ItemType{
private:
	unsigned int maxProtection;
	unsigned int maxRechargeRate;
	unsigned int Efficiency;

public:
	Shield(unsigned int _maxProtection,unsigned int _maxRechargeRate,unsigned int _Efficiency);
};

class ShieldItem: public Item, public ShipItem, public InternalItem {
private:
	Shield *type;
	unsigned int protection;

public:
	ShieldItem(Shield *_type);

	unsigned int getProtection();

	bool dryRecharge();

	bool recharge();
};

#endif
