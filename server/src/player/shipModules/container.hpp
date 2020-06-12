#ifndef GRIDLOCK_CONTAINER_HPP
#define GRIDLOCK_CONTAINER_HPP

#include <stdexcept>
#include "constants.hpp"

#include "item.hpp"
#include "itemType.hpp"
#include "module.hpp"
#include "internalItem.hpp"

#include "container.hpp"

class Container:public ItemType{

private:
	unsigned int Volume;

public:
	Container();
};

class ContainerItem:public Module,public InternalItem {

private:
	Container *type;

	// Material *material=NULL;

public:
	ContainerItem(
		Container *_type);
	
	unsigned int getSize() override;
};

#endif
