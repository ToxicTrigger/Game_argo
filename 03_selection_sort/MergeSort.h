#pragma once
#include <limits.h>
#include "sort.h"

class MergeSort : public Sort
{
private:
	void merge(int* data, int f, int m, int l)
	{
		int tmp[50000];
		int f1 = f; int l1 = m;
		int f2 = m + 1; int l2 = l;
		int index = f1;

		for (; (f1 <= l1) && (f2 <= l2); ++index)
		{
			if (data[f1] < data[f2])
			{
				tmp[index] = data[f1];
				++f1;
			}
			else
			{
				tmp[index] = data[f2];
				++f2;
			}
		}
		
		for (; f1 <= l1; ++f1, ++index) tmp[index] = data[f1];
		for (; f2 <= l2; ++f2, ++index) tmp[index] = data[f2];
		for (index = f; index <= l; ++index) data[index] = tmp[index];
	}

	void merge_sort(int* data, int f , int l)
	{
		if (f < l)
		{
			int m = (f + l) / 2;
			merge_sort(data, f, m);
			merge_sort(data, m + 1, l);
			merge(data, f, m, l);
		}
	}
public:
	void sort(int* Datas, int size)
	{
		int f = 0;
		int last = size-1;

		merge_sort(Datas,0, last);
	}

};