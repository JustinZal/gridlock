#ifndef GRIDLOCK_GRID_HPP
#define GRIDLOCK_GRID_HPP

#include <stdexcept>
#include <iostream>
#include <fstream>
#include <memory>
#include <mutex>
#include <vector>
#include <json.hpp>

#include "constants.hpp"

#include "player.hpp"
#include "node.hpp"
#include "material.hpp"
#include "blueprint.hpp"
#include "module.hpp"
#include "item.hpp"

#include "grid.hpp"

class Grid{

private:
	// This mutex synchronizes all access to we socket sessions
	std::mutex mutex_;

	// List of players
	std::vector<std::shared_ptr<Player>> players;

	// Array of nodes, main grid
	std::vector<std::vector<std::shared_ptr<Node>>> grid;

	//---- Grid mode

	std::vector<std::shared_ptr<Material>> materials;

	std::vector<std::shared_ptr<Blueprint>> blueprints;

	std::vector<std::shared_ptr<Module>> modules;

	std::vector<std::shared_ptr<Item>> items;
	

public:
	Grid(
		unsigned long _seed,
		unsigned int _size=20,
		unsigned int _playerLimit=4,
		std::string _file="standard.json");

	void Turn();
};

#endif
