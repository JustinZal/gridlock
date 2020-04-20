#ifndef grid_h
#define grid_h

#include <stdexcept>
#include "constants.h"

#include "grid.h"

class Grid{
	private:
		Object *grid[][]=NULL;

	public:
		void Grid(GridSize size);
		void Turn();
};

#endif