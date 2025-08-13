// Quick Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

void Swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

int partition(vector<int>& Arr, int start, int end)
{
	int Poivt = Arr[end];
	int index = start - 1;
	// 3,2,1,9,8,0,2
	// 1,0,3,9,8,2,2
	// 1,0,2,9,8,2,2
	for (int i = start; i < end; i++)
	{
		if (Arr[i] <= Poivt)
		{
			index++;
			Swap(Arr[i], Arr[index]);
		}
	}
	Swap(Arr[++index], Arr[end]);
	return index;
}
void QuickSort(vector<int>& Arr, int start, int end)
{
	if (start < end)
	{
		int povit = partition(Arr, start, end);
		QuickSort(Arr, start, povit-1);
		QuickSort(Arr, povit+1, end);
	}
}
int main()
{
	vector<int> Arr = { 3,2,1,9,8,0,2 };
	QuickSort(Arr, 0, Arr.size()-1);

	for (int i : Arr)
		cout << i << " ";
	cout << endl;
}


