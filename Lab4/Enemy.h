#pragma once
#include "Base.h"
class Enemy : public Base
{
private:

public:
	//Enemy();
	Enemy(ConsoleColor _color, const char* const _char);
	~Enemy();

	void SetChar(const char* const _char);

	void SetX(int _x) { x = _x; }
	void SetY(int _y) { y = _y; }
	void Render() const;
	void Update();

};

