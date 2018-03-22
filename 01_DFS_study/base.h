#pragma once

struct node
{
	int x;
	int y;
	//방향
	int dir;
};


struct offset
{
	//세로 오프셋
	int vert;
	//가로 오프셋
	int horiz;
};

//타일 속성
enum MAPINFO { BLANK, OBJECT, WALL };