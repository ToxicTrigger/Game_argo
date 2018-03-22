#include "DFS.h"
#include "GameMap.h"


void main()
{
	CGameMap map;
	DFS path;

	path.findPath(map);
	map.drawMap();
	path.drawPath();

	while (true) {}
}