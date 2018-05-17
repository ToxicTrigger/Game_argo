#pragma once
template <typename T>
class myStack
{
private:
	T* stack;
	int max = 100;
	int top;

public:
	myStack( )
	{
		stack = new T[100];
		top = 0;
	}

	myStack(int max)
	{
		stack = new T[max];
		this->max = max;
		top = 0;
	}
	~myStack()
	{
		if (stack) delete stack;
	}

	void push(T data)
	{
		if (!isFull())
		{
			stack[top++] = data;
		}
	}

	T pop()
	{
		if (!isEmpty())
		{
			T t = stack[--top];
			return t;
		}
		return T();
	}

	bool isEmpty()
	{
		return top == 0;
	}

	bool isFull()
	{
		return top == max;
	}
};

