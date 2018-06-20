#include <iostream>
#include "BTree.h"

using namespace std;

void main()
{
	Node * Tree = createNode(1);
	Node * find;
	int input;
	while (true)
	{
		cout << "������ ������ : ";
		cin >> input;

		insertNode(Tree, createNode(input));

		cout << "�˻��� ������ : ";
		cin >> input;

		find = searchNode(Tree, input);
		if (find != NULL)
		{
			cout << "�˻� ���" << find->Data << endl;
			printTree(find);
			cout << endl;
		}
		else {
			cout << "�˻��� ����� ��尡 �������� �ʳ׿�" << endl;

		}

		cout << "���� Ʈ���� ���� : ";
		printTree(Tree);
		cout << endl;


		cout << "������ ������ : ";
		cin >> input;

		removeNode(Tree, input);
		printTree(Tree);
		cout << endl;
	}
}