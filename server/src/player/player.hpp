#ifndef GRIDLOCK_PLAYER_HPP
#define GRIDLOCK_PLAYER_HPP

#include <stdexcept>
#include <string>
#include <array>
#include "constants.hpp"

#include "item.hpp"
#include "module.hpp"
#include "constants.hpp"
#include "physicsObject.hpp"
#include "occupyingObject.hpp"
#include "fabricator.hpp"
#include "slots.hpp"

#include "player.hpp"

class Player:public OccupyingObject{

private:

	std::string name;

	std::string token;

	int credits;

	unsigned int posX;

	unsigned int posY;

	Fabricator fabricator();

	Slots<Item> externalItems;

	Slots<InternalItem> internalItems;

public:
	Player(
		std::string _name,
		std::string _token,
		unsigned int _externalItems,
		unsigned int _internalItems);

	std::string getName();

	std::string getToken();

	unsigned int getPosX();

	unsigned int getPosY();

	int getCredits();


	Action getAction(
		int _t) override;

	unsigned int getMass() override;

	Damage giveDamage() override;

	bool takeDamage(
		Damage _damage) override;
};

#endif
