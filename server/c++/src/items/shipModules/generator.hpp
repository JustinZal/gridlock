#ifndef generator_h
#define generator_h

#include <stdexcept>
#include "constants.hpp"

#include "item.hpp"
#include "itemType.hpp"
#include "module.hpp"
#include "internalItem.hpp"

#include "generator.hpp"

class Generator:public ItemType{
private:
	unsigned int maxGeneration;
	unsigned int efficiency;

public:
	Generator();
};

class GeneratorItem:public Module,public InternalItem{
private:
	Generator *type;

public:
	GeneratorItem(Generator *_type);
	unsigned int getSize() override;
};

#endif
