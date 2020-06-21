#include "player.hpp"

Player::Player(std::string _name,std::string _token,unsigned int _externalItems,unsigned int _internalItems) : externalItems(_externalItems), internalItems(_internalItems){
 	name=_name;
 	token=_token;
}

std::string Player::getToken() {
 	return token;
}

std::string Player::getName() {
	return name;
}

// Action Player::getAction(int _t){

// }

//Mass of the bullet
unsigned int Player::getMass(){
	return 100;
}

Damage Player::giveDamage(){
	return Damage{10,16,18,24};
}

// bool Player::takeDamage(Damage _damage){

// }
unsigned int Player::getPosX(){
	return posY;
}

unsigned int Player::getPosY(){
	return posY;
}

int Player::getCredits(){
	return credits;
}