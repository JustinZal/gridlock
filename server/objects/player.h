#ifndef player_h
#define player_h

#include <stdexcept>
#include "constants.h"

#include "object.h"

class Player:public object{
	std::string token;
	std::string name;
	std::vector<Container> conatiners;
};

#endif