#include "stdafx.h"
#include "Play.h"
#include "Base.h"

Play::Play()
{
	play = true;
	//p = new Player(5, 5, "#");
}


Play::~Play()
{
	
}
void Play::Update()
{
	while (play)
	{

		Console::Lock(true);
		system("cls");
		
		if (GetAsyncKeyState(VK_ESCAPE))
			break;

	}
}