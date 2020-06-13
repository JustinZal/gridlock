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
	unsigned int _maxX,
	unsigned int _maxY,
	unsigned int _seed): posX(_posX), posY(_posY) {

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