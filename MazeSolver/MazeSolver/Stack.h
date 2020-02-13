#pragma once
#include "stacknode.h"
using namespace std;

class Stack
{
private:
	StackNode *top;

public:
	Stack();
	void Push(int x, int y);
	void Pop();
	StackNode *getTop();
	virtual  ~Stack();
	friend ostream& operator<<(ostream& output, Stack& stack);
};

