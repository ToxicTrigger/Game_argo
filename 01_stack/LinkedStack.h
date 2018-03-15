#pragma once

struct Node
{
	int data;
	Node* next;
};

typedef Node* Nptr;

class LinkedStack
{
private:
	Nptr top;
	int size;
	int max_size;
public:
	LinkedStack(): max_size(100)
	{
		top = new Node;
		size = 0;
	}

	LinkedStack(int maxSize) : max_size(maxSize) { size = 0; }

	~LinkedStack()
	{
		//delete top;
	}

	void push(int data);
	int pop();
	bool is_empty();
	int get_size();
};

