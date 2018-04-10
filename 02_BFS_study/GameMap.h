#pragma once
#include <Windows.h>

struct offset
{
	int vert;
	int horz;
};

enum TileType
{
	BLANK,
	OBJECT,
	WALL,
	GONE,
	NPC
};

class GameMap
{
	int** m_game_map;
	int m_map_size;

public:
	offset m_move[4];

	~GameMap() {
		if (m_game_map)
		{
			for (int i = 0; i < m_map_size; i++)
			{
				delete m_game_map[i];
			}
			delete m_game_map;
		}
	}

	GameMap(int Max = 5) : m_map_size(Max)
	{
		m_game_map = new int*[Max];
		for (int i = 0; i < Max; i++)
		{
			m_game_map[i] = new int[Max];
		}
	}

	void initMap();
	void initOffset();
	void makeMap();
	int getMapSize() { return m_map_size;  }
	int getMapInfo(int x, int y) { return m_game_map[y][x]; }
	void setMapInfo(int x, int y, int val) { m_game_map[y][x] = val; }
	void drawTile(HDC hdc, HDC hmemdc, HBITMAP bitmap, int x, int y);
};

