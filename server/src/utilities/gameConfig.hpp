#ifndef GRIDLOCK_GAMECONFIG_HPP
#define GRIDLOCK_GAMECONFIG_HPP

#include "material.hpp"

#include "gameConfig.hpp"

class GameConfig{
private:

	std::Vector<std::shared_ptr<Material>> materials;

public:
	GameConfig(std::string _filePath);

	std::Vector<std::shared_ptr<Material>> getMaterials();

	//getBlueprints();
}

#endif