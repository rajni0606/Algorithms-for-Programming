/*
C++ program to demonstrate the implementation of Quick Sort such that positive and negative numbers
alternate in position. Also, in case the number of positive integers is more than that of negative,
or vice-versa, they would be shifted to the end and sorted as usual using a quick sort.
Contributed to  Data-Science-Community-SRM on Github
Contributor: Rajni Soundararajan 
GitHub username : rajni0606
*/

#include <iostream.h>
#include <algorithm.h>
#include <iomanip.h>
using namespace std;

// Partitioning routine of quicksort
int partition(int A[], int n)
{
	int j = 0;
	int pivot = 0;	// consider 0 as pivot

	// each time we find a negative number, j is incremented
	// and negative element would be placed before the pivot
	for (int i = 0; i < n; i++)
	{
		if (A[i] < pivot)
		{
			swap(A[i], A[j]);
			j++;
		}
	}

	// j holds index of first positive element
	return j;
}

// Function to rearrange given array such that it contains positive
// and negative numbers at alternate positions
int rearrange(int A[], int size)
{
	// partition given array such that all positive elements move
	// to end of the array
	int p = partition(A, size);

	// swap alternate negative element from next available positive
	// element till end of array is reached or all negative or
	// positive elements are exhausted.
	for (int n = 0; (p < size && n < p); p++, n += 2) {
		swap(A[n], A[p]);
	}
}

int main()
{
	int A[] = { 9, -3, 5, -2, -8, -6, 1, 3 };
	int n = sizeof(A)/sizeof(A[0]);

	rearrange(A, n);

	// print the rearranged array
	for (int i = 0 ; i < n; i++) {
		cout << setw(3) << A[i];
	}

	return 0;
}