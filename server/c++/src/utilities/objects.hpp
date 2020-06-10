#ifndef shipitems_h
#define shipitems_h

#include <stdexcept>
#include <array>

#include "rocket.hpp"
#include "bullet.hpp"
#include "shield.hpp"
#include "generator.hpp"
#include "booster.hpp"
#include "container.hpp"
#include "material.hpp"
#include "blueprint.hpp"

#include "constants.hpp"


// Ammunitions

// Rocket rockets{};
// Bullet bullets{};


// Ship items

// Shield shields{};
// Generator generators{};
// Booster boosters{};
// Container containers{};


// Materials
std::array<Material *,60> materials {
	new Material("Water"),
	new Material("Methane"),
	new Material("Silica"),
	new Material("Copper ore"),
	new Material("Iron ore"),
	new Material("Gold ore"),

	new Material("Silicon"),
	new Material("Iron"),
	new Material("Copper"),
	new Material("Hydrogen"),
	new Material("Oxygen"),
	new Material("Gold")
};

#endif
