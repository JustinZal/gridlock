#include "gridConfig.hpp"

GridConfig::GridConfig(
	std::string _filePath){

}

std::vector<std::shared_ptr<Material>> GridConfig::getMaterials(){

	return materials;
}

std::vector<std::shared_ptr<Blueprint>> GridConfig::getBlueprints(){

	return blueprints;
}