#pragma once
#include "Stack.h"
#include <stdio.h>

class Calculator
{
private:

public:
	Stack<float> stack;
	Stack<char> op;

	inline Calculator::Calculator()
	{
		stack = Stack<float>(100);
		op = Stack<char>(100);
	}
	inline Calculator::~Calculator()
	{
	}

	float calc();
};

