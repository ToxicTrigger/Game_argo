#include <iostream>
#include "Stack.h"

using namespace std;

void main()
{
	Stack<int> tmp = Stack<int>(10);
	tmp.push(1);
	tmp.push(2);
	tmp.push(3);
	
	cout << tmp.pop() << endl;
	cout << tmp.pop() << endl;
	cout << tmp.pop() << endl;
	cout << tmp.pop() << endl;
	getchar();

}