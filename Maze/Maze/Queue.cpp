#include "Queue.h"
#include "pch.h"
using namespace std;

//Steps for ADDING a node to the list:
//Create a new node and Store data into the new node
//If there are no nodes in the list, make the new node the first node.
//Else
//Traverse the list to find the last node.
//Add the node to the end of the list.
//void Queue::Push(int x, int y)
//{
//	Node *newNode; // to point to the new node
//
//	//Allocate a new node.
//	newNode = new Node;
//	newNode->x = x;
//	newNode->y = y;
//	newNode->next = 0;
//
//	//If there are no nodes in the list make newNode the 1st node
//	if (!front)
//	{
//		front = newNode;
//		back = newNode;
//	}
//	else
//	{
//		back->next = newNode;
//		back = newNode;			
//	}						
//}
//end method AddNode


//void Queue::Pop()
//{
//	Node *nodePtr;			// To move through the list
//	nodePtr = front;		// Move nodePointer to head of list
//	if (!front)
//	{
//		Node *nodePtr = front;
//		front = front->next;
//		delete nodePtr;
//	}
//}
