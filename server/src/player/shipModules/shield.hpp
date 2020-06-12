#ifndef GRIDLOCK_SHIELD_HPP
#define GRIDLOCK_SHIELD_HPP

#include <stdexcept>
#include "constants.hpp"

#include "item.hpp"
#include "itemType.hpp"
#include "module.hpp"
#include "internalItem.hpp"

#include "shield.hpp"

class Shield:public ItemType{

private:
	unsigned int maxProtection;

	unsigned int maxRechargeRate;

	unsigned int Efficiency;

public:
	Shield(
		unsigned int _maxProtection,
		unsigned int _maxRechargeRate,
		unsigned int _Efficiency);
};

class ShieldItem:public Module,public InternalItem{

private:
	Shield *type;

	unsigned int protection;

public:
	ShieldItem(
		Shield *_type);

	unsigned int getProtection();

	unsigned int getSize() override;

	bool dryRecharge();

	bool recharge();
};

#endif
