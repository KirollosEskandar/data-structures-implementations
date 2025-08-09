// ConsoleApplication56.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;


//Insertion Sort
void InsertionSort(int arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		// 3 4 2 0 9 
		// 3 4 4 0 9 
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && key < arr[j])
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

int main()
{
	int arr[] = { 3, 4, 2, 0, 9 };
	InsertionSort(arr, 5);
	for (int i : arr)
		cout << i << "  ";
	cout << endl;
}


