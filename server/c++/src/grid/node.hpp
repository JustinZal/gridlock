#ifndef node_h
#define node_h

#include <vector>

#include "item.hpp"
#include "player.hpp"
#include "deposit.hpp"

#include "node.hpp"

class Node {
  private:
    std::vector<Deposit> deposits;
    std::vector<Item> items;
    Player * occupier=NULL;

  public:
    Node(std::vector<Deposit> _deposits);
    std::vector<Material> getDeposits();
    std::vector<Item> getItems();
    Player * getOccupier();
    void setOccupier(Player & _occupier);
    void setItems(std::vector<int> _items);
};

#endif
