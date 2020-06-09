#ifndef player_h
#define player_h

#include <stdexcept>
#include <string>
#include "constants.hpp"

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
	Player(std::string _name,std::string _token,unsigned int _externalItems,unsigned int _internalItems);

	std::string getName();
	std::string getToken();

	Action getAction(int t) override;
	Damage getDamage() override;
	bool collide(unsigned int d) override;
};

#endif
