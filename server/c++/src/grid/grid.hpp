#ifndef grid_h
#define grid_h

#include <stdexcept>
#include "constants.hpp"

#include "node.hpp"

#include "grid.hpp"

class Grid{
	private:
		//Node *grid[][]=NULL;
		//std::vector<Location> players;

	public:
		Grid(GRIDSIZE _size=Normal,unsigned int playerExternalItems=4,unsigned int _playerInternalItems=20);
		void Populate();
		void Turn();
};

#endif
