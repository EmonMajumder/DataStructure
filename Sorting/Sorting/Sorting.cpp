// Sorting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <ctime>

using namespace std;

const int arraysize = 100;
const int valuelimit = 32767;
int copya[arraysize];

void copyarray(int a[])
{
	for (int i = 0; i < arraysize; i++)
	{
		copya[i] = a[i];
	}
}

void showarray(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << a[i] ;

		if (i == size - 1)
		{
			cout << "\n" << endl;
		}
		else
		{
			cout << ", ";
		}
	}
}

void bubbleSort(int a[],int size)
{
	int outer, inner, temp;
	for (outer = size-1; outer > 0; outer--)
	{
		for (inner = 0; inner < outer; inner++) 
		{              
			if (a[inner] > a[inner + 1]) 
			{             
				temp = a[inner];                       
				a[inner] = a[inner + 1];               
				a[inner + 1] = temp;            
			}        
		}    
	}
}

void selectionSort(int a[], int size)
{
	int outer, inner, min, temp;
	for (outer = 0; outer < size - 1; outer++)
	{       
		min = outer;

		for (inner = outer + 1; inner < size; inner++)
		{
			if (a[inner] < a[min])
			{
				min = inner;
			}
		}// a[min] is least among a[outer]..a[a.length - 1]     
		temp = a[outer];
		a[outer] = a[min];
		a[min] = temp;
	}
}

void insertionSort(int a[], int size)
{
	int i, j, temp;
	for (i = 1; i < size; i++)
	{
		temp = a[i];

		for (j = i - 1; j >= 0 && a[j] > temp; j--)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = temp;
	}
}

void shellSort(int a[], int size)
{
	int i, j, increment, temp;
	for (increment = size / 2; increment > 0; increment /= 2) 
	{ 
		for (i = increment; i < size; i++) 
		{ 
			temp = a[i];
			for (j = i; j >= increment; j -= increment) 
			{ 
				if (temp < a[j - increment]) 
				{ 
					a[j] = a[j - increment]; 
				} 
				else 
				{ 
					break; 
				} 
			}
			a[j] = temp; 
		}
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

void quickSort(int a[], int left, int right)
{
	int pivot = 0;

	if (left < right)
	{
		pivot = partition(a, left, right);
		quickSort(a, left, pivot - 1);
		quickSort(a, pivot + 1, right);
	}
}

void merge(int a[], int first, int middle, int last, int tempArray[])
{
	int i = first, j = middle+1, k=0;

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

void mergeSort(int a[], int first, int last, int tempArray[]) 
{ 
	if (first<last)
	{ 
		int middle = (first + last) / 2;
		mergeSort(a, first, middle, tempArray);
		mergeSort(a, middle+1, last, tempArray);
		merge(a, first, middle, last, tempArray); 
	}
}

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
	int i, count[10] = {0};

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
void radixSort(int a[], int n, int temp[])
{
	// Find the maximum number to know number of digits 
	int m = getMax(a, n), exp;

	// Do counting sort for every digit. Note that instead 
	// of passing digit number, exp is passed. exp is 10^i 
	// where i is current digit number 
	for (exp = 1; m / exp > 0; exp *= 10)
		countSort(a, n, exp, temp);
}

int main()
{
	srand((unsigned)time(0));

	int randomNumber = 0;
	int a[arraysize];
	
	for (int i = 0;i < arraysize;i++)
	{
		randomNumber = rand() % valuelimit;
		a[i] = randomNumber;
	}
	
	/*copyarray(a);
	showarray(copya, arraysize);	
	auto t1 = chrono::high_resolution_clock::now();
	bubbleSort(copya, arraysize);
	auto t2 = chrono::high_resolution_clock::now();
	showarray(copya, arraysize);
	cout << "Bubble Sort\t: " << (t2 - t1) / CLK_TCK << " sec\n";*/

	/*copyarray(a);
	showarray(copya, arraysize);
	auto t1 = chrono::high_resolution_clock::now();
	insertionSort(copya, arraysize);
	auto t2 = chrono::high_resolution_clock::now();
	showarray(copya, arraysize);
	cout << "Insertion Sort\t: " << (t2 - t1) / CLK_TCK << " sec\n";*/

	/*copyarray(a);
	showarray(copya, arraysize);
	auto t1 = chrono::high_resolution_clock::now();
	quickSort(copya, 0, arraysize-1);
	auto t2 = chrono::high_resolution_clock::now();
	showarray(copya, arraysize);
	cout << "Quick Sort\t: " << (t2 - t1) / CLK_TCK << " sec\n";*/

	/*copyarray(a);
	showarray(copya, arraysize);
	auto t1 = chrono::high_resolution_clock::now();
	selectionSort(copya, arraysize);
	auto t2 = chrono::high_resolution_clock::now();
	showarray(copya, arraysize);
	cout << "Selection Sort\t: " << (t2 - t1) / CLK_TCK << " sec\n";*/

	//copyarray(a);
	//showarray(copya, arraysize);
	//auto t1 = chrono::high_resolution_clock::now();
	//shellSort(copya, arraysize);
	//auto t2 = chrono::high_resolution_clock::now();
	//showarray(copya, arraysize);
	//cout << "Shell Sort\t: " << (t2 - t1) / CLK_TCK << " sec\n";

	/*copyarray(a);
	showarray(copya, arraysize);
	int b[arraysize];
	auto t1 = chrono::high_resolution_clock::now();
	mergeSort(copya, 0, arraysize-1, b);
	auto t2 = chrono::high_resolution_clock::now();
	showarray(copya, arraysize);
	cout << "Merge Sort\t: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << " milliseconds.";*/

	copyarray(a);
	showarray(copya, arraysize);
	int b[arraysize];
	auto t1 = chrono::high_resolution_clock::now();
	radixSort(copya, arraysize, b);
	auto t2 = chrono::high_resolution_clock::now();
	showarray(copya, arraysize);
	cout << "Merge Sort\t: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << " milliseconds.";
	
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
