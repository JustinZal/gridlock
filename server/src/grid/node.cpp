#include "node.hpp"
#include <boost/random.hpp>
#include <random>
Node::Node(
		const unsigned int _posX,
		const unsigned int _posY) : posX(_posX), posY(_posY){}

Node::Node(
	std::vector<std::shared_ptr<Material>> _Material,
	const unsigned int _posX,
	const unsigned int _posY,
	unsigned int _seed):
	posX(_posX),
	posY(_posY) {

	std::mt19937 rand_eng(_seed);
	//for every material in the construction material vector
	for( auto& mat_ptr : _Material){
		//if the probability is greater than the threshhold, add a new material to the debris
		//this material will be a "core", it will have the highest volume value but also a higher accessibility

		unsigned int p =   rand_eng() % ABUNDANCE_CAP ;

		if (p >= mat_ptr->getAbundance() ){

		}
	}

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