#pragma once
class CintStack
{
	int* m_stack;
	int m_top;
	int m_stack_size;

public:
	CintStack(int Max=500) : m_top(0), m_stack_size(Max) 
	{ 
		m_stack = new int[Max];
	}
	~CintStack() { ; }

	void push(int Val)
	{
		isFull() ? -1 : m_stack[m_top++] = Val;
	}

	int pop()
	{
		return isEmpty() ? -1 : m_stack[--m_top];
	}

	int getTop()
	{
		return m_stack[m_top - 1];
	}

	bool isEmpty() { return m_top == 0; }
	bool isFull() { return m_top == m_stack_size; }
	
};

