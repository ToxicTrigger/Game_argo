#pragma once
#include "sort.h"

class ShellSort : public Sort
{
public:
	void sort(int * Datas, int size)
	{
		int i, j, h, v;
		for (h = 1; h <= size / 9; h = 3 * h + 1);

		for (; h > 0; h /= 3)
		{
			for (i = h; i < size; i++)
			{
				v = Datas[i];
				j = i;

				while (j >= h && Datas[j - h] > v)
				{
					Datas[j] = Datas[j - h];
					j -= h;
				}
				Datas[j] = v;
			}
		}
	}
};