#include "slots.hpp"

bool Slots::addItem(ShipItem item) {
  if (!dryAddItem(item)) {
    return false;
  }

  slots.push_back(item);
  return true;
}

Item * Slots::getItem(unsigned int itemId) {
  if (!dryGetItem(itemId)) {
    return null;
  }

  return &slots[itemId];
}

std::vector<ShipItem> * Slots::getItems() {
  return &slots;
}

bool Slots::dryAddItem(ShipItem item) {
  const len = item.size();
  unsigned int occupied_slots = 0;

  for (int i = 0; i < len; i++) {
    occupied_slots += slots[i].getSize();
  }

  return (item.getSize() + occupied_slots) <= size
}

bool Slots::dryGetItem(unsigned int itemId) {
  return itemId <= (slots.size() - 1);
}

bool Slots::Slots(unsigned int _size) {
  size = _size;
}
