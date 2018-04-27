#pragma once
#include "sort.h"

class SelectionSort : public Sort
{
public:
	SelectionSort() {};
	~SelectionSort() {};
	
	void sort(int* Datas, int Size)
	{
		for (int last = Size - 1; last >= 1; --last)
		{
			int large = 0;
			int tmp;

			for (int cur = 1; cur <= last; cur++)
			{
				if (Datas[cur] > Datas[large]) large = cur;
			}

			swap(Datas[large], Datas[last], tmp);
		}
	}
};

