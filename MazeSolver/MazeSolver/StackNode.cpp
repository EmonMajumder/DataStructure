#include "pch.h"
#include <iostream>
#include "StackNode.h"


StackNode::StackNode() : x(0), y(0), next(NULL)
{
}

StackNode::StackNode(int x, int y, StackNode* next) : x(x), y(y), next(next)
{
}

StackNode::~StackNode()
{
}

int StackNode::getX()
{
	return x;
}

void StackNode::setX(int x)
{
	x = x;
}

int StackNode::getY()
{
	return y;
}

void StackNode::setY(int y)
{
	y = y;
}

StackNode* StackNode::getNext()
{	
	return next;
}

void StackNode::setNext(StackNode *next)
{
	next = next;
}
