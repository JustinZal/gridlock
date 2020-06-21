#include "grid.hpp"

Grid::Grid(
	unsigned long _seed,
	unsigned int _size,
	unsigned int _playerCount,
	std::string _file):
	grid(_size,std::vector<std::shared_ptr<Node>>(_size)),
	players(_playerCount){

	for(unsigned int x;x<grid.capacity();x++){
		for(unsigned int y;y<grid[x].capacity();y++){
			grid[x][y] = std::make_shared<Node>(
				x,y,
				_seed,
				materials
			);
		}
	}
}

bool Grid::parseGameMode(std::string _file){
	std::system((std::string("mkdir -p ")+std::string(getpwuid(getuid())->pw_dir)+std::string("/.gridlock/game")).c_str());

	std::ifstream configFile;
	configFile.open(std::string(getpwuid(getuid())->pw_dir)+"/.gridlock/game/"+_file+".json");

	nlohmann::json j;
	configFile >> j;

	configFile.close();

	// if(j.contains("Materials"))
	// 	std::cerr << "1--\n\n";
	return true;
}

void Grid::Turn(){


}
