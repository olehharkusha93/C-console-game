#include "stdafx.h"
#include "Player.h"


Player::Player(int _x, int _y, char* _char)
{
	x = _x;
	y = _x;
	mChar = _strdup(_char);
	isAlive = true;
	SetColor(Red);
}


Player::~Player()
{
}
