#ifndef object_h
#define object_h

#include <stdexcept>

struct vector{
	int x,y;
}

class Object{
	private:
		struct vector v;

	public:
		void accelerate(unsigned int energy,struct vector direction);
		
};

#endif