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
		cout << "���� �Է��ϼ���. [�������� 0�� �Է����ּ���.]" << endl;
		cin >> in;
		if (in == 0) { end = true; return; }
		calc.stack.push(in);

		cout << "���� �Է��ϼ���." << endl;
		cin >> in;
		calc.stack.push(in);

		cout << "�����ڸ� �Է��ϼ���." << endl;
		char op;
		cin >> op;
		calc.op.push(op);

		cout << "result = " << calc.calc() << endl;
	}
}