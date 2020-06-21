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
        _TYPE item);

    Module * getItem(
        unsigned int itemId);

    std::vector<Item> * getItems();

    bool dryAddItem(
        Module item);

    bool dryGetItem(
        unsigned int itemId);
//TEMPLATE DEFINITION AND DECLARATION CANNOT BE SEPARATED LMAO;
    Slots(
        unsigned int _size){
    	size = _size;
    }
};

#endif