#ifndef slots_h
#define slots_h

#include <vector>
#include "constants.hpp"

#include "shipItem.hpp"

#include "slots.hpp"

template <class _TYPE>
class Slots{
  private:
    unsigned int size;
    std::vector<_TYPE> slots;

  public:
    bool addItem(_TYPE item);
    ShipItem * getItem(unsigned int itemId);
    std::vector<Item> * getItems();
    bool dryAddItem(ShipItem item);
    bool dryGetItem(unsigned int itemId);
    Slots(unsigned int _size);
};

#endif