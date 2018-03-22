#include <iostream>
#include "LinkedStack.h"
#include "Tile.h"
#include <Windows.h>

using namespace std;

void gen_map(const int w, const int h, Tile** src);
void draw_map(const int w, const int h, Tile** src);
void update(Object* player, Object* target, LinkedStack* stack, Tile** map, int over)
{
	int px = player->get_x();
	int py = player->get_y();
	int tx = target->get_x();
	int ty = target->get_y();

	//얼마나의 거리가 남았나.
	int pivot_x = tx - px;
	int pivot_y = ty - py;

	//현재 플레이어 기점으로 상하좌우 타일을 얻어옵니다.
	Tile around[4];
	if (px > 0)
		around[0] = map[py][px - 1];
	if (px < 9)
		around[1] = map[py][px + 1];
	if (py > 0)
		around[2] = map[py - 1][px];
	if (py < 9)
		around[3] = map[py + 1][px];

	//맵 타일 크기를 벗어나 연산하지 않습니다.
	while (px < 10 & py < 10)
	{
		//도착
		if (pivot_x == 0 & pivot_y == 0) return;

		//피봇y 진행 방향에 벽이 있다면?
		if (pivot_y > 0 & around[3].isWall)
		{
			//피봇x 진행방향에서 가장 가까운 쪽으로 움직입니다.
			if (pivot_x < 0)
			{
				player->move(Look::LEFT_);
				stack->push(Look::RIGHT_);
				break;
			}
			else
			{
				player->move(Look::RIGHT_);
				stack->push(Look::LEFT_);
				break;
			}
			break;
		}
		if (pivot_x > 0 & !around[1].isWall)
		{
			player->move(Look::RIGHT_);
			stack->push(Look::LEFT_);
			break;
		}
		else if (pivot_y > 0 & !around[3].isWall)
		{
			player->move(Look::UP_);
			stack->push(Look::DOWN_);
			break;
		}
		else if (pivot_x < 0 & !around[0].isWall)
		{
			player->move(Look::LEFT_);
			stack->push(Look::RIGHT_);
			break;
		}
		else if (pivot_x > 0 & around[1].isWall)
		{
			if (px != tx)
			{
				player->move(Look::UP_);
				stack->push(Look::DOWN_);
				break;
			}
		}
		else if (pivot_y < 0 & !around[2].isWall)
		{
			player->move(Look::DOWN_);
			stack->push(Look::UP_);
			break;
		}
		else
		{
			int head = stack->pop();
			switch (head)
			{
			case 0:
				player->move(Look::UP_);
				break;
			case 1:
				player->move(Look::DOWN_);
				break;
			case 2:
				player->move(Look::LEFT_);
				break;
			case 3:
				player->move(Look::RIGHT_);
				break;
			}

			break;
		}
	}
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			int tx = map[y][x].get_x();
			int ty = map[y][x].get_y();

			map[y][x].update(player);

		}
	}
	//보기 쉽게 천천히 끊어서 보여줍니다.
	Sleep(500);
}

int main()
{
	LinkedStack stack = LinkedStack();

	int end = 0;
	Object player = Object(0, 0, (char*)"○");
	Tile** map = new Tile*[10];
	gen_map(10, 10, map);
	Object target = Object(0, 5, (char*)"★");

	map[0][2].isWall = true;
	map[1][2].isWall = true;
	map[1][0].isWall = true;

	map[4][0].isWall = true;

	ScreenInit();
	while (end == 0)
	{
		update(&player, &target, &stack, map, end);
		ScreenClear();

		draw_map(10, 10, map);
		player.draw();
		target.draw();

		int px = player.get_x();
		int py = player.get_y();
		if (px == target.get_x() & py == target.get_y())
		{

			ScreenPrint(0, 11, (char*)"Start::");
			ScreenPrint(0, stack.get_size() + 15, (char*)"::DONE");
			int len = stack.get_size();
			for (int i = 0; i < len; i++)
			{
				int head = stack.pop();
				const char* top = "";

				switch (head)
				{
				case 0:
					top = "Up";
					break;
				case 1:
					top = "DOWN";
					break;
				case 2:
					top = "Right";
					break;
				case 3:
					top = "Left";
					break;

				}
				ScreenPrint(0, i + 13, (char*)top);

			}
			end = 1;
		}

		ScreenFlipping();
		if (end == 1)
		{
			Sleep(3000);
		
			break;
		}
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
			src[y][x].set_pos(x, y);
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


