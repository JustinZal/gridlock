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
    std::vector<std::shared_ptr<NonPhysicsObject>> debrees;

  public:
    Node(
        std::vector<std::shared_ptr<Material>> _materials,
        unsigned int _posX,
        unsigned int _posY,
        unsigned long _seed);

    std::shared_ptr<OccupyingObject> getOccupant();

    void setOccupant(
        std::shared_ptr<OccupyingObject> _occupant);

    std::vector<std::shared_ptr<NonOccupyingObject>> getObjects();

    std::vector<std::shared_ptr<NonPhysicsObject>> getDebrees();
};

#endif
