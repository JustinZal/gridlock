#ifndef shield_h
#define shield_h

#include <stdexcept>
#include "constants.hpp"

#include "shield.hpp"

class Shield{
	private:
		int maxProtection;
		int maxRechargeRate;
		int Efficiency;

	public:
		void Shield(int _maxProtection,int _maxRechargeRate,int _Efficiency);

};

class ShieldItem:public Item,public InternalItem{
	private:
		Shield *type;
		int protection;

	public:
		void ShieldItem(Shield *_type);

		int getProtection();

		bool dryRecharge();

		bool recharge();
};

#endif
