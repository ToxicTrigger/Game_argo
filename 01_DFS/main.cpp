#include <iostream>
#include "util.h"
#include "LinkedStack.h"
#include "Object.h"
#include "Tile.h"
#include <ctime>
#include <string>
#include <Windows.h>

using namespace std;

void gen_map(const int w, const int h, Tile** src);
void draw_map(const int w, const int h, Tile** src);

void update(Object* player, Object* target, LinkedStack* stack, Tile** map, int over)
{
	int px = player->get_x();
	int py = player->get_y();
	if (px < 10 & py < 10)
	{
		if (px == target->get_x() & py == target->get_y())
		{

			return;
		}

		if (px != 9)
		{
			player->move(Look::RIGHT_);
			stack->push(Look::RIGHT_);
		}
		else
		{
			if (py < 10) ++py;
			player->set_pos(0, py);
			stack->push(Look::DOWN_);
		}
	}

		for (int y = 0; y < 10; y++)
		{
			for (int x = 0; x < 10; x++)
			{
				int tx = map[y][x].get_x();
				int ty = map[y][x].get_y();
				if (tx == player->get_x() & ty == player->get_y())
				{
					map[y][x].isOver = true;
					//TODO:: 여기서 시작. 다녀온 타일은 isOver 로 마킹.
					/*
					현재 위치를 스택에 집어넣고,
					이동 하다가 스택에 넣어진 값이 동일할 때 처음 위치까지 pop
					다른 방향으로 계속 이동.
					*/
				}
				map[y][x].update();

			}
		}
		
	
	Sleep(100);
}

int main()
{
	LinkedStack stack = LinkedStack();
	

	int end = 0;
	Object player = Object(-1,0,(char*)"○");
	Tile** map = new Tile*[10];
	gen_map(10, 10, map);
	Object target = Object(2, 4, (char*)"★");

	ScreenInit();
	while (end == 0)
	{
		update(&player, &target , &stack, map, end);
		ScreenClear();

		draw_map(10, 10, map);
		player.draw();
		target.draw();

		int px = player.get_x();
		int py = player.get_y();
		if (px == target.get_x() & py == target.get_y())
		{
			ScreenPrint(0, 14, (char*)"::DONE");
		}

		ScreenFlipping();

	}
	ScreenRelease();
	
	return 0;
}

void gen_map(const int w, const int h, Tile ** src)
{
	for (int x = 0; x < h; x++)
	{
		src[x] = new Tile[h];		
	}

	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			src[y][x].set_pos( x, y );
		}
	}
	
}

void draw_map(const int w, const int h, Tile** src)
{
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			src[y][x].draw();
		}
	}
}


