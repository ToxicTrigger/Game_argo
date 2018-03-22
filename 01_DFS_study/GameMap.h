#pragma once
#include "base.h"
class CGameMap
{
	int m_mapsize;
public:
	int** map;
	int** visited;

	offset move[4];

	CGameMap(int MapSize = 10);
	~CGameMap();
	
	void initOffset();
	void makeMap();
	void drawMap();
};

