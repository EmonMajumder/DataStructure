#pragma once
#include "StackNode.h"
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
};

