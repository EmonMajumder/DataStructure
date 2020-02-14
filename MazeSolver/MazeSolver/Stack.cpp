#include "pch.h"
#include <iostream>
#include "StackNode.h"
#include "Stack.h"
using namespace std;

Stack::Stack() : top(NULL)
{
}

Stack::~Stack()
{
	while (top != NULL)
	{
		Pop();
	}
}

void Stack::Push(int x, int y)
{
	top = new StackNode(x, y, top);
}

StackNode* Stack::getTop()
{
	return top;
}

void Stack::Pop()
{
	if (top->getNext() != NULL)
	{
		StackNode *nodePtr = top;
		top = top->getNext();
		delete nodePtr;
	}
}
