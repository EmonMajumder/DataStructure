// Sorting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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


void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m-l+1;
	int n2 = r - m;

	/* create temp arrays */
	int *L = new int[n1];
	int *R = new int[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	k = l; // Initial index of merged subarray 
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	   are any */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	   are any */
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int a[], int l, int r)
{
	if (l<r)
	{
		int m = l+(r - l) / 2;
		mergeSort(a, l, m);
		mergeSort(a, m+1, r);
		merge(a, l, m, r);
	}
}

int main()
{
	double t1, t2;
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
	t1 = clock();
	bubbleSort(copya, arraysize);
	t2 = clock();
	showarray(copya, arraysize);
	cout << "Bubble Sort\t: " << (t2 - t1) / CLK_TCK << " sec\n";*/

	/*copyarray(a);
	showarray(copya, arraysize);
	t1 = clock();
	insertionSort(copya, arraysize);
	t2 = clock();
	showarray(copya, arraysize);
	cout << "Insertion Sort\t: " << (t2 - t1) / CLK_TCK << " sec\n";*/

	/*copyarray(a);
	showarray(copya, arraysize);
	t1 = clock();
	quickSort(copya, 0, arraysize-1);
	t2 = clock();
	showarray(copya, arraysize);
	cout << "Quick Sort\t: " << (t2 - t1) / CLK_TCK << " sec\n";*/

	/*copyarray(a);
	showarray(copya, arraysize);
	t1 = clock();
	selectionSort(copya, arraysize);
	t2 = clock();
	showarray(copya, arraysize);
	cout << "Selection Sort\t: " << (t2 - t1) / CLK_TCK << " sec\n";*/

	//copyarray(a);
	//showarray(copya, arraysize);
	//t1 = clock();
	//shellSort(copya, arraysize);
	//t2 = clock();
	//showarray(copya, arraysize);
	//cout << "Shell Sort\t: " << (t2 - t1) / CLK_TCK << " sec\n";

	copyarray(a);
	showarray(copya, arraysize);
	t1 = clock();
	mergeSort(copya, 0, arraysize-1);
	t2 = clock();
	showarray(copya, arraysize);
	cout << "Merge Sort\t: " << (t2 - t1) / CLK_TCK << " sec\n";
	
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
