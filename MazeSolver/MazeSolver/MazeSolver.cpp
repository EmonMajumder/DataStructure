// MazeSolver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <cstdlib>
#include "Stack.h"
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

	int *size = MazeSize(file);

	int row = size[0];
	int col = size[1] + 1;

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

	while (!myReadFile.eof()) {
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

int StartingPointX(char **maze, int row, int col) {
	for (int i = 0; i <= row; i++) {
		if (maze[i][0] == ' ')
		{
			return i;
		}
	}
	for (int j = 0; j <= col; j++) {
		if (maze[0][j] == ' ')
		{
			return 0;
		}
	}
}

int StartingPointY(char **maze, int row, int col) {
	for (int i = 0; i <= row; i++) {
		if (maze[i][0] == ' ')
		{
			return 0;
		}
	}
	for (int j = 0; j <= col; j++) {
		if (maze[0][j] == ' ')
		{
			return j;
		}
	}
}

int EndPointX(char **maze, int row, int col) {
	for (int i = 0; i <= row; i++) {
		if (maze[i][col] == ' ')
		{
			return i;
		}
	}
	for (int j = 0; j <= col; j++) {
		if (maze[row][j] == ' ')
		{
			return 0;
		}
	}
}

int EndPointY(char **maze, int row, int col) {
	for (int i = 0; i <= row; i++) {
		if (maze[i][col] == ' ')
		{
			return col;
		}
	}
	for (int j = 0; j <= col; j++) {
		if (maze[row][j] == ' ')
		{
			return j;
		}
	}
}

string ValidateInputFilename()
{
	string file;
	string filename;
	ifstream inStream;
	regex rextxt(R"(^\S+(\s\S+)*\.txt$)");
	regex rex(R"(^\S+(\s\S+)*$)");

	//While loop for continually asking filename for invalid input
	while (true)
	{
		cout << "Type exit to close program" << endl;
		cout << "File Name: ";
		getline(cin, filename);

		transform(filename.begin(), filename.end(), filename.begin(),[](unsigned char c) { return tolower(c); });
		
		if (filename == "exit")
		{
			return filename;
		}
		else
		{
			//Regex comparism
			if (regex_match(filename, rex))
			{
				if (!regex_match(filename, rextxt))
				{
					filename += ".txt";
				}

				file = "C:\\DataStructure\\MazeSolver\\" + filename;
				inStream.open(file);

				if (!inStream.fail())
				{
					inStream.close();
					break;
				}
				else
				{
					cout << "File was not found. Please Check file name." << endl;
					cin.clear();
				}
			}
			else
			{
				//Check if no input given.
				if (file.empty())
				{
					cout << "Please input a filename." << endl;
					cin.clear();
				}
				else
				{
					cout << "Incorrect filename." << endl;
					cin.clear();
				}
			}
		}		
	}
	return file;
}


int main() {

	Stack stack;
	string file = "";
	int *size;
	int height = 0;
	int width = 0;
	int dir = 1;
	char **maze;
	int endPointX = 0;
	int endPointY = 0;
	int startingPointX = 0;
	int startingPointY = 0;
	int currentPosition[] = { 0,0 };

	while (true)
	{	
		file = ValidateInputFilename();
		if (file == "exit")
		{
			break;
		}

		size = MazeSize(file);
		height = size[0];
		width = size[1];
		maze = Maze(file);

		endPointX = EndPointX(maze, height, width);
		endPointY = EndPointY(maze, height, width);
		startingPointX = StartingPointX(maze, height, width);
		startingPointY = StartingPointY(maze, height, width);

		currentPosition[0] = startingPointX;
		currentPosition[1] = startingPointY;

		maze[startingPointX][startingPointY] = '#';

		while (true)
		{
			int random = rand() % 100 + 1;
			if (random % 2 == 0)
			{
				dir = -1;
			}
			else
			{
				dir = 1;
			}

			if (maze[currentPosition[0] - dir][currentPosition[1]] == ' ')
			{
				currentPosition[0] = currentPosition[0] - dir;
				maze[currentPosition[0]][currentPosition[1]] = '#';
				stack.Push(currentPosition[0], currentPosition[1]);
			}
			else if (maze[currentPosition[0]][currentPosition[1] + dir] == ' ')
			{
				currentPosition[1] = currentPosition[1] + dir;
				maze[currentPosition[0]][currentPosition[1]] = '#';
				stack.Push(currentPosition[0], currentPosition[1]);
			}
			else if (maze[currentPosition[0] + dir][currentPosition[1]] == ' ')
			{
				currentPosition[0] = currentPosition[0] + dir;
				maze[currentPosition[0]][currentPosition[1]] = '#';
				stack.Push(currentPosition[0], currentPosition[1]);
			}
			else if (maze[currentPosition[0]][currentPosition[1] - dir] == ' ')
			{
				currentPosition[1] = currentPosition[1] - dir;
				maze[currentPosition[0]][currentPosition[1]] = '#';
				stack.Push(currentPosition[0], currentPosition[1]);
			}
			else
			{
				stack.Pop();
				maze[currentPosition[0]][currentPosition[1]] = '*';
				currentPosition[0] = stack.getTop()->getX();
				currentPosition[1] = stack.getTop()->getY();
			}

			if (currentPosition[0] == endPointX && currentPosition[1] == endPointY)
			{
				for (int i = 0; i <= height; i++)
				{
					for (int j = 0; j <= (width + 1); j++)
					{
						if (maze[i][j] == '*')
						{
							cout << ' ';
						}
						else
							cout << maze[i][j];
					}
				}
				break;
			}
		}
	}
	return 0;
}