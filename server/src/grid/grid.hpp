#ifndef GRIDLOCK_GRID_HPP
#define GRIDLOCK_GRID_HPP

#include <stdexcept>
#include <mutex>
#include "constants.hpp"

#include "player.hpp"
#include "node.hpp"

#include "grid.hpp"


class Grid{

private:
	// This mutex synchronizes all access to we socket sessions
	std::mutex mutex_;

	std::vector<std::shared_ptr<Player>> players;

	//Node *grid[][]=NULL;

public:
	Grid(
		unsigned int _size=20,
		unsigned int playerExternalItems=4,
		unsigned int _playerInternalItems=20);

	void Populate();

	void Turn();
};

#endif
