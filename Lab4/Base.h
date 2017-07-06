#pragma once
class Base
{
private:
protected:
	int x;
	int y;
	char* mChar;
	ConsoleColor color;
	bool isAlive;

public:
	Base();
	Base(int _x, int _y,const char* const _char, ConsoleColor _color);
	~Base();
	
	ConsoleColor GetColor() const { return color; }
	int GetX() const { return x; }
	int GetY() const { return y; }
	char const * const GetChar() const { return mChar; }
	bool Alive() const { return isAlive; }

	void SetColor(ConsoleColor _color) { color = _color; }
	void SetX(int _x) { x = _x; }
	void SetY(int _y) { y = _y; }
	void SetChar(const char* const _char);


	void Update();
	virtual void Render() const;
};

