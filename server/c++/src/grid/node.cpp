#include "node.hpp"

std::vector<Material> Node::getDeposits() {
  return materials;
}

std::vector<Item> Node::getItems() {
  return items;
}

Player * Node::getPlayer() {
  return occupier;
}
