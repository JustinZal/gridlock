#include "node.hpp"

Node::Node(
	std::vector<std::shared_ptr<Material>> _Material,
	unsigned int _posX,
	unsigned int _posY,
	unsigned long _seed){


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

std::vector<std::shared_ptr<NonPhysicsObject>> Node::getDebrees(){

	return debrees;
}