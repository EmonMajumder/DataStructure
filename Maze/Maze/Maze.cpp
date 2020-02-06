// Maze.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Queue.h"
using namespace std;

int main() {
	int row = 0;
	int col = 0;
	char currentchar = NULL;
	/*char **maze;
	maze = new char *[];
	maze[0] = new char[];*/
	ifstream myReadFile;
	//Queue queue;
	int x = 0;
	int y = 1;
	myReadFile.open("C:\\DataStructure\\Maze\\maze.txt");
	char output;
	myReadFile.get(output);
	while (!myReadFile.eof()) {
		cout << output;
		if (output != '\n')
		{
			col++;
		}		
		if (currentchar == '\n' && output != currentchar)
		{
			row++;
			col = 0;
		}
		currentchar = output;		
		myReadFile.get(output);				
	}
	myReadFile.close();
	cout << row << "<=>" << col << endl;

	//while(x < mazechar2.size()-1)
	//{
	//	int direction = 0;

	//	if (mazechar1.at(y).at(x - 1) == ' ')
	//	{
	//		x--;
	//		direction++;
	//		mazechar1[y][x] = 'o';
	//	}
	//	else if(mazechar1.at(y).at(x + 1) == ' ')
	//	{
	//		x++;
	//		direction++;
	//	}
	//	else if (mazechar1.at(y - 1).at(x) == ' ')
	//	{
	//		y--;
	//		direction++;
	//	}
	//	else if (mazechar1.at(y + 1).at(x) == ' ')
	//	{
	//		y++;
	//		direction++;
	//	}
	//	else
	//	{

	//	}
	//	if (direction > 0)
	//	{
	//		//queue.Push(j, i);
	//	}
	//}

	//cout << mazechar1.size() << endl;

	//int i = 0;
	//while (i < mazechar1.size()) {
	//	int j = 0;
	//	//cout << mazechar1[i].size() << endl;
	//	while (j < mazechar1.at(i).size())
	//	{
	//		cout << mazechar1.at(i).at(j);
	//		j++;
	//	}
	//	i++;
	//}
	return 0;
}