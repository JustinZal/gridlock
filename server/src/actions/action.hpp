#ifndef GRIDLOCK_ACTION_HPP
#define GRIDLOCK_ACTION_HPP

class Action{
	
private:
	
public:
	virtual bool dryExecute();

	virtual bool execute();
};

#endif