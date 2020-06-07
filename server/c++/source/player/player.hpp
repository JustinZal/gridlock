#ifndef player_h
#define player_h

#include <stdexcept>
#include <string>

#include "constants.hpp"
#include "object.hpp"
#include "player.hpp"
#include "slots.hpp"

class Player:public object {
	public:
		std::string getToken();
		std::string getName();
		void Player(
			std::string _name, std::string _token,
			Slots externalItems, Slots internalItems
		);

	private:
		std::string token;
		std::string name;
		Slots externalItems;
		Slots internalItems;
};

#endif
