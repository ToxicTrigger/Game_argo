#pragma once
#include "header.h"

class BFS
{
	LinkQueue q;
	CintStack stack;
	GameMap *map;

	int sNode;
	int tNode;
	int mapSize;
public:

	enum VisitInfo { UNVISIT, VISITED };
	BFS(int sn, int tn, int mSize) : sNode(sn), tNode(tn), mapSize(mSize)
	{
		map = new GameMap(mSize);
	}

	~BFS() {	}

	GameMap* getMap() { return map; }

	void getXY(int nodeNum, int& x, int& y)
	{
		y = nodeNum / mapSize;
		x = nodeNum % mapSize;
	}

	int getNode(int x, int y) 
	{
		return y * mapSize + x;
	}

	void draw(HDC hdc, HDC hmemde, HBITMAP hBitmap)
	{
		int x, y;
		HBITMAP old;
		if (!stack.isEmpty())
		{
			getXY(stack.pop(), x, y);
			map->setMapInfo(x, y, GONE);
		}
		else
		{
			getXY(tNode, x, y);
		}

		old = (HBITMAP)SelectObject(hmemde, hBitmap);
		BitBlt(hdc, x * 24, y * 24, 24, 24, hmemde, 0, 0, SRCCOPY);
		SelectObject(hmemde, old);
	}

	bool pathFind()
	{
		int* visit = new int[mapSize * mapSize];
		int* parent = new int[mapSize * mapSize];
		bool bFound = false;

		memset(visit, UNVISIT, sizeof(int) * mapSize * mapSize);
		memset(parent, -1, sizeof(int) * mapSize * mapSize);

		q.enqueue(sNode);
		visit[sNode] = VISITED;
		parent[sNode] = sNode;

		int top, x, y, dir;
		int nextX, nextY;

		while (!q.is_empty())
		{
			top = q.get_front();
			if (top == tNode)
			{
				bFound = true;
				break;
			}

			getXY(top, x, y);
			int nextNode;
			for (dir = 0; dir < 4; dir++)
			{
				nextY = y + map->m_move[dir].vert;
				nextX = x + map->m_move[dir].horz;
				nextNode = getNode(nextX, nextY);
				if (map->getMapInfo(nextX, nextY) == BLANK && 
					visit[nextNode] == UNVISIT)
				{
					q.enqueue(nextNode);
					visit[nextNode] = VISITED;
					parent[nextNode] = top;
				}
			}
			q.dequeue();
		}
		if (bFound)
		{
			int p = tNode;
			stack.push(p);
			do
			{
				p = parent[p];
				stack.push(p);
			} while (p != sNode);
		}

		while (!q.is_empty())
		{
			q.dequeue();
		}

		return bFound;
	}
};
