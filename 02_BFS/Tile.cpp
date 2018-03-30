#include "Tile.h"

void Tile::update(Object* player)
{
	int x, y = 0;
	x = player->get_x();
	y = player->get_y();

	//��ġ��!
	if (x == this->get_x() & y == this->get_y())
	{
		isOver = true;
	}

	if (isWall)
	{
		set_char((char*)"��");
	}
	else if(!isOver)
	{
		set_char((char*)"��");
	}
	else if (isOver)
	{
		set_char((char*)"��");
	}
}
