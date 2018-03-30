#pragma once
#include <stdlib.h>
#include <malloc.h>
#include "Tile.h"

class ArrayQ
{
private:
	Tile* q;
	int front;
	int end;
	int max_size;
	int size;

public:
	ArrayQ(int MaxSize)
	{
		int tmp_size = MaxSize + 1;
		Tile * tmp = (Tile*)malloc(tmp_size * sizeof(Tile));
		q = tmp;
		end = front = 0;
		max_size = tmp_size;
		size = 0;
	}

	~ArrayQ()
	{
		//delete[] q;
	}
	
	void enqueue(Tile data)
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

	Tile dequeue()
	{
		if (is_empty())
		{
			printf("Error : failed Dequeue, End of Queue\n");
			return Tile(-1, -1);
		}
		size--;
		front = (front + 1) % max_size;
		return q[front];
	}

	Tile get_front()
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
		q = (Tile*)realloc(q, max_size * sizeof(int));
	}
};