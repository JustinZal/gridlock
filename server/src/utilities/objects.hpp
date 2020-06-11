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
// const std::array<Rocket *,60> ROCKETS {};
// const std::array<Bullet *,60> BULLETS {};

// Ship items
// const std::array<Shield *,60> SHIELDS {};
// const std::array<Generator *,60> GENERATORS {};
// const std::array<Booster *,60> BOOSTERS {};
// const std::array<Container *,60> CONTAINERS {};

// Materials
const std::array<Material *,60> MATERIALS {
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

// Blueprints
const std::array<Blueprint *,60> BLUEPRINTS {
};

#endif
