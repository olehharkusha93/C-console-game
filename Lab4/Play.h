#pragma once
#include "Player.h"
class Play
{
private:
	
	bool play;
	//Player* p;

public:
	Play();	
	~Play();

	void Game(bool play)
	{
		while (play)
		{
			Console::Lock(true);
			system("cls");
			
			Update();
			Render();


			Console::Lock(false);
			Sleep(20);
		}
	}
	void Update();
	void Render() const;

};



