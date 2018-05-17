#include <iostream>
#include "myStack.h"
#include "../02_Queue/ArrayQ.h"

using namespace std;

void main()
{
	ArrayQ<float> queue(10);
	queue.enqueue(1.1f);
	cout << queue.dequeue() << endl;
	getchar();
}