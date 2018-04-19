#include <iostream>
using namespace std;

#ifndef _SWAP
#define swap(a,b,t){ t = a; a = b; b = t;}
#endif

void selection_sort(int* arr, int size);


void main()
{
	int a[10] = {40,22,140,22, 11, 50, 25,75,24,14};
	selection_sort(a, 10);

	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << endl;
	}

	getchar();
}

void selection_sort(int*arr, int size)
{
	for (int last = size - 1; last >= 1; --last)
	{
		int large = 0;
		int tmp;

		for (int cur = 1; cur <= last; cur++)
		{
			if (arr[cur] > arr[large]) large = cur;
		}

		swap(arr[large], arr[last], tmp);
	}
}
