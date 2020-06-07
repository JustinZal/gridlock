#include "player.hpp"

std::string Player::getToken() {
  return token;
}

std::string Player::getName() {
  return name;
}

void Player::Player(
  std::string _name,
  std::string _token,
  Slots _externalItems,
  Slots _internalItems) {
  name = _name;
  token = _token;
  externalItems = _externalItems;
  internalItems = _internalItems;
}