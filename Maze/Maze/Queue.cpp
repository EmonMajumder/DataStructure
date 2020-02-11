#include "Queue.h"
#include "pch.h"
using namespace std;

void Queue::Push(int x, int y)
{
	Node *newNode; // to point to the new node

	//Allocate a new node.
	newNode = new Node;
	newNode->x = x;
	newNode->y = y;
	newNode->next = 0;


	//If there are no nodes in the list make newNode the 1st node
	if (!front)
	{
		front = newNode;
		back = newNode;
	}
	else
	{
		back->next = newNode;
		back = newNode;			
	}						
}


void Queue::Pop()
{
	Node *nodePtr;			// To move through the list
	nodePtr = front;		// Move nodePointer to head of list
	if (!back)
	{
		Node *nodePtr = back;
		front = front->next;
		delete nodePtr;
	}
}
