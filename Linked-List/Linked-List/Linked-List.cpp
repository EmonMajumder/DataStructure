//Assignment1.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "pch.h"
#include <iostream>
#include <regex>
#include <fstream>
#include <regex>
#include <string>
#include "LinkedList.h"
using namespace std;


//Function for checking user input as argument and validating filename
int ValidateInputFilename(string *filename)
{
	regex rextxt(R"(^\S+(\s\S+)*$)");

	//Check filename for invalid input
	if (!regex_match(*filename, rextxt))
	{
		cout << "Invalid file name." << endl;
		return 0;
	}
	else
		return 1;
}

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		string filename = argv[1];
		string input;
		char command;
		regex rexfile(R"(^\S+(\s\S+)*(\.txt)$)");
		regex commandrex(R"(^Q|E|G|S|D|R|q|e|g|s|d|r$)");
		regex gotorex(R"(^(G|g)\s*\d$)");
		regex gotorexmore(R"(^(G|g)\s*\d+$)");
		regex replacerex(R"(^(S|s)\s\d{1,2}$)");
		regex replacerexspace(R"(^(S|s)\s\d+$)");
		regex replacerexmore(R"(^(S|s)\s*\d+$)");

		int position = 0;

		//If filename is valid.
		if (ValidateInputFilename(&filename))
		{
			if (!regex_match(filename, rexfile))
			{
				//Add .txt to filename if not passed in argument.
				filename = filename + ".txt";
			}

			LinkedList linkedList;

			//Generate a key combination.
			linkedList.GenerateCombination();

			//Display the key combination
			linkedList.DiaplayNode(position);

			//Loop for continuous user input.
			while (true)
			{
				//Check if position value is set.
				if (position != 0)
				{
					linkedList.DiaplayNode(position);
					cout << "Current working combination position: " << position << " Current combination: ";

					//Get and show combinarion at that position and 
					linkedList.GetNode(position);
				}

				cout << "\nCommand:";

				//Get User input
				getline(cin, input);

				if (regex_match(input, commandrex))
				{
					//Convert user input to uppercase.
					command = toupper(input[0]);

					if (command == 'Q')
					{
						return 0;
					}
					else if (command == 'E')
					{
						//Save linked list the a file.
						linkedList.SavetoFile(&filename);
						return  0;
					}
					else if (command == 'D')
					{
						if (position == 0)
						{
							cout << "Please select your current working position first with command G <position> to delete." << endl;
						}
						else
						{
							//Delete Node.
							linkedList.DeleteNode(position);
						}
					}
					else if (command == 'R')
					{
						//Reset combination
						linkedList.ResetNode();
					}
					else if (command == 'G')
					{
						cout << "Please input position number too." << endl;
					}
					else if (command == 'S')
					{
						if (position == 0)
						{
							cout << "Please select your current working position first with command G <position>. \nPlease input value to replace too." << endl;
						}
						else
							cout << "Please input value to replace too." << endl;
					}
				}
				else if (regex_match(input, gotorexmore))
				{
					if (regex_match(input, gotorex))
					{
						int i = 1;
						int inputposition;
						while (true)
						{
							if (input[i] != ' ')
							{
								inputposition = input[i] - '0';

								if (inputposition == 0 || inputposition > 7)
								{
									cout << "Invalid position. Valid position value is from 1 to 7." << endl;
								}
								else
								{
									position = inputposition;
								}
								break;
							}
							i++;
						}
					}
					else
						cout << "Invalid position value. Valid position value is from 1 to 7." << endl;
				}
				else if (regex_match(input, replacerexmore))
				{
					if (regex_match(input, replacerexspace))
					{
						if (regex_match(input, replacerex))
						{
							if (position == 0)
							{
								cout << "Please select your current working position first with command G <position>." << endl;
							}
							else
							{
								int num = input[2] - '0';

								if (input.length() == 4)
								{
									num = num * 10 + (input[3] - '0');
								}

								if (num > 49)
								{
									cout << "Only 0-49 is accepted as combination number." << endl;
								}
								else
								{
									//Replace combination number.
									linkedList.ReplaceNode(num, position);
								}
							}
						}
						else
							cout << "Only 0-49 is accepted as combination number." << endl;
					}
					else
					{
						cout << "Invalid input. Leave a single space between S and number." << endl;
					}
				}
				else
				{
					cout << "Invalid command." << endl;
					cout << "Valid Commands: Q (QUIT), E (EXIT), G (GOTO), S (SUBSTITUTE), D (DELETE), R (RESET)" << endl;
				}
			}
		}
		else
			return 0;
	}
	else if (argc > 2)
		cout << argc - 1 << " argument passed. Exactly 1 argument expected." << endl;
	else
		cout << "No argument passed. Exactly 1 argument expected" << endl;
	return 0;
}