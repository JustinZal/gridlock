#include "slots.hpp"

template <class _TYPE>
bool Slots<_TYPE>::addItem(_TYPE item) {
  if (!dryAddItem(item)) {
    return false;
  }

  slots.push_back(item);
  return true;
}

template <class _TYPE>
Module * Slots<_TYPE>::getItem(unsigned int itemId) {
  if (!dryGetItem(itemId)) {
    return NULL;
  }

  return &slots[itemId];
}

template <class _TYPE>
std::vector<Item> * Slots<_TYPE>::getItems() {
  return &slots;
}

template <class _TYPE>
bool Slots<_TYPE>::dryAddItem(Module item) {
  const unsigned int len=item.getSize();
  unsigned int occupied_slots=0;

  for (Module element:slots){
    occupied_slots+=element.getSize();
  }

  return (item.getSize() + occupied_slots) <= size;
}

template <class _TYPE>
bool Slots<_TYPE>::dryGetItem(unsigned int itemId) {
  return itemId <= (slots.size() - 1);
}

template <class _TYPE>
Slots<_TYPE>::Slots(unsigned int _size) {
  size = _size;
}
