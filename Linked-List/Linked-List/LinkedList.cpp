#include "pch.h"
#include <iostream>
#include <fstream>
#include "LinkedList.h"
using namespace std;

//Traverse and display values in list
void LinkedList::DiaplayNode(int position)
{
	int i = 1;
	Node *nodePtr; // To move through the list
	nodePtr = head; // Move nodePointer to head of list

	while (nodePtr)// while it points to a node - traverse
	{
		if (i == position)
		{
			cout << "[" << nodePtr->turn << nodePtr->num << "]  ";
		}
		else
		{
			cout << nodePtr->turn << nodePtr->num << "  ";
		}
		nodePtr = nodePtr->next;
		i++;
	}
	cout << "" << endl;
}
//end method displayList

//Steps for ADDING a node to the list:
//Create a new node and Store data into the new node
//If there are no nodes in the list, make the new node the first node.
//Else
//Traverse the list to find the last node.
//Add the node to the end of the list.
void LinkedList::AddNode(char turn, int num)
{
	Node *newNode; // to point to the new node
	Node *nodePtr; // to move through the list

	//Allocate a new node and store turn and num there
	newNode = new Node;
	newNode->turn = turn;
	newNode->num = num;
	newNode->next = 0;

	//If there are no nodes in the list make newNode the 1st node
	if (!head)
	{
		head = newNode;
	}
	else // otherwise, traverse and insert newNode at end
	{
		nodePtr = head;				// initialize nodepointer to head of list
		while (nodePtr->next)		//travers to find last node
		{
			nodePtr = nodePtr->next;
		}

		//insert newNode as the last node
		nodePtr->next = newNode;
	}
}
//end method AddNode


//Reset a node number value to 0
void LinkedList::DeleteNode(int position)
{
	Node *nodePtr; // To move through the list
	nodePtr = head; // Move nodePointer to head of list

	for (int i = 0; i < position;i++)
	{
		if (i == position - 1)
		{
			nodePtr->num = 0;
			cout << "Lock combination deleted at " << position << ".It is now set to " << nodePtr->turn << nodePtr->num << endl;
		}
		nodePtr = nodePtr->next;
	}
}

//Generate the initial Lock combination.
void LinkedList::GenerateCombination()
{
	char direction;
	int num = 0;
	for (int i = 0; i < 7; i++)
	{
		if (i % 2 == 0)
		{
			direction = 'R';
		}
		else
		{
			direction = 'L';
		}
		AddNode(direction, num);
	}
}

//Save lock combination to a file. 
void LinkedList::SavetoFile(string *filename)
{
	ofstream myfile;
	myfile.open(*filename);
	myfile << "Code Combination\n";
	Node *nodePtr;				// To move through the list
	nodePtr = head;				// Move nodePointer to head of list

	while (nodePtr)				// while it points to a node - traverse
	{
		myfile << nodePtr->turn << nodePtr->num << "  ";
		nodePtr = nodePtr->next;
	}
	myfile << "" << endl;
	myfile.close();
}

//Replace a combination sequence at certain position.
void LinkedList::ReplaceNode(int num, int position)
{
	Node *nodePtr; // To move through the list
	nodePtr = head; // Move nodePointer to head of list

	for (int i = 0; i < position;i++)
	{
		if (i == position - 1)
		{
			nodePtr->num = num;
			cout << "Lock combination at " << position << " is set to " << nodePtr->turn << nodePtr->num << endl;
		}
		nodePtr = nodePtr->next;
	}
}

//Get the certain node. 
void LinkedList::GetNode(int position)
{
	Node *nodePtr; // To move through the list
	nodePtr = head; // Move nodePointer to head of list

	for (int i = 0; i < position;i++)
	{
		if (i == position - 1)
		{
			cout << nodePtr->turn << nodePtr->num << endl;
			break;
		}
		nodePtr = nodePtr->next;
	}
}

//Reset the combination sequence
void LinkedList::ResetNode()
{
	Node *nodePtr; // To move through the list
	nodePtr = head; // Move nodePointer to head of list

	for (int i = 0; i < 7; i++)
	{
		nodePtr->num = 0;
		nodePtr = nodePtr->next;
	}
	cout << "Lock combination was reset." << endl;
}
