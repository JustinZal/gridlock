#ifndef turn_h
#define turn_h

#include <stdexcept>
#include "constants.h"

#include "turn.h"

class Turn:public Location{
	private:
		std::vector<Move> moves;
};

#endif