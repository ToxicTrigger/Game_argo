#include "Tile.h"




Tile::~Tile()
{
}

void Tile::update()
{
	if (isOver)
	{
		set_char((char*)"в├");
	}
	else 
	{
		set_char((char*)"бр");
	}
}
