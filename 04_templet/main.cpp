#include <iostream>
#include "CkQ.h"
#include <string>
#include <chrono>
using namespace std;

void main()
{
	CkQ<int> q_int(10);
	CkQ<float> q_float(10);
	CkQ<string> q_string(10);

	auto s = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < q_int.get_max_size(); i++)
	{
		q_int.enQ(i);
		q_float.enQ(sin(i));
		q_string.enQ(std::to_string(i + 2));
	}
	auto f = std::chrono::high_resolution_clock::now();
	cout << "input : " << std::chrono::duration_cast<std::chrono::nanoseconds>(f - s).count() << "ns\n";

	s = std::chrono::high_resolution_clock::now();
	while (!q_int.isEmpty())
	{
		printf("int : %d\n", q_int.deQ());
		printf("float : %f\n", q_float.deQ());
		printf("str : %s\n", q_string.deQ().c_str());
	}
	f = std::chrono::high_resolution_clock::now();
	cout << "output : " << std::chrono::duration_cast<std::chrono::nanoseconds>(f - s).count() << "ns\n";

	getchar();
}