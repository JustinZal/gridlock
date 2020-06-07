#ifndef grid_h
#define grid_h

#include <stdexcept>
#include "constants.hpp"

#include "grid.hpp"

class Grid{
	private:
		Object *grid[][]=NULL;
		std::vector<Location> players;

	public:
		void Grid(GRIDSIZE size=Normal,unsigned int playerExternalItems=4,unsigned int playerInternalItems=20);
		void Turn();
};

#endif
