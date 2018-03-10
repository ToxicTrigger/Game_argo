#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Stack
{
	struct Data
	{
		T data;
		Data* next;
		Data(T data, Data* next) : data(data), next(next) {}
	};

private:
	Data* stack;
	int max_size;
	Data top;
	int cur;

public:
	Stack() : top(0, NULL)
	{
		stack = &top;
		cur = 0;
	}

	Stack(int maxSize) : max_size(maxSize), top(0, NULL)
	{
		stack = &top;
		cur = 0;
	};

	Stack(const Stack& other) : max_size(other.max_size), top(other.top), stack(other.stack), cur(other.cur)
	{
	};

	void push(T data)
	{
		// when stack not overflow.
		if (cur < max_size)
		{
			Data* tmp = new Data(data, stack);
			stack = tmp;
			cur += 1;
		}
	};

	void clean()
	{
		Data top = Data(0,NULL);
		stack = &top;
	}

	T getTop()
	{
		T data = stack->data;
		return data;
	}

	T pop()
	{
		if (cur > 0)
		{
			T data = stack->data;
			Data* tmp = stack;
			stack = stack->next;
			delete tmp; 
			cur--;
			return data;
		}
		return NULL;
	};

	bool is_empty()
	{
		return stack == &top;
	};

	bool is_full()
	{
		if (cur == max_size) return true;
		return false;
	};

	int get_size()
	{
		return cur;
	};

	int getMaxSize()
	{
		return max_size;
	};




};

