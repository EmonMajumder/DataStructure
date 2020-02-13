#pragma once
class StackNode
{
private:
	int x;
	int y;	
public:
	StackNode *next;
	StackNode();
	StackNode(int x, int y, StackNode* next);
	virtual ~StackNode();
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	StackNode *getNext();
	void setNext(StackNode *next);
};

