#ifndef GRIDLOCK_MODULE_HPP
#define GRIDLOCK_MODULE_HPP

#include <stdexcept>
#include "constants.hpp"

#include "item.hpp"

#include "module.hpp"

class Module{

private:
	
public:
	virtual unsigned int getSize() = 0;
};

#endif
