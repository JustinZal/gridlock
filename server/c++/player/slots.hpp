#include <vector>
#include "item.hpp"

class Slots {
  private:
    unsigned int size;
    std::vector<ShipItem> slots;

  public:
    bool addItem(ShipItem item) {
      if (!dryAddItem(item)) {
        return false;
      }

      slots.push_back(item);
      return true;
    };

    Item * getItem(unsigned int itemId) {
      if (!dryGetItem(itemId)) {
        return null;
      }

      return &slots[itemId];
    };

    std::vector<ShipItem> * getItems() {
      return &slots;
    };

    bool dryAddItem(ShipItem item) {
      const len = item.size();
      unsigned int occupied_slots = 0;

      for (int i = 0; i < len; i++) {
        occupied_slots += slots[i].getSize();
      };

      return (item.getSize() + occupied_slots) <= size
    };

    bool dryGetItem(unsigned int itemId) {
      return itemId <= (slots.size() - 1)
    };

    void Slots(unsigned int _size) {
      size = _size;
    };
}
