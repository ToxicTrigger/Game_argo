#include "Calculator.h"

int Calculator::calc()
{
	int a, b;
	a = stack.pop();
	b = stack.pop();

	switch (op.pop())
	{
	case '+':
		stack.push(a + b);
		return stack.getTop();
		break;
	case '-':
		stack.push(a - b);
		return stack.getTop();
		break;
	case '*':
		stack.push(a * b);
		return stack.getTop();
		break;
	case '/':
		stack.push(a / b);
		return stack.getTop();
		break;
	case '%':
		stack.push(a % b);
		return stack.getTop();
		break;
	}
}
