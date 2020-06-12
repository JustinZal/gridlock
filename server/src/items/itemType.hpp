#ifndef GRIDLOCK_ITEMTYPE_HPP
#define GRIDLOCK_ITEMTYPE_HPP

#include <stdexcept>
#include <vector>
#include "constants.hpp"

#include "item.hpp"

#include "itemType.hpp"

class ItemType{

private:

public:
	virtual unsigned int getName(){
		return 0;};

	virtual unsigned int getMass(){
		return 0;};
};

#endif
