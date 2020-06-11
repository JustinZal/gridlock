#ifndef fabricator_h
#define fabricator_h

#include <stdexcept>
#include <string>
#include <vector>
#include "constants.hpp"

#include "blueprint.hpp"
#include "material.hpp"

#include "fabricator.hpp"

class Fabricator{
private:
public:
	bool research();
	bool fabricate();
};

#endif