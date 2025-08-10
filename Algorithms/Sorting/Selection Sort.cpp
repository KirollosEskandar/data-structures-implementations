// ConsoleApplication58.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void Swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

void Selection_Sort(int Arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int MinIndex = i;
		for (int j = i + 1; j < n; j++)
		{
			if (Arr[j] < Arr[MinIndex])
				MinIndex = j;
		}
		if (i != MinIndex)
			Swap(Arr[i], Arr[MinIndex]);
	}
}
int main()
{
	int Arr[] = { 3,2,1,0,9 , 1};
	Selection_Sort(Arr, 6);
	for (int i : Arr)
		cout << i << " ";
	cout << endl;
}

