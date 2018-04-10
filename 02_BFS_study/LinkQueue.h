#pragma once
#include <stdio.h>

struct node
{
	int data;
	node* next;
};

class LinkQueue
{
private:
	node* head;
	node* tail;
	int size;

public:
	LinkQueue()
	{
		head = new node();
		tail = new node();

		head->next = tail;
		tail->next = tail;
		size = 0;
	}

	bool is_empty()
	{
		return head->next == tail;
	}

	void enqueue(int data)
	{
		node* tmp = head;

		while (tmp->next != tail)
		{
			tmp = tmp->next;
		}

		tmp->data = data;
		tmp->next = new node();
		tmp->next->next = tail;
		size++;
	}

	int dequeue()
	{
		if (is_empty())
		{
			printf("End\n");
			return -1;
		}

		int result = head->data;
		node* tmp = head;
		head = head->next;
		delete tmp;
		size--;
		return result;
	}

	int get_front()
	{
		return head->data;
	}

	int get_size()
	{
		return size;
	}
};