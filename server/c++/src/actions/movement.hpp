#ifndef movement_h
#define movement_h

class Movement:private Action{
private:
	DIRECTION Direction;
public:
	Movement(DIRECTION _dircetion);
};

#endif