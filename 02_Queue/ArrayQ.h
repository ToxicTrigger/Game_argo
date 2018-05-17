#pragma once
#include <stdlib.h>
#include <malloc.h>

template <typename T>
class ArrayQ
{
private:
	T* q;
	int front;
	int end;
	int max_size;
	int size;

public:
	ArrayQ(int MaxSize)
	{
		int tmp_size = MaxSize + 1;
		T * tmp = (T*)malloc(tmp_size * sizeof(T));
		q = tmp;
		end = front = 0;
		max_size = tmp_size;
		size = 0;
	}

	~ArrayQ()
	{
		delete[] q;
	}
	
	void enqueue(T data)
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

	T dequeue()
	{
		if (is_empty())
		{
			printf("Error : failed Dequeue, End of Queue\n");
			return T();
		}
		size--;
		front = (front + 1) % max_size;
		return q[front];
	}

	T get_front()
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
		return (_msize(q) / sizeof(T)) - 1;
	}

	bool is_empty()
	{
		return front == end;
	}

	void grow_size(int Up)
	{
		max_size = max_size + Up;
		q = (T*)realloc(q, max_size * sizeof(T));
	}
};