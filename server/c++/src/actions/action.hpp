#ifndef action_h
#define action_h

class Action{
private:
public:
	virtual bool dryExecute();
	virtual bool execute();
};

#endif