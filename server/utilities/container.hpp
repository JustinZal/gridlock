#ifndef container_h
#define container_h

#include "container.hpp"

#include <stdexcept>

#include "constants.hpp"
#include "material.hpp"

class Container{
	public:
		void setContent(unsigned int _content) {
			content = _content;
		};

		unsigned int getContent() {
			return content;
		};

		void setMaterial(Material *_material) {
			material = _material;
		};

		Material * getMaterial() {
			return material;
		};
	private:
		unsigned int volume=1;
		unsigned int content=0;
		Material *material=NULL;
};

#endif
