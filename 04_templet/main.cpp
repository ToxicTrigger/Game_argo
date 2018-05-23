#include <iostream>
#include <string>
#include <chrono>
#include <queue>
#include <deque>
using namespace std;

void main()
{
	deque<int> dq;
	deque<int>::iterator iter;
	dq.push_back(22);
	dq.push_back(11);

	for (iter = dq.begin(); iter != dq.end(); ++iter)
	{
		cout << *iter << endl;
	}
	getchar();
}