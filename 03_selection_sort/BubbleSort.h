#pragma once
#include "sort.h"

class BubbleSort : public Sort
{
public:
	BubbleSort() {};
	~BubbleSort() {};

	//bubble
	void sort(int* Datas, int Size)
	{
		for (int i = Size - 1; i > 0; --i)
		{
			for (int k = 0; k < i; ++k)
			{
				if (Datas[i] < Datas[k])
				{
					int tmp;
					swap(Datas[i], Datas[k], tmp);
				}
			}
		}
	}
};