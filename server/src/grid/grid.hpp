#ifndef GRIDLOCK_GRID_HPP
#define GRIDLOCK_GRID_HPP

#include <stdexcept>
#include <mutex>
#include "constants.hpp"

#include "player.hpp"
#include "node.hpp"

#include "grid.hpp"


template <unsigned int _SIZE>
class Grid{

private:
	// This mutex synchronizes all access to we socket sessions
	std::mutex mutex_;

	// List of players
	std::vector<std::shared_ptr<Player>> players;

	// Array of nodes, main grid
	std::array<std::shared_prt<Node>,_SIZE> grid;

public:
	Grid(
		unsigned long _seed,
		unsigned int _playerExternalItems=4,
		unsigned int _playerInternalItems=20);

	void Populate();

	void Turn();
};

#endif
