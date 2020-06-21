#include "player.hpp"
#include <memory>
#include <iostream>
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

std::unique_ptr<Action> Player::getAction(int _t){
	auto a = std::make_unique<TempAction>();
	return a;
 }


//Mass of the bullet
unsigned int Player::getMass(){
	return 100;
}

Damage Player::giveDamage(){
	return Damage{10,16,18,24};
}

bool Player::takeDamage(Damage _damage){
	return true;

 }
unsigned int Player::getPosX(){
	return posY;
}

unsigned int Player::getPosY(){
	return posY;
}

int Player::getCredits(){
	return credits;
}