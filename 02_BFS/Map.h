#pragma once
#include "Tile.h"

class Map
{
public:
	Tile * * tiles;
	int w, h;

	Map(int W = 10, int H = 10)
	{
		w = W;
		h = H;
		tiles = new  Tile*[w];
		for (int x = 0; x < h; x++)
		{
			tiles[x] = new Tile[h];
		}

		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
			{
				tiles[y][x].set_pos(x, y);
			}
		}

	}
	~Map()
	{
	}

	void draw_map()
	{
		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
			{
				tiles[y][x].draw();
			}
		}
	}
};

