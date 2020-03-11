#include "pch.h"
#include <iostream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <ctime>
#include <string>
#include <fstream>
#include "sortObj.h"

using namespace std;


sortObj::sortObj()
{
	arraysize = 100;
	valuelimit = 32767;
	a = new int[arraysize];
	copya = new int[arraysize];
}

sortObj::sortObj(int arraysize)
{
	this->arraysize = arraysize;
	this->valuelimit = 32767;
	this->a = new int[arraysize];
	this->copya = new int[arraysize];
}

sortObj::~sortObj()
{
	delete[] a;
}

void sortObj::fillArray()
{
	srand((unsigned)time(0));

	int randomNumber = 0;

	for (int i = 0;i < arraysize;i++)
	{
		randomNumber = rand() % valuelimit;
		a[i] = randomNumber;
	}
}

void sortObj::copyarray()
{
	for (int i = 0; i < arraysize; i++)
	{
		copya[i] = a[i];
	}
}

void sortObj::showarray(int a[], string arrayType)
{	
	cout << arrayType << endl;

	for (int i = 0; i < arraysize; i++)
	{
		cout << a[i];

		if (i == arraysize - 1)
		{
			cout << "\n" << endl;
		}
		else
		{
			cout << ", ";
		}
	}
}

void sortObj::bubbleSort()
{
	int outer, inner, temp;
	for (outer = arraysize - 1; outer > 0; outer--)
	{
		for (inner = 0; inner < outer; inner++)
		{
			if (copya[inner] > copya[inner + 1])
			{
				temp = copya[inner];
				copya[inner] = copya[inner + 1];
				copya[inner + 1] = temp;
			}
		}
	}
}

void sortObj::selectionSort()
{
	int outer, inner, min, temp;
	for (outer = 0; outer < arraysize - 1; outer++)
	{
		min = outer;

		for (inner = outer + 1; inner < arraysize; inner++)
		{
			if (copya[inner] < copya[min])
			{
				min = inner;
			}
		}

		temp = copya[outer];
		copya[outer] = copya[min];
		copya[min] = temp;
	}
}

void sortObj::insertionSort()
{
	int i, j, temp;
	for (i = 1; i < arraysize; i++)
	{
		temp = copya[i];

		for (j = i - 1; j >= 0 && copya[j] > temp; j--)
		{
			copya[j + 1] = copya[j];
		}
		copya[j + 1] = temp;
	}
}

void sortObj::shellSort()
{
	int i, j, increment, temp;
	for (increment = arraysize / 2; increment > 0; increment /= 2)
	{
		for (i = increment; i < arraysize; i++)
		{
			temp = copya[i];
			for (j = i; j >= increment; j -= increment)
			{
				if (temp < copya[j - increment])
				{
					copya[j] = copya[j - increment];
				}
				else
				{
					break;
				}
			}
			copya[j] = temp;
		}
	}
}

void merge(int a[], int first, int middle, int last, int tempArray[])
{
	int i = first, j = middle + 1, k = 0;

	while (i <= middle && j <= last)
	{
		if (a[i] <= a[j])
		{
			tempArray[k] = a[i];
			i++;
		}
		else
		{
			tempArray[k] = a[j];
			j++;
		}
		k++;
	}

	while (i <= middle)
	{
		tempArray[k] = a[i];
		i++;
		k++;
	}

	while (j <= last)
	{
		tempArray[k] = a[j];
		j++;
		k++;
	}

	for (i = 0; i <= last - first; i++)
		a[first + i] = tempArray[i];
}

void sortObj::mergeSort(int a[], int first, int last, int tempArray[])
{
	if (first < last)
	{
		int middle = (first + last) / 2;
		mergeSort(a, first, middle, tempArray);
		mergeSort(a, middle + 1, last, tempArray);
		merge(a, first, middle, last, tempArray);
	}
}

int partition(int a[], int left, int right)
{
	int pivot_element = a[left];
	int lb = left, ub = right;
	int temp;

	while (left < right)
	{
		while (a[left] <= pivot_element)
			left++;
		while (a[right] > pivot_element)
			right--;
		if (left < right)
		{
			temp = a[left];
			a[left] = a[right];
			a[right] = temp;
		}
	}
	a[lb] = a[right];
	a[right] = pivot_element;
	return right;
}

void sortObj::quickSort(int a[], int left, int right)
{
	int pivot = 0;

	if (left < right)
	{
		pivot = partition(a, left, right);
		quickSort(a, left, pivot - 1);
		quickSort(a, pivot + 1, right);
	}
}



//-------------------------------------- Part-2 ---------------------------------------

// A utility function to get maximum value in arr[] 
int getMax(int a[], int n)
{
	int mx = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > mx)
			mx = a[i];
	}
	return mx;
}

// A function to do counting sort of arr[] according to 
// the digit represented by exp. 
void countSort(int a[], int n, int exp, int temp[])
{
	int i, count[10] = { 0 };

	// Store count of occurrences in count[] 
	for (i = 0; i < n; i++)
	{
		count[(a[i] / exp) % 10]++;
	}

	// Change count[i] so that count[i] now contains actual 
	//  position of this digit in output[] 
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Build the output array 
	for (i = n - 1; i >= 0; i--)
	{
		temp[count[(a[i] / exp) % 10] - 1] = a[i];
		count[(a[i] / exp) % 10]--;
	}

	// Copy the output array to arr[], so that arr[] now 
	// contains sorted numbers according to current digit 
	for (i = 0; i < n; i++)
		a[i] = temp[i];
}

// The main function to that sorts arr[] of size n using  
// Radix Sort 
void sortObj::radixSort(int a[], int n, int temp[])
{
	// Find the maximum number to know number of digits 
	int m = getMax(a, n), exp;

	// Do counting sort for every digit. Note that instead 
	// of passing digit number, exp is passed. exp is 10^i 
	// where i is current digit number 
	for (exp = 1; m / exp > 0; exp *= 10)
		countSort(a, n, exp, temp);
}

int getArraysize()
{
	int arraysize;
	string arraysizeinput;

	while (true)
	{
		cout << "Define the array size: ";
		try
		{
			getline(cin, arraysizeinput);
			arraysize = stoi(arraysizeinput);
			if (arraysize < 100001)
			{
				break;
			}
			else
			{
				cout << "Array size must be smaller then 100001" << endl;
			}
		}
		catch (exception e)
		{
			cin.clear();
			cout << "Invalid input" << endl;
		}
	}

	return arraysize;
}

void writesortedArray(string file, string writeornot, int a[], int arraysize)
{
	if (writeornot == "y" || writeornot == "Y")
	{
		ofstream outputfile;
		outputfile.open(file);

		for (int i = 0; i < arraysize; i++)
		{
			outputfile << a[i];

			if (i != arraysize - 1)
			{
				outputfile << ", ";
			}

			if (i % 20 == 0 && i > 0)
			{
				outputfile << "\n";
			}
		}

		outputfile.close();
	}
}
