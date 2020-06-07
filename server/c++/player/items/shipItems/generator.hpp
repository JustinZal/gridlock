#ifndef generator_h
#define generator_h

#include <stdexcept>
#include "constants.hpp"

#include "itemType.hpp"
#include "shipItem.hpp"
#include "internalItem.hpp"

#include "generator.hpp"

class Generator:public ItemType{
	private:
		unsigned int maxGeneration;
		unsigned int efficiency;

	public:
		void Generator();

};

class GeneratorItem:public Iterm,public ShipItem,public InternalItem{
	private:
		Generator *type;

	public:
		void GeneratorItem(Generator *_type);
};

#endif
