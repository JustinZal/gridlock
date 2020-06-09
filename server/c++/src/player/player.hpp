#ifndef player_h
#define player_h

#include <stdexcept>
#include <string>

#include "item.hpp"
#include "shipItem.hpp"
#include "constants.hpp"
#include "physicsObject.hpp"
#include "slots.hpp"

#include "player.hpp"

class Player:public PhysicsObject{
private:
	std::string name;
	std::string token;

	Slots externalItems;
	Slots internalItems;

public:
	Player(std::string _name, std::string _token,Slots externalItems, Slots internalItems);

	std::string getName();
	std::string getToken();
};

#endif
