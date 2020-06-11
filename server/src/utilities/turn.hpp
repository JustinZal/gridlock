#ifndef turn_h
#define turn_h

#include <stdexcept>
#include "constants.hpp"

#include "turn.hpp"

class Turn:public Location{
	private:
		std::vector<Move> moves;
};

#endif
