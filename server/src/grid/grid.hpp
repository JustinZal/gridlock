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

	// List of players
	std::vector<std::shared_ptr<Player>> players;

	// Array of nodes, main grid
	std::vector<std::shared_ptr<Node>> grid;

public:
	Grid(
		unsigned int _size,
		unsigned int _playerLimit,
		unsigned long _seed);

	void Populate();

	void Turn();
};

#endif
