#ifndef GRIDLOCK_GRID_HPP
#define GRIDLOCK_GRID_HPP

#include <stdexcept>
#include <mutex>
#include "constants.hpp"

#include "node.hpp"

#include "grid.hpp"

class Grid{

private:
	// This mutex synchronizes all access to we socket sessions
	std::mutex mutex_;

	//Node *grid[][]=NULL;
	//std::vector<Location> players;

public:
	Grid(
		GRIDSIZE _size=Normal,
		unsigned int playerExternalItems=4,
		unsigned int _playerInternalItems=20);

	void Populate();

	void Turn();
};

#endif
