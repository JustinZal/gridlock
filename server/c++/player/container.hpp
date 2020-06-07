#ifndef container_h
#define container_h

#include <stdexcept>
#include "constants.hpp"

#include "container.hpp"

class Container{
	private:
		int Volume;

	public:
		void Container();

};

class ContainerItem:public Item,public InternalItem{
	private:
		Container *type;
		Material *material=NULL;

	public:
		void ContainerItem(Container *_type);
};

#endif
