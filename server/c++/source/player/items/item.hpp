#ifndef item_h
#define item_h

#include <stdexcept>
#include <string>
#include "constants.hpp"

#include "item.hpp"

class Item{
	private:
		Item();
		unsigned int size;
		std::string Name;

	public:
		unsigned int getSize();
};

#endif
