#ifndef generator_h
#define generator_h

#include <stdexcept>
#include "constants.hpp"


#include "item.hpp"
#include "itemType.hpp"
#include "shipItem.hpp"
#include "internalItem.hpp"

#include "generator.hpp"

class Generator:public ItemType{
private:
	unsigned int maxGeneration;
	unsigned int efficiency;

public:
	Generator();
};

class GeneratorItem:public Item,public ShipItem,public InternalItem{
private:
	Generator *type;

public:
	GeneratorItem(Generator *_type);
};

#endif
