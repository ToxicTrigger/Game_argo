#pragma once
#include "CnodeStack.h"
#include "GameMap.h"
class DFS
{
	CnodeStack stack;
	int ey, ex, sx, sy;
	bool found;

public:
	DFS(int sY = 1, int sX = 1, int Y = 8, int X = 8);
	~DFS();

	void findPath(CGameMap map);
	void drawPath();
};

