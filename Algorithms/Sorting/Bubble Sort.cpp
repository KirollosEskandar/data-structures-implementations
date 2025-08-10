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

void Bubble_Sort(int Arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		bool isSwapped = false;
		for (int j = 0; j < n-(i+1); j++)
		{
			if (Arr[j + 1] < Arr[j])
			{
				Swap(Arr[j], Arr[j + 1]);
				isSwapped = true;
			}
		}
		if (!isSwapped)
			return;
	}
}
int main()
{
	int Arr[] = { 3,2,1,0,9 , 1};
	Bubble_Sort(Arr, 6);
	for (int i : Arr)
		cout << i << " ";
	cout << endl;
}

