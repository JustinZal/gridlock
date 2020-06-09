#include "shield.hpp"

Shield::Shield(unsigned int _maxProtection,unsigned int _maxRechargeRate,unsigned int _Efficiency){

}

ShieldItem::ShieldItem(Shield *_type){
	type=_type;
}
