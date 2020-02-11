#pragma once
#include "pch.h"
using namespace std;

class Queue {

private:

	struct Node {
		int x;
		int y;
		Node *next;
		Node *prev;
	};

	Node *front;
	Node *back;

public:
	Queue() { front = 0; back = 0; };
	void Push(int x, int y);
	void Pop();
};



