#ifndef booster_h
#define booster_h

#include <stdexcept>
#include "constants.hpp"

#include "booster.hpp"

class Booster{
	private:
		int maxPower;
		int efficiency;

	public:
		void Booster();

};

class BoosterItem:public Item{
	private:
		Booster *type;

	public:
		void BoosterItem(Booster *_type);
};

#endif
