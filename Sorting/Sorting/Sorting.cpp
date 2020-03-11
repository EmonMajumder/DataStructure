// Sorting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "sortObj.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <ctime>

using namespace std;

int main()
{
	int arraysize= getArraysize();
	string writeornot;

	sortObj sortobj(arraysize);
	sortobj.fillArray();
	
	cout << "Do you want to write output to a file? (Y/N) : ";
	getline(cin, writeornot);

	//sortobj.showarray(sortobj.a, "Unsorted Array");
	sortobj.copyarray();
	auto t1 = chrono::high_resolution_clock::now();
	sortobj.bubbleSort();
	auto t2 = chrono::high_resolution_clock::now();
	writesortedArray("BubbleSort.txt", writeornot, sortobj.copya, sortobj.arraysize);
	//sortobj.showarray(sortobj.copya, "Sorted Array");
	cout << "Bubble Sort\t: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << " milliseconds." << endl;

	//sortobj.showarray(sortobj.a, "Unsorted Array");
	sortobj.copyarray();
	t1 = chrono::high_resolution_clock::now();
	sortobj.selectionSort();
	t2 = chrono::high_resolution_clock::now();
	//sortobj.showarray(sortobj.copya, "Sorted Array");
	writesortedArray("SelectionSort.txt", writeornot, sortobj.copya, sortobj.arraysize);
	cout << "Selection Sort\t: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << " milliseconds." << endl;

	//sortobj.showarray(sortobj.a, "Unsorted Array");
	sortobj.copyarray();
	t1 = chrono::high_resolution_clock::now();
	sortobj.insertionSort();
	t2 = chrono::high_resolution_clock::now();
	//sortobj.showarray(sortobj.copya, "Sorted Array");
	writesortedArray("InsertionSort.txt", writeornot, sortobj.copya, sortobj.arraysize);
	cout << "Insertion Sort\t: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << " milliseconds." << endl;

	//sortobj.showarray(sortobj.a, "Unsorted Array");
	sortobj.copyarray();
	t1 = chrono::high_resolution_clock::now();
	sortobj.shellSort();
	t2 = chrono::high_resolution_clock::now();
	//sortobj.showarray(sortobj.copya, "Sorted Array");
	writesortedArray("ShellSort.txt", writeornot, sortobj.copya, sortobj.arraysize);
	cout << "Shell Sort\t: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << " milliseconds." << endl;

	//sortobj.showarray(sortobj.a, "Unsorted Array");
	sortobj.copyarray();
	int *b = new int[arraysize];
	t1 = chrono::high_resolution_clock::now();
	sortobj.mergeSort(sortobj.copya, 0, arraysize-1, b);
	t2 = chrono::high_resolution_clock::now();
	//sortobj.showarray(sortobj.copya, "Sorted Array");
	writesortedArray("MergeSort.txt", writeornot, sortobj.copya, sortobj.arraysize);
	cout << "Merge Sort\t: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << " milliseconds." << endl;
	delete[] b;

	//sortobj.showarray(sortobj.a, "Unsorted Array");
	sortobj.copyarray();
	t1 = chrono::high_resolution_clock::now();
	sortobj.quickSort(sortobj.copya, 0, arraysize - 1);
	t2 = chrono::high_resolution_clock::now();
	//sortobj.showarray(sortobj.copya, "Sorted Array");
	writesortedArray("QuickSort.txt", writeornot, sortobj.copya, sortobj.arraysize);
	cout << "Quick Sort\t: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << " milliseconds." << endl;

	//sortobj.showarray(sortobj.a, "Unsorted Array");
	sortobj.copyarray();
	b = new int[arraysize];
	t1 = chrono::high_resolution_clock::now();
	sortobj.radixSort(sortobj.copya, arraysize, b);
	t2 = chrono::high_resolution_clock::now();
	//sortobj.showarray(sortobj.copya, "Sorted Array");
	writesortedArray("RadixSort.txt", writeornot, sortobj.copya, sortobj.arraysize);
	cout << "Radix Sort\t: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << " milliseconds." << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
