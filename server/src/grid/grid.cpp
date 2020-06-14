#include "grid.hpp"

Grid::Grid(
	unsigned long _seed,
	unsigned int _size,
	unsigned int _playerLimit,
	std::string _file):
	grid(_size,std::vector<std::shared_ptr<Node>>(_size)){
	std::ifstream file(_file);

	nlohmann::json j;
	file >> j;
	if(j["Materials"]){
		std::cerr << "test\n\n";
	}

	for(unsigned int x;x<grid.capacity();x++){
		for(unsigned int y;y<grid[x].capacity();y++){
			grid[x][y] = std::make_shared<Node>(
				materials,
				x,y,
				_seed
			);
		}
	}
}

void Grid::Turn(){

}
