#include "stdafx.h"
#include "PickUp.h"
#include "Base.h"


PickUp::PickUp(int _x, int _y,ConsoleColor _color, char* _char)
{
	SetX(_x);
	SetY(_y);
	SetColor(_color);
	mChar = _strdup(_char);
	isAlive = true;
}


PickUp::~PickUp()
{
}
void PickUp::onpickup()
{
	isAlive = false;
}
