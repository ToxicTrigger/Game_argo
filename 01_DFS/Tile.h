#pragma once
#include "Object.h"

class Tile : public Object
{
public:
	bool isOver;
	bool isWall;
	Tile() : Object(0, 0, (char*)"��")
	{
		isOver = false;
		isWall = false;
	}
	Tile(int X, int Y) : Object(X, Y, (char*)"��")
	{
		isOver = false;
		isWall = false;
	};
	~Tile();

	void update();
};

