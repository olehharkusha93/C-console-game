#include "stdafx.h"
#include "Base.h"
#include "PickUp.h"


Base::Base()
{
	mChar = nullptr;

	//p = new Player(5,5,"#");
	/*SetChar("$");
	SetColor(Red);
	SetX(10);
	SetY(10);*/
}

Base::Base(int _x, int _y,const char* const _char, ConsoleColor _color)
{
	mChar = nullptr;
	SetChar(_char);
	SetColor(_color);
	SetX(_x);
	SetY(_y);
}

Base::~Base()
{
	delete[] mChar;
}

void Base::SetChar(const char* const _char)
{
	delete[] mChar;

	mChar = _strdup(_char);
}
void Base::Update()
{	
	if (GetAsyncKeyState(VK_LEFT))
	{
		if (x < 0)
		{
			x = 0;
		}
		else
		{
			x--;
		}
	}	
	else if (GetAsyncKeyState(VK_RIGHT))
	{
		if (x > 75)
		{
			x = 75;
		}
		else
		{
			x++;
		}
	}
	else if (GetAsyncKeyState(VK_UP))
	{
		if (y < 0)
		{
			y = 0;
		}
		else
		{
			y--;
		}
	}
	else if (GetAsyncKeyState(VK_DOWN))
	{
		if (y > 30)
		{
			y = 30;
		}
		else
		{
			y++;
		}
	}
}
void Base::Render() const
{
	Console::ForegroundColor(color);
	Console::SetCursorPosition(x, y);
	if (isAlive == true)
		cout << mChar;
	
	Console::ResetColor();

}