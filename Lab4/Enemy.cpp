#include "stdafx.h"
#include "Enemy.h"
#include "Base.h"
#include "Player.h"


Enemy::Enemy(ConsoleColor _color, const char* const _char)
{
	mChar = nullptr;
	SetX(rand() % 74);
	SetY(rand() % 29);
	SetChar("X");
	SetColor(Cyan);
	isAlive = true;
}


Enemy::~Enemy()
{

}
void Enemy::Render() const
{
	Console::ForegroundColor(Cyan);
	Console::SetCursorPosition(x, y);
	cout << mChar;
	Console::ResetColor();
}

void Enemy::Update()
{	
	if (rand() % 2 == 0)
		x += rand() % 3 - 1;
	else
		y += rand() % 3 - 1;

	//if (x < 0 || x > 75)
	//	x *= -1;
	//if (y < 0 || y > 30)
	//	y *= -1;

	if (x < 0)
		x = 0;
	if (x > 75)	
		x = 75;
	if (y < 0)
		y = 0;
	if (y > 30)	
		y = 30;
	

}
void Enemy::SetChar(const char* const _char)
{
	delete mChar;

	int length = strlen(_char) + 1;
	mChar = new char[length];
	strcpy_s(mChar, length, _char);
}

