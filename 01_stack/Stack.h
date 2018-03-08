#pragma once

template <typename T>
class Stack
{
private:
	int top;
	int size;
	int max_size;

	T stack[100];

public:
	Stack(int maxSize)
	{
		max_size = maxSize;
		top = 0;
		size = 0;
	};

	Stack(const Stack& other)
	{
		stack = other.stack;
		max_size = other.max_size;
		top = other.top;
		size = other.size;
	};

	void push(T data)
	{
		// when stack not overflow.
		if (top < max_size)
		{
			stack[top] = data;
			top += 1;
			//size = sizeof(data) / sizeof(stack);
		}
	};

	T pop()
	{
		if (top > 0)
		{
			T tmp = stack[--top];
			stack[top] = NULL;
			return tmp;
		}
		return NULL;
	};

	bool isEmpty()
	{

	};

	bool isFull()
	{

	};

	int getSize()
	{
		return size;
	};

	int getMaxSize()
	{

	};

	int getTop()
	{

	};



};

