#include "node.hpp"

std::vector<Deposit> Node::getDeposits() {
  return deposits;
}

std::vector<Item> Node::getItems() {
  return items;
}

Player * Node::getOccupier() {
  return occupier;
}

void Node::setOccupier(Player *_occupier) {
  occupier = _occupier;
}

void Node::setItems(std::vector<Item> _items) {
  items.insert(_items.end(),_items.begin(),_items.end());
}

Node::Node(std::vector<Deposit> _deposits) {
  deposits = _deposits;
}
