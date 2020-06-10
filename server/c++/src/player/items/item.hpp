#ifndef item_h
#define item_h

#include <stdexcept>
#include <string>
#include "constants.hpp"

#include "item.hpp"

class Item {
private:
public:
	virtual unsigned int getMass();
};

#endif
