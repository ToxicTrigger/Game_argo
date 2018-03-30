#include <iostream>
#include "ArrayQ.h"
#include "LinkQueue.h"
#include "CkQ.h"

using namespace std;

void main()
{
	CkQ q;
	q.enQ(6);
	q.enQ(2);
	cout << q.getFront() << endl;
	cout << q.deQ() << endl;
	cout << q.deQ() << endl;

}

/*
void main()
{
ArrayQ aq(3);
cout << "현재 최대 크기 : " << aq.get_max_Size() << endl;

aq.enqueue(1);
aq.enqueue(2);
aq.enqueue(3);
cout << "pop : " << aq.dequeue() << " | size = " << aq.get_size() - 1 << endl;
cout << "pop : " << aq.dequeue() << " | size = " << aq.get_size() - 1 << endl;
cout << "pop : " << aq.dequeue() << " | size = " << aq.get_size() - 1 << endl;

aq.enqueue(1);
aq.enqueue(2);
aq.enqueue(3);

//Overflow!!
aq.enqueue(4);
//end!!

cout << "pop : " << aq.dequeue() << " | size = " << aq.get_size() - 1 << endl;
cout << "pop : " << aq.dequeue() << " | size = " << aq.get_size() - 1 << endl;
cout << "pop : " << aq.dequeue() << " | size = " << aq.get_size() - 1 << endl;

//Error!!
cout << "pop : " << aq.dequeue() << " | size = " << aq.get_size() - 1 << endl;
//Error!!

cout << "최대길이 증가" << endl;
aq.grow_size(1);
cout << "현재 최대 크기 : " << aq.get_max_Size() << endl;

aq.enqueue(1);
aq.enqueue(2);
aq.enqueue(3);
aq.enqueue(4);
cout << "pop : " << aq.dequeue() << " | size = " << aq.get_size() - 1 << endl;
cout << "pop : " << aq.dequeue() << " | size = " << aq.get_size() - 1 << endl;
cout << "pop : " << aq.dequeue() << " | size = " << aq.get_size() - 1 << endl;
cout << "pop : " << aq.dequeue() << " | size = " << aq.get_size() - 1 << endl;

cout << " ====== Link Q ====== " << endl;
LinkQueue lq;
cout << "lq.size : " << lq.get_size() << endl;
lq.enqueue(10);
cout << "lq.size : " << lq.get_size() << endl;
lq.enqueue(20);
cout << "lq.front : " << lq.get_front() << endl;
cout << "lq.size : " << lq.get_size() << endl;
cout << ">>lq.pop : " << lq.dequeue() << endl;
cout << "lq.size : " << lq.get_size() << endl;
cout << ">>lq.pop : " << lq.dequeue() << endl;
cout << "lq.size : " << lq.get_size() << endl;

while (true) {}
}
*/
