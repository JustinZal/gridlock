#ifndef shipitem_h
#define shipitem_h

#include <stdexcept>
#include "constants.hpp"

#include "item.hpp"

#include "shipItem.hpp"

class ShipItem:public Item{
private:
public:
	virtual unsigned int getSize();
};

#endif
