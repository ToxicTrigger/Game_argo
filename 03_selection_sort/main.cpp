#include <iostream>
#include <time.h>
#include "SelectionSort.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "ShellSort.h"
#include "MergeSort.h"

using namespace std;

void main()
{
	//Init sort Class & time
	clock_t t;
	SelectionSort ss;
	BubbleSort bs;
	InsertionSort is;
	ShellSort shell;
	MergeSort ms;

	int size = 10000;
	int* data = new int[size];

	//setting random value at dataArray
	srand((unsigned)clock());
	for (int i = 0; i < size; i++)
	{
		data[i] = (rand() % 1000) + 1;
	}
	//start timer
	t = clock();
	ss.sort(data, size);
	//end timer
	printf("Select = %0.4fs\n", (float)(clock() - t) / CLOCKS_PER_SEC);
	for (int i = 0; i < 10; i++)
	{
		cout << data[i] << endl;
	}

	srand((unsigned)clock());
	for (int i = 0; i < size; i++)
	{
		data[i] = (rand() % 1000) + 1;
	}
	t = clock();
	bs.sort(data, size);
	printf("Bubble = %0.4fs\n", (float)(clock() - t) / CLOCKS_PER_SEC);
	for (int i = 0; i < 10; i++)
	{
		cout << data[i] << endl;
	}

	srand((unsigned)clock());
	for (int i = 0; i < size; i++)
	{
		data[i] = (rand() % 1000) + 1;
	}
	t = clock();
	is.sort(data, size);
	printf("Insert = %0.4fs\n", (float)(clock() - t) / CLOCKS_PER_SEC);
	for (int i = 0; i < 10; i++)
	{
		cout << data[i] << endl;
	}

	srand((unsigned)clock());
	for (int i = 0; i < size; i++)
	{
		data[i] = (rand() % 1000) + 1;
	}
	t = clock();
	shell.sort(data, size);
	printf("Shell = %0.4fs\n", (float)(clock() - t) / CLOCKS_PER_SEC);
	for (int i = 0; i < 10; i++)
	{
		cout << data[i] << endl;
	}

	srand((unsigned)clock());
	for (int i = 0; i < size; i++)
	{
		data[i] = (rand() % 1000) + 1;
	}
	t = clock();
	ms.sort(data, size);
	printf("merge = %0.4fs\n", (float)(clock() - t) / CLOCKS_PER_SEC);
	for (int i = 0; i < 10; i++)
	{
		cout << data[i] << endl;
	}

	getchar();
}

