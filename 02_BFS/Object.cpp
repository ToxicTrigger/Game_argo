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
	//화면 밖으로 이동하려 할 때 차단
	if (x < 0 & look == Look::LEFT_) return;
	if (y < 0 & look == Look::DOWN_) return;

	switch (look)
	{
	case UP_: y++; break; 
	case DOWN_: y--; break;
	case LEFT_: x--; break; 
	case RIGHT_: x++; break; 
	}
}
