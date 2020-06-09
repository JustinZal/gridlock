#include "node.hpp"

std::vector<Material> Node::getDeposits() {
  return materials;
}

std::vector<Item> Node::getItems() {
  return items;
}

Player * Node::getOccupier() {
  return occupier;
}

void Node::setOccupier(Player & _occupier) {
  occupier = _occupier;
}

void Node::setItems(std::vector<int> _items) {
  items = _items;
}
