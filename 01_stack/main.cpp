#include <iostream>
#include "Calculator.h"

using namespace std;


void main()
{

	Calculator c;
	char post[100];
	cin.getline(post, 100);
	c.set_form(post);
	c.calc();

	cout << c.get_result() << endl;

	getchar();
}