#ifndef GRIDLOCK_SLOTS_HPP
#define GRIDLOCK_SLOTS_HPP

#include <vector>
#include "constants.hpp"

#include "module.hpp"

#include "slots.hpp"

template <class _TYPE>
class Slots{
  private:
    unsigned int size;

  	std::vector<_TYPE> slots;

  public:
    bool addItem(
        _TYPE item){
		if (!dryAddItem(item)) {
			return false;
		}

		slots.push_back(item);
		return true;

    }

    Module * getItem(
        unsigned int itemId){
		if (!dryGetItem(itemId)) {
			return NULL;
		}

		return &slots[itemId];
    }

    std::vector<Item> * getItems(){
		return &slots;
    }

    bool dryAddItem(
        Module item){
		const unsigned int len=item.getSize();
		unsigned int occupied_slots=0;

		for (Module element:slots){
			occupied_slots+=element.getSize();
		}

		return (item.getSize() + occupied_slots) <= size;
    }

    bool dryGetItem(
        unsigned int itemId){
		return itemId <= (slots.size() - 1);
    }
//TEMPLATE DEFINITION AND DECLARATION CANNOT BE SEPARATED LMAO;
    Slots(
        unsigned int _size){
    	size = _size;
    }
};

#endif