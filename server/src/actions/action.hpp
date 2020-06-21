#ifndef GRIDLOCK_ACTION_HPP
#define GRIDLOCK_ACTION_HPP

class Action{
	
private:
	
public:
	virtual bool dryExecute()=0;

	virtual bool execute()=0;
};

#endif

class TempAction : public Action{

public:
	virtual bool dryExecute() override{
		return true;
	}
	virtual bool execute() override{
		return true;
	}

};