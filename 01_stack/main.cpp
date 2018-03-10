#include <iostream>
#include "Stack.h"
#include "Calculator.h"

using namespace std;

void main()
{
	Calculator calc;
	float in;
	bool end = false;
	while (!end)
	{
		cout << "값을 입력하세요. [끝내려면 0을 입력해주세요.]" << endl;
		cin >> in;
		if (in == 0) { end = true; return; }
		calc.stack.push(in);

		cout << "값을 입력하세요." << endl;
		cin >> in;
		calc.stack.push(in);

		cout << "연산자를 입력하세요." << endl;
		char op;
		cin >> op;
		calc.op.push(op);

		cout << "result = " << calc.calc() << endl;
	}
}