#pragma once
#include "sort.h"

class InsertionSort : public Sort 
{
public:
	InsertionSort() {};
	~InsertionSort() {};

	//insert
	void sort(int * Datas, int Size)
	{
		for (int i = 1; i < Size; i++)
		{
			int tmp = Datas[i];
			int j = i;
			while (j > 0 && Datas[j - 1] > tmp)
			{
				Datas[j] = Datas[j - 1];
				j--;
			}
			Datas[j] = tmp;
		}
	}
};