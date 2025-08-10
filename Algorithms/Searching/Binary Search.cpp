// ConsoleApplication58.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
// Binary Search
int Binary_Search(int Arr[], int n, int Target)
{
	int left = 0, right = n-1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (Arr[mid] == Target)
			return mid;
		if (Target > Arr[mid])
			left = mid + 1;
		else
			right = mid - 1;
	}

	return -1;
}

int Binary_Search_(int Arr[], int left, int right, int Target)
{
	if (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (Arr[mid] == Target)
			return mid;
		else if (Target > Arr[mid])
			return Binary_Search_(Arr, mid + 1, right, Target);
		else
			return Binary_Search_(Arr, left, mid-1, Target);

	}
	return -1;
}

int main()
{
	int Arr[] = { 3,4,5,6,9,11};
	cout << Binary_Search(Arr, 6, 9) << endl;
	cout << Binary_Search_(Arr,0, 6, 9) << endl;
	cout << endl;
}

