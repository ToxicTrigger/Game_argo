#include <iostream>
#include "Map.h"
#include "ArrayQ.h"
#include <Windows.h>
#include <string>

using namespace std;

void drawObject(Map map, Object player, Object des, ArrayQ end);
void update(Map map, Object player, Object des, bool isEnd, ArrayQ end);
void bfs(Map map, Object player, Object des, ArrayQ q, bool isEnd, ArrayQ* end);

void main()
{
	ArrayQ visit(1000);
	ArrayQ End(1000);
	Map map(5, 5);
	Object player(0, 0, (char*)"⊙");
	Object point(0, 4, (char*)"♨");

	map.tiles[0][1].isWall = true;
	map.tiles[1][1].isWall = true;

	map.tiles[1][3].isWall = true;
	map.tiles[2][3].isWall = true;


	map.tiles[3][0].isWall = true;
	map.tiles[3][1].isWall = true;
	map.tiles[3][2].isWall = true;
	map.tiles[3][3].isWall = true;

	bool isEnd = false;

	visit.enqueue(map.tiles[0][0]);

	bfs(map, player, point, visit, isEnd, &End);
	isEnd = true;

	ScreenInit();
	update(map, player, point, isEnd, End);
	ScreenRelease();
}

void drawObject(Map map, Object player, Object des, ArrayQ end)
{
	ScreenClear();

	map.draw_map();
	des.draw();
	player.draw();

	ArrayQ tm = end;
	int s = tm.get_size();
	for (int i = 0; i < s; i++)
	{
		Tile tmp = tm.dequeue();
		string msg = "(" + to_string(tmp.get_x()) + ", " + to_string(tmp.get_y()) + ")";
		char* str = (char*)msg.c_str();
		ScreenPrint(0, map.h + i + 1, str);
	}

	ScreenFlipping();
	Sleep(500);
}

void update(Map map, Object player, Object des, bool isEnd, ArrayQ end)
{
	while (isEnd)
	{
		if ((des.get_x() == player.get_x())&(des.get_y() == player.get_y()))
		{
			player.set_char((char*)"DONE");
		}

		for (int y = 0; y < map.h; y++)
		{
			for (int x = 0; x < map.w; x++)
			{
				map.tiles[y][x].update(&player);
				
			}
		}
		ArrayQ move = end;

		Tile tile = end.dequeue();
		player.set_pos(tile.get_x(), tile.get_y());

		drawObject(map, player, des, end);
	}
}

void bfs(Map map, Object player, Object des, ArrayQ q, bool isEnd, ArrayQ* end)
{
	//인접 큐가 아직 남아 있다면
	while (!q.is_empty())
	{
		Tile now = q.dequeue();
		int x = now.get_x();
		int y = now.get_y();

		//만약 현재 노드가 다녀간 곳 이라면?
		if (now.isOver == true) continue;
		
		Tile front = q.get_front();
		//만약 현재 노드가 다음 대상과 같은 노드라면?
		if ((front.get_x() == x)&(front.get_y() == y))
		{
			q.dequeue();
			continue;
		}

		map.tiles[y][x].isOver = true;
		//현재 노드를 EndPath 큐에 집어 넣는다.
		end->enqueue(now);

		//만약 현재 노드와 목적지의 위치가 동일하다면?
		if ((now.get_x() == des.get_x()) & (now.get_y() == des.get_y()))
		{
			return;
		}

		Tile* up = new Tile(-1, -1);
		Tile* down = new Tile(-1, -1);
		Tile* left = new Tile(-1, -1);
		Tile* right = new Tile(-1, -1);

		if (x - 1 >= 0) left =		&map.tiles[y][x - 1];
		if (x + 1 < map.w) right =	&map.tiles[y][x + 1];
		if (y - 1 >= 0) up =		&map.tiles[y-1][x];
		if (y + 1 < map.h) down =	&map.tiles[y+1][x];

		// 1. 다녀간 타일이 아닐 것
		// 2. 벽이 아닐 것
		// 3. 갈 수 없는 곳이 아닐 것
		if ((!left->isOver & !left->isWall) & left->get_x() != -1) {
			//조건 충족시 인접 노드를 인접노트큐에 삽입
			Tile l = map.tiles[y][x - 1];
			q.enqueue(l);
		}
		if ((!right->isOver & !right->isWall) & right->get_x() != -1) {
			Tile l = map.tiles[y][x + 1];
			q.enqueue(l);
		}
		if ((!up->isOver & !up->isWall) & up->get_x() != -1) {
			Tile l = map.tiles[y - 1][x];
			q.enqueue(l);
		}
		if ((!down->isOver & !down->isWall) & down->get_x() != -1) {
			Tile l = map.tiles[y + 1][x];
			q.enqueue(l);
		}

	}
}

