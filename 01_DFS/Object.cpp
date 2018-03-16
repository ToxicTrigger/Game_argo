#include "Object.h"



Object::Object()
{
}


Object::~Object()
{
}

void Object::draw()
{
	ScreenPrint(this->x, this->y, this->Char);
}

void Object::set_pos(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Object::set_char(char * Char)
{
	this->Char = Char;
}

void Object::move(Look look)
{
	if (x < 0 & look == Look::LEFT_) return;

	switch (look)
	{
	case UP_: y++; break; 
	case DOWN_: y--; break;
	case LEFT_: x--; break; 
	case RIGHT_: x++; break; 

	}
}
