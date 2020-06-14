#include "grid.hpp"

Grid::Grid(
	unsigned long _seed,
	unsigned int _size,
	unsigned int _playerLimit,
	std::string _filePath):
	config(_filePath),
	grid(_size,std::vector<std::shared_ptr<Node>>(_size)){
	for(unsigned int x;x<grid.capacity();x++){
		for(unsigned int y;y<grid[x].capacity();y++){
			grid[x][y] = std::make_shared<Node>(
				config.getMaterials(),
				x,y,
				_seed
			);
		}
	}
}

void Grid::Turn(){

}
