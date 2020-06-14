#ifndef GRIDLOCK_GRIDCONFIG_HPP
#define GRIDLOCK_GRIDCONFIG_HPP

#include <iostream>
#include <vector>
#include <memory>

#include "json.hpp"
#include "material.hpp"
#include "blueprint.hpp"

#include "gridConfig.hpp"

class GridConfig{
private:

	std::vector<std::shared_ptr<Material>> materials;

	std::vector<std::shared_ptr<Blueprint>> blueprints;

public:
	GridConfig(std::string _filePath);

	std::vector<std::shared_ptr<Material>> getMaterials();

	std::vector<std::shared_ptr<Blueprint>> getBlueprints();
};

#endif