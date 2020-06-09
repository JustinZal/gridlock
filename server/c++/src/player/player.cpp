#include "player.hpp"

Player::Player(std::string _name,std::string _token,unsigned int _externalItems,unsigned int _internalItems) : externalItems(_externalItems), internalItems(_internalItems){
  name = _name;
  token = _token;
}

std::string Player::getToken() {
  return token;
}

std::string Player::getName() {
  return name;
}
