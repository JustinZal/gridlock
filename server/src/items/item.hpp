#ifndef GRIDLOCK_ITEM_HPP
#define GRIDLOCK_ITEM_HPP

#include <stdexcept>
#include <string>
#include "constants.hpp"

#include "item.hpp"

class Item {
	
private:

public:
	virtual unsigned int getMass(){
		return 0;};
};

#endif
