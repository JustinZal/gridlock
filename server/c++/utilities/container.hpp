#ifndef container_h
#define container_h

#include "container.hpp"

#include <stdexcept>

#include "constants.hpp"
#include "material.hpp"

class Container{
	public:
		bool modifyContent(int _content) {
			if (!dryModifyContent(_content)) {
				return false;
			};

			content += _content;
			return true;
		};

		bool dryModifyContent(int _content) {
			return ((content + _content) <= volume);
		};

		unsigned int getContent() {
			return content;
		};

		void setMaterial(Material *_material) {
			// TODO add dry run and checks 
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
