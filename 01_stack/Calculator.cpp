#include "Calculator.h"

Calculator::Calculator(int max)
{
	form = new char[max];
	result = 0;
	cur_pos = 0;
}

enum Data_type{ PLUS, MINUS, MULTI, DIV, NUMBER, BLANK, END };
int Calculator::get_token(char* token)
{
	int pos = 0;
	switch (form[cur_pos])
	{
	case '+': 
		token[pos++] = form[cur_pos++];
		token[pos] = '\0';
		return PLUS;
	case '-':
		token[pos++] = form[cur_pos++];
		token[pos] = '\0';
		return MINUS;
	case '*':
		token[pos++] = form[cur_pos++];
		token[pos] = '\0';
		return MULTI;
	case '/':
		token[pos++] = form[cur_pos++];
		token[pos] = '\0';
		return DIV;
	case ' ':
		cur_pos++;
		return BLANK;
	case '\0':
		return END;
	case '=':
		return END;
	default:
		while (form[cur_pos] > '0' && form[cur_pos] <= '9')
		{
			token[pos++] = form[cur_pos++];

		}
		token[pos] = '\0';
		return NUMBER;
	}
	return 0;
}

void Calculator::calc()
{
	int tag;
	int num;
	char token[20];
	int a, b;

	cur_pos = 0;
	while ((tag = get_token(token)) != END)
	{
		switch (tag)
		{
		case PLUS:
			b = stack.pop();
			a = stack.pop();
			stack.push(a + b);
			break;
		case MINUS:
			b = stack.pop();
			a = stack.pop();
			stack.push(a - b);
			break;
		case MULTI:
			b = stack.pop();
			a = stack.pop();
			stack.push(a * b);
			break;
		case DIV:
			b = stack.pop();
			a = stack.pop();
			stack.push(a / b);
			break;
		case BLANK:
			break;
		case NUMBER:
			num = 0;
			for (int i = 0; token[i] != '\0'; i++)
			{
				num = num * 10 + token[i] - '0';
			}
			stack.push(num);
			break;
		}
	}
	result = stack.pop();
}

void Calculator::set_form(char * in)
{
	form = in;
}

void Calculator::infix_to_postfix(char * in, char * post)
{

}
