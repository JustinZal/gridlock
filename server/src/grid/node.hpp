#ifndef GRIDLOCK_NODE_HPP
#define GRIDLOCK_NODE_HPP

#include <vector>

#include "item.hpp"
#include "player.hpp"
#include "deposit.hpp"
#include "material.hpp"
#include "module.hpp"
#include "nonOccupyingObject.hpp"
#include "nonPhysicsObject.hpp"
#include "occupyingObject.hpp"
#include "player.hpp"

#include "node.hpp"

class Node {

  private:
    //Occupant of node (eg: Player)
    std::shared_ptr<OccupyingObject> occupant=nullptr;

    //List of objects in node (eg: Bullet, Rocket)
    std::vector<std::shared_ptr<NonOccupyingObject>> objects;

    //List of dropable items and deposits
    std::vector<std::shared_ptr<NonPhysicsObject>> debris;

    const unsigned int posX;

    const unsigned int posY;


    //Base Node constructor posX and posY not currently implemented
  public:
	Node(
		unsigned int _posX,
		unsigned int _posY);
	/**
	 *
	 * @param _Material a vector of pointers pointing to the material that will be harvested
	 * @param _posX x coord of node
	 * @param _posY y coord of node
	 * @param _maxX x dimension size of grid
	 * @param _maxY y dimension size of grid
	 * @param _seed the randomized seed
	 */

    Node(
        std::vector<std::shared_ptr<Material>> _Material,
        const unsigned int _posX,
        const unsigned int _posY,
        unsigned int _seed);

    std::shared_ptr<OccupyingObject> getOccupant();

    void setOccupant(
        std::shared_ptr<OccupyingObject> _occupant);

    std::vector<std::shared_ptr<NonOccupyingObject>> getObjects();

    std::vector<std::shared_ptr<NonPhysicsObject>> getDebris();
};

#endif
