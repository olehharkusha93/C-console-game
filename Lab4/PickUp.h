#pragma once
#include "Base.h"
class PickUp : public Base
{
protected:
	//bool isAlive;
public:
	PickUp(int _x, int _y, ConsoleColor _color, char* _char);
	~PickUp();
	void onpickup();
};

