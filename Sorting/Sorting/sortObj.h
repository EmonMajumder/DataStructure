#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

class sortObj
{
public:
	int arraysize;
	int valuelimit;
	int *a;
	int *copya;
	sortObj();
	sortObj(int arraysize);
	void fillArray();
	void copyarray();
	void showarray(int a[], string arrayType);
	void bubbleSort();
	void selectionSort();
	void insertionSort();
	void shellSort();
	void quickSort(int a[], int left, int right);
	void mergeSort(int a[], int first, int last, int tempArray[]);
	void radixSort(int a[], int n, int temp[]);
	~sortObj();
};

int getArraysize();
void writesortedArray(string file, string writeornot, int a[], int arraysize);

