#pragma once
#include "Object.h"

class Tile : public Object
{
public:
	//다녀간 타일 마킹용
	bool isOver;
	//벽
	bool isWall;
	Tile() : Object(0, 0, (char*)"□")
	{
		isOver = false;
		isWall = false;
	}
	Tile(int X, int Y) : Object(X, Y, (char*)"□")
	{
		isOver = false;
		isWall = false;
	};
	inline ~Tile()
	{

	}

	//플레이어 값을 사용하여 타일을 업데이트 합니다.
	void update(Object* player);
};

