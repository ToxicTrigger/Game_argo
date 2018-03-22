#include "DFS.h"


DFS::DFS(int sY, int sX, int Y, int X)
{
	found = false;
	sx = sX;
	sy = sY;
	ex = X;
	ey = Y;
}

DFS::~DFS()
{
}

#include "base.h"
#include <iostream>
using namespace std;

void DFS::findPath(CGameMap map)
{
	node pos;
	map.visited[sy][sx] = 1;
	pos.x = sx;
	pos.y = sy;
	pos.dir = 0;

	int x, y, dir;
	int ny, nx;
	stack.push(pos);

	while (!stack.isEmpty() && !found)
	{
		pos = stack.pop();
		y = pos.y;
		x = pos.x;
		dir = pos.dir;
		while (dir < 4 && !found)
		{
			ny = y + map.move[dir].vert;
			nx = x + map.move[dir].horiz;
			if (ny == ey && nx == ex)
			{
				found = true;
			}
			else if(!map.map[ny][nx] && !map.visited[ny][nx])
			{
				map.visited[y][x] = 1;
				pos.x = x;
				pos.y = y;
				pos.dir = ++dir;
				stack.push(pos);
				x = nx;
				y = ny;
				dir = 0;
			}
			else {
				dir++;
			}

		}
	}
	if (found)
	{
		pos.x = x;
		pos.y = y;
		pos.dir = dir;
		stack.push(pos);
	}

}

void DFS::drawPath()
{
	int i = 0;
	node path[100];
	cout << "Path" << endl;
	if (found)
	{
		for (i = 0; !stack.isEmpty(); i++)
		{
			path[i] = stack.pop();
		}
		for (int j = i - 1; j >= 0; j--) cout << "[" << path[j].y << "," << path[j].x << "]-->";
		cout << "end" << endl;
	}
	else
	{
		cout << "Nope"<<endl;
	}
}
