#include "Tile.h"




Tile::~Tile()
{
}

void Tile::update()
{
	if (isOver)
	{
		set_char((char*)"��");
	}
	else 
	{
		set_char((char*)"��");
	}
}
