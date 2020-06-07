#ifndef constants_h
#define constants_h

#include <stdexcept>

#include "shield.hpp"
#include "generator.hpp"
#include "booster.hpp"
#include "container.hpp"

#include "constants.hpp"

enum GRIDSIZE{Mini=24,Small=64,Normal=128,Large=256};
enum DIRECTION{U,D,L,R};


shield shields{};
container generators{};
booster boosters{};
container containers{};

#endif
