#include "Calculator.h"

float Calculator::calc()
{
	float a, b;
	a = stack.pop();
	b = stack.pop();

	switch (op.pop())
	{
	case '+':
		stack.push(b + a);
		return stack.getTop();
		break;
	case '-':
		stack.push(b - a);
		return stack.getTop();
		break;
	case '*':
		stack.push(b * a);
		return stack.getTop();
		break;
	case '/':
		stack.push(b / a);
		return stack.getTop();
		break;
	}
}
