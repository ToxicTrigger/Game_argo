#pragma once
#include "sort.h"

class QuickSort : public Sort
{
private:
	int partition(int* data, int f, int l)
	{
		int low, h, p;
		p = data[l];
		low = f;
		h = l - 1;
		int t = 0;
		while (low < h)
		{
			while (p > data[low]) low++;
			while (p <= data[h]) h--;
			if(low < h) swap(data[low], data[h], t);
		}
		swap(data[low], data[l], t);
		return low;
	}

	void QS(int* data, int f, int l)
	{
		if (f < l)
		{
			int p = partition(data, f, l);
			QS(data, f, p - 1);
			QS(data, p + 1, l);
		}
	}

public:
	void sort(int* data, int size)
	{
		int f = 0;
		int last = size-1;
		QS(data, f, last);
	}
};