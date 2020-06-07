#ifndef generator_h
#define generator_h

#include <stdexcept>
#include "constants.hpp"

#include "generator.hpp"

class Generator{
	private:
		int maxGeneration;
		int efficiency;

	public:
		void Generator();

};

class GeneratorItem:public Item,public InternalItem{
	private:
		Generator *type;

	public:
		void GeneratorItem(Generator *_type);
};

#endif
