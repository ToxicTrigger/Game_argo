#pragma once
#include "LinkedStack.h"
#include <stdio.h>

class Calculator
{
private:
	char* form;
	LinkedStack stack;
	int result;
	int cur_pos;
public:
	Calculator::Calculator(int max = 100);
	inline Calculator::~Calculator()
	{
	}

	// �Է� ���� �Ľ���
	int get_token(char* token);
	int get_result() { return result; }
	void calc();
	void set_form(char* in);
	void infix_to_postfix(char* in, char* post);
};

