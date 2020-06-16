#include "node.hpp"
#include <boost/random.hpp>
#include <random>

#define MAX_CLUSTER_SIZE 5

Node::Node(
		const unsigned int _posX,
		const unsigned int _posY,
		unsigned int _seed,
        std::vector<std::shared_ptr<Material>> _materials):
		posX(_posX),
		posY(_posY){

	for(auto const& material:_materials){
		for(long x=posX-(MAX_CLUSTER_SIZE/2);x<posX+(MAX_CLUSTER_SIZE/2);x++){
			for(long y=posY-(MAX_CLUSTER_SIZE/2);y<posY+(MAX_CLUSTER_SIZE/2);y++){
				if(isClusterOrigin(x,y,_seed,material)){
					debris.push_back(std::make_shared<Deposit>(
						material,
						depositVolume(_posX,posY,_seed,x,y,material),
						20));
				}
			}
		}
	}

}

bool Node::isClusterOrigin(
    unsigned int _posX,
    unsigned int _posY,
   	unsigned int _seed,
    std::shared_ptr<Material> _material){
	return false;
}

unsigned int Node::depositVolume(
    unsigned int _posX,
    unsigned int _posY,
    unsigned int _seed,
    long _originPosX,
    long _originPosY,
    std::shared_ptr<Material> _material){
	return 1;
}

std::shared_ptr<OccupyingObject> Node::getOccupant(){

  return occupant;
}

void Node::setOccupant(
	std::shared_ptr<OccupyingObject> _occupant){

	occupant = _occupant;
}

std::vector<std::shared_ptr<NonOccupyingObject>> Node::getObjects(){

	return objects;
}

std::vector<std::shared_ptr<NonPhysicsObject>> Node::getDebris(){

	return debris;
}