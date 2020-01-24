#pragma once
using namespace std;

class LinkedList {

private:

	struct Node {
		char turn;
		int num;
		struct Node *next;
	};

	Node *head;

public:

	LinkedList() { head = 0; };
	void DiaplayNode(int position);
	void AddNode(char turn, int num);
	//void InsertNode(char turn, int num, int position);
	void ReplaceNode(int num, int position);
	void GetNode(int position);
	void ResetNode();
	void DeleteNode(int position);
	void GenerateCombination();
	void SavetoFile(string *filename);
};

