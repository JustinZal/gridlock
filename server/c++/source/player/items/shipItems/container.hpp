#ifndef container_h
#define container_h

#include <stdexcept>
#include "constants.hpp"

#include "itemType.hpp"
#include "shipItem.hpp"
#include "internalItem.hpp"

#include "container.hpp"

class Container:public ItemType{
	private:
		unsigned int Volume;

	public:
		void Container();

};

class ContainerItem:public Iterm,public ShipItem,public InternalItem{
	private:
		Container *type;
		Material *material=NULL;

	public:
		void ContainerItem(Container *_type);
};

#endif
