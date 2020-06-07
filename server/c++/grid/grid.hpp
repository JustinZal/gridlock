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
		void Grid(GRIDSIZE size);
		void Turn();
};

#endif
