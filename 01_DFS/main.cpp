#include <iostream>
#include "util.h"
#include "../01_stack/LinkedStack.h"

using namespace std;

void draw()
{
	ScreenClear();

	ScreenPrint(0, 0, (char*)"@");

	ScreenFlipping();
}

int main()
{
	bool end = false;

	ScreenInit();
	while (!end)
	{
		draw();
	}
	ScreenRelease();
	
	return 0;
}