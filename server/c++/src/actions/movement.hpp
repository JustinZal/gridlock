#ifndef movement_h
#define movement_h

#include <stdexcept>
#include <string>
#include "constants.hpp"

#include "action.hpp"

#include "movement.hpp"

class Movement:public Action{
private:
	DIRECTION Direction;
public:
	Movement();
	Movement(DIRECTION _dircetion);
	bool dryExecute() override;
	bool execute() override;
};

#endif