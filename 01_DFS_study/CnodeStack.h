#pragma once
#include "base.h"

class CnodeStack
{
	node* m_stack;
	int m_top;
public:

	CnodeStack(int Max = 500) : m_top(0)
	{
		m_stack = new node[Max];
	}

	~CnodeStack()
	{
		if (m_stack) delete m_stack;
	}

	void push(node val) { m_stack[m_top++] = val; }
	node pop() { return m_stack[--m_top]; }
	node getTop() { return m_stack[m_top - 1]; }
	bool isEmpty() { return m_top == 0; }
};

