#ifndef GRIDLOCK_GRID_HPP
#define GRIDLOCK_GRID_HPP

#include <stdexcept>
#include <iostream>
#include <memory>
#include <mutex>
#include <vector>

#include "constants.hpp"

#include "gridConfig.hpp"
#include "player.hpp"
#include "node.hpp"

#include "grid.hpp"

class Grid{

private:
	// This mutex synchronizes all access to we socket sessions
	std::mutex mutex_;

	GridConfig config;

	// List of players
	std::vector<std::shared_ptr<Player>> players;

	// Array of nodes, main grid
	std::vector<std::vector<std::shared_ptr<Node>>> grid;

public:
	Grid(
		unsigned long _seed,
		unsigned int _size=20,
		unsigned int _playerLimit=4,
		std::string _filePath="standard.json");

	void Turn();
};

#endif
