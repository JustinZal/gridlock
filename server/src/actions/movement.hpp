#ifndef GRIDLOCK_MOVEMENT_HPP
#define GRIDLOCK_MOVEMENT_HPP

#include <stdexcept>
#include <string>
#include "constants.hpp"

#include "action.hpp"

#include "movement.hpp"

class Movement:public Action:public Action{
	
private:
	DIRECTION Direction;
	
public:
	Movement();
	Movement(DIRECTION _dircetion);
	bool dryExecute() override;
	bool execute() override;
};

#endif