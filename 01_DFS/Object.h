#pragma once
#include "util.h"

enum Look { UP_, DOWN_, LEFT_, RIGHT_ };
class Object
{
private:
	int x, y;
	char* Char;

public:
	Object();
	Object(int x, int y, char* Char)
	{
		this->x = x;
		this->y = y;
		this->Char = Char;
	}
	~Object();

	void draw();
	void set_pos(int x, int y);
	void set_char(char* Char);
	int get_x() { return x; };
	int get_y() { return y; };

	void move(Look look);
};

