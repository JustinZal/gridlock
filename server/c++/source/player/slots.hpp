#include <vector>
#include "item.hpp"

#include "slots.hpp"

class Slots {
  private:
    unsigned int size;
    std::vector<ShipItem> slots;

  public:
    bool addItem(ShipItem item);
    ShipItem * getItem(unsigned int itemId);
    std::vector<ShipItem> * getItems();
    bool dryAddItem(ShipItem item);
    bool dryGetItem(unsigned int itemId);
    void Slots(unsigned int _size);
