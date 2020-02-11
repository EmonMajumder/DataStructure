// Maze.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Queue.h"
using namespace std;

int * MazeSize(string file) {
	int row = 0;
	int col = 0;
	int size[2];
	char currentchar = NULL;

	ifstream myReadFile;
	myReadFile.open(file);

	char output;
	myReadFile.get(output);

	while (!myReadFile.eof()) {
		if (output != '\n')
		{
			if (currentchar == '\n')
			{
				row++;
				col = 0;
			}
			else
				col++;
		}
		currentchar = output;
		myReadFile.get(output);
	}
	myReadFile.close();
	size[0] = row;
	size[1] = col;
	return size;
}

char **Maze(string file) {
	int *size = MazeSize("C:\\DataStructure\\Maze\\maze.txt");
	int row = size[0];
	int col = size[1]+1;

	char** maze = new char *[row];

	for (int i = 0; i <= row; i++)
	{
		maze[i] = new char[col];
	}

	int i = 0;
	int j = 0;
	ifstream myReadFile;
	myReadFile.open(file);

	char output;

	myReadFile.get(output);

	while (i <= row) {
		maze[i][j] = output;
		if (output == '\n')
		{
			i++;
			j = 0;
		}
		else
		{
			j++;
		}
		myReadFile.get(output);		
	}
	myReadFile.close();

	return maze;
}

int *StartingPoint(char **maze,int row, int col) {
	for (int i = 0; i <= row; i++) {
		if (maze[i][0] == ' ')
		{
			int startingPoint[] = {i,0};
			return startingPoint;
		}
	}
	for (int j = 0; j <= col; j++) {
		if (maze[0][j] == ' ')
		{
			int startingPoint[] = { 0,j };
			return startingPoint;
		}
	}
}

int *EndPoint(char **maze, int row, int col) {
	for (int i = 0; i <= row; i++) {
		if (maze[i][col] == ' ')
		{
			int endPoint[] = { i,col };
			return endPoint;
		}
	}
	for (int j = 0; j <= col; j++) {
		if (maze[row][j] == ' ')
		{
			int endPoint[] = { 0,j };
			return endPoint;
		}
	}
}


int main() {

	int *size;
	size = MazeSize("C:\\DataStructure\\Maze\\maze.txt");
	int x = size[0];
	int y = size[1];
	char **maze = Maze("C:\\DataStructure\\Maze\\maze.txt");
	

	int *startingPoint;
	startingPoint = StartingPoint(maze,x,y);
	//cout << startingPoint[0] << startingPoint[1] << endl;
	int *endPoint;
	endPoint = EndPoint(maze, x, y);
	//cout << endPoint[0] << endPoint[1] << endl;

	int mazerow = startingPoint[0];
	int mazecol = startingPoint[1];

	while(true)
	{
		if (mazerow == endPoint[0] && mazecol == endPoint[1])
		{
			break;
		}
	}

	for (int i = 0; i <= x; i++)
	{
		for (int j = 0; j <= y + 1; j++)
		{
			cout << maze[i][j];
		}
	}

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