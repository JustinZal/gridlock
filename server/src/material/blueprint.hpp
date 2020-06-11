#ifndef blueprint_h
#define blueprint_h

#include <stdexcept>
#include <string>
#include <vector>
#include "constants.hpp"

#include "itemType.hpp"
#include "material.hpp"
#include "container.hpp"

#include "blueprint.hpp"

class Blueprint{
private:
	std::vector<Material> materials;
public:
	Blueprint();
	bool Craft();
};

#endif