#include "GameMap.h"

CGameMap::CGameMap(int MapSize)
{

	m_mapsize = MapSize;
	map = new int*[MapSize];
	visited = new int*[MapSize];

	for (int i = 0; i < MapSize; i++)
	{
		map[i] = new int[MapSize];
		visited[i] = new int[MapSize];
	}
	initOffset();
	makeMap();

}

CGameMap::~CGameMap()
{
}

void CGameMap::initOffset()
{
	move[0].horiz = 1;
	move[0].vert = 0;

	move[1].horiz = 0;
	move[1].vert = 1;

	move[2].horiz = -1;
	move[2].vert = 0;

	move[3].horiz = 0;
	move[3].vert = -1;
}

#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;;
void CGameMap::makeMap()
{
	int y, x;
	srand((unsigned)time(NULL));
	//srand(0);
	for (y = 0; y < m_mapsize; y++)
	{
		for (x = 0; x < m_mapsize; x++)
		{
			if (x == 0 || y == 0 || x == m_mapsize - 1 || y == m_mapsize - 1)
			{
				map[y][x] = WALL;
				visited[y][x] = 1;
			}
			else if (x == 1 || y == m_mapsize - 2)
			{
				map[y][x] = BLANK;
				visited[y][x] = 0;
			}
			else
			{
				map[y][x] = rand() % 2;
				visited[y][x] = map[y][x];

			}
		}
	}
}

void CGameMap::drawMap()
{
	int y, x;
	for (y = 0; y < m_mapsize; y++)
	{
		for (x = 0; x < m_mapsize; x++)
		{
			cout << map[y][x] << " ";
		}
		cout << endl;
	}
}
