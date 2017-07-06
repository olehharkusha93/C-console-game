// Lab4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Base.h"
#include "Play.h"
#include "Enemy.h"
#include "PickUp.h"

#include <Windows.h>
#include <mmsystem.h>
#include <cstdlib>
#include <crtdbg.h>
#include <iostream>
#include <fstream>
#include <string>

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>


int main()
{
	//Also need this for memory leak code stuff
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetBreakAlloc(-1);
	srand((int)time(0));
	PlaySound(TEXT("Videogame2.wav"), NULL, SND_ASYNC | SND_LOOP);
	Player* p = new Player(20, 20, "$");
	Enemy* e = new Enemy(Cyan, "X");
	PickUp* pickup = new PickUp(rand() % 74, rand() % 29, Green, "@");

	vector<Enemy*> enemy;
	for (size_t i = 0; i < 25; i++)
	{
		enemy.push_back(new Enemy(Cyan, "X"));
	}
	vector<PickUp*> mPickup;
	mPickup.resize(1);
	mPickup[0] = pickup;

	Console::EOLWrap(false);
	Console::SetWindowSize(75, 30);
	Console::SetBufferSize(75, 30);
	int score = 0;
	bool play = true;
	bool lost = false;
	string fname;
	while (play)
	{
		Console::Lock(true);
		Console::Clear();
		//system("cls");
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			delete p;
			delete e;
			//delete pickup;
			for (size_t i = 0; i < enemy.size(); i++)
			{
				delete enemy[i];
			}
			for (size_t i = 0; i < mPickup.size(); i++)
			{
				delete mPickup[i];
			}
			break;
		}
		for (size_t i = 0; i < enemy.size(); i++)
		{
			if (enemy[i] != nullptr)
			{
				if (p->GetX() == enemy[i]->GetX() && p->GetY() == enemy[i]->GetY())
				{

					delete p;
					delete e;
					//delete pickup;
					for (size_t i = 0; i < enemy.size(); i++)
					{
						delete enemy[i];
					}
					for (size_t i = 0; i < mPickup.size(); i++)
					{
						delete mPickup[i];
					}
					return play = false;
				}
			}
		}
		if (p->GetX() == pickup->GetX() && p->GetY() == pickup->GetY() && pickup->Alive())
		{
			pickup->onpickup();
			pickup = new PickUp(rand() % 75, rand() % 30, Green, "@");
			score += 100;
			mPickup.push_back(pickup);

		}
		p->Render();
		e->Render();
		pickup->Render();
		p->Update();
		e->Update();
		for (int i = 0; i < 25; i++)
		{
			if (enemy[i] != nullptr)
			{
				enemy[i]->Render();
				enemy[i]->Update();
			}
		}

		Console::SetCursorPosition(0, 0);
		cout << "Score: " << score;
		Console::SetCursorPosition(38, 0);
		cout << "Shift-open";
		Console::SetCursorPosition(52, 0);
		cout << "Space-save";
		Console::SetCursorPosition(66, 0);
		cout << "ESC-exit";

		Console::Lock(false);
		Sleep(20);

 		if (GetAsyncKeyState(VK_SPACE))
		{
			Console::Clear();
			
			cout << "Name your file(.txt/.bin): ";
			cin >> fname;
			fstream fout;
			fout.open(fname + ".txt", ios_base::out | ios_base::app);
			if (fout.is_open())
			{
				fout << "Score: " << '\t' << score << '\n';
				fout.close();				
			}
			ofstream bout;
			bout.open(fname + ".bin", ios_base::binary | ios_base::app);
			if (bout.is_open())
			{
				bout << "Score: " << '\t' << score << '\n';
				bout.close();
			}
		}
		if (GetAsyncKeyState(VK_SHIFT))
		{
			Console::Clear();
			char test[32];
			ifstream fin;
			cout << "Name of a file you'd like to open?(.txt/bin) ";
			cin >> fname;			
			fin.open(fname,ios_base::in);

			if (fin.is_open())
			{
				while (true)
				{
					fin.getline(test, 32, '\t');
					
					if (fin.eof())
						break;
					fin >> score;					
					cout << "Score: " << score << '\n';
					fin.ignore(INT_MAX, '\n');
				}
				fin.close();
			}
			else
				cout << "File did not open...\n";
			system("pause");
			fstream bin;
			int location = (int)bin.tellg();
			bin.open(fname, ios_base::binary | ios_base::in);
			
			if (bin.is_open())
			{
				bin.seekg(0, ios_base::end);
				int count = (int)bin.tellg();
				bin.close();
			}
		}
	}

	//delete p;
	//delete e;
	//delete pickup;
	//for (int i = 0; i < enemy.size(); i++)
	//{
	//	delete enemy[i];
	//}
	//cout << "\n\n\n\n\n";	

	/*ifstream fin;
	fin.open("score.txt");
	if (fin.is_open)
	{

	}*/

	//cout << "\n\n\n\n\n\n\n";
	//system("pause");
	return 0;
}

