#include "node.hpp"

Node::Node(
	std::vector<Deposit> _deposits){

  //deposits = _deposits;
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