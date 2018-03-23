#pragma once
#include <stdlib.h>
#include <malloc.h>

class ArrayQ
{
private:
	int* q;
	int front;
	int end;
	int max_size;
	int size;

public:
	ArrayQ(int MaxSize)
	{
		int tmp_size = MaxSize + 1;
		int * tmp = (int*)malloc(tmp_size * sizeof(int));
		q = tmp;
		end = front = 0;
		max_size = tmp_size;
		size = 0;
	}

	~ArrayQ()
	{
		delete[] q;
	}
	
	void enqueue(int data)
	{
		if ((end + 1) % max_size == front)
		{
			printf("Error : failed Enqueue, MaxSize < size\n");
		}
		else
		{
			size++;
			end = (end + 1) % max_size;
			q[end] = data;
		}
	}

	int dequeue()
	{
		if (is_empty())
		{
			printf("Error : failed Dequeue, End of Queue\n");
			return -1;
		}
		size--;
		front = (front + 1) % max_size;
		return q[front];
	}

	int get_front()
	{
		return q[(front + 1) % max_size];
	}

	int get_size()
	{
		return size;
	}

	int get_max_Size()
	{
		//메모리 상의 q 가 차지하는 크기
		return (_msize(q) / sizeof(int)) - 1;
	}

	bool is_empty()
	{
		return front == end;
	}

	void grow_size(int Up)
	{
		max_size = max_size + Up;
		q = (int*)realloc(q, max_size * sizeof(int));
	}
};