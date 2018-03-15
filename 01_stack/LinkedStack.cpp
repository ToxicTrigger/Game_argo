#include "LinkedStack.h"

void LinkedStack::push(int data)
{
	if (size >= max_size) return;

	Node* tmp = new Node;
	tmp->data = data;
	tmp->next = top;
	top = tmp;
	size++;
}

int LinkedStack::pop()
{
	if (is_empty()) return 0;

	Nptr tmp = top;
	size--;
	int item = tmp->data;
	top = top->next;
	delete tmp;
	return item;
}

bool LinkedStack::is_empty()
{
	return size == 0;
}

int LinkedStack::get_size()
{
	return size;
}
