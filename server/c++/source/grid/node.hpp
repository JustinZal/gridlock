#include <vector>

#include "node.hpp"

class Node {
  private:
    std::vector<Deposit> deposits;
    std::vector<Item> items;
    Player * occupier = NULL;

  public:
    std::vector<Material> getDeposits();
    std::vector<Item> getItems();
    Player * getPlayer();
}
