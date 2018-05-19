#include <iostream>
#include <time.h>
#include "SelectionSort.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "ShellSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include <chrono>

using namespace std;

void main()
{
	//Init sort Class & time
	SelectionSort ss;
	BubbleSort bs;
	InsertionSort is;
	ShellSort shell;
	MergeSort ms;
	QuickSort qs;

	int size = 50000;
	int* data = new int[size];

	srand((unsigned)clock());
	for (int i = 0; i < size; i++)
	{
		data[i] = (rand() % 1000) + 1;
	}
	auto s = std::chrono::high_resolution_clock::now();
	shell.sort(data, size);
	auto f = std::chrono::high_resolution_clock::now();
	cout << "Shell : " << std::chrono::duration_cast<std::chrono::nanoseconds>(f - s).count() << "ns\n";


	srand((unsigned)clock());
	for (int i = 0; i < size; i++)
	{
		data[i] = (rand() % 10) + 1;
	}
	 s = std::chrono::high_resolution_clock::now();
	ms.sort(data, size);
	 f = std::chrono::high_resolution_clock::now();
	cout << "Merge : " << std::chrono::duration_cast<std::chrono::nanoseconds>(f - s).count() << "ns\n";


	srand((unsigned)clock());
	for (int i = 0; i < size; i++)
	{
		data[i] = (rand() % 1000) + 1;
	}
	 s = std::chrono::high_resolution_clock::now();
	qs.sort(data, size);
	 f = std::chrono::high_resolution_clock::now();
	cout << "Quick : " << std::chrono::duration_cast<std::chrono::nanoseconds>(f - s).count() << "ns\n";


	getchar();
}

