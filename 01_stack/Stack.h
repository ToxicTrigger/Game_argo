#pragma once

template <typename T>
class Stack
{
private:
	int top;
	int max_size;

	T stack[100];

public:
	Stack(int maxSize)
	{
		max_size = maxSize;
		top = 0;
	};

	Stack(const Stack& other)
	{
		stack = other.stack;
		max_size = other.max_size;
		top = other.top;
	};

	void push(T data)
	{
		// when stack not overflow.
		if (top < max_size)
		{
			stack[top] = data;
			top += 1;
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
		if (top == 0) return false;
		return true;
	};

	bool isFull()
	{
		if (top == max_size) return true;
		return false;
	};

	int getSize()
	{
		return top;
	};

	int getMaxSize()
	{
		return max_size;
	};

	int getTop()
	{
		return top;
	};



};

