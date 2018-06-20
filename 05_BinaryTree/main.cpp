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
		cout << "삽입할 데이터 : ";
		cin >> input;

		insertNode(Tree, createNode(input));

		cout << "검색할 데이터 : ";
		cin >> input;

		find = searchNode(Tree, input);
		if (find != NULL)
		{
			cout << "검색 결과" << find->Data << endl;
			printTree(find);
			cout << endl;
		}
		else {
			cout << "검색한 결과의 노드가 존재하지 않네요" << endl;

		}

		cout << "현재 트리의 상태 : ";
		printTree(Tree);
		cout << endl;


		cout << "삭제할 데이터 : ";
		cin >> input;

		removeNode(Tree, input);
		printTree(Tree);
		cout << endl;
	}
}