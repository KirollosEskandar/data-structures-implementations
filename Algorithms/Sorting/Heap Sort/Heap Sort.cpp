// Heap Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
void Heapfiy(vector<int> &Arr,int index, int n)
{
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	int largest = index;

	if (left <n && Arr[left] > Arr[largest])
		largest = left;
	if (right <n && Arr[right] > Arr[largest])
		largest = right;

	if (index != largest)
	{
		Swap(Arr[index], Arr[largest]);
		Heapfiy(Arr, largest, n);
	}
}
void BuilHeap(vector<int>& Arr, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		Heapfiy(Arr, i, n);
	}
}
void SortHeap(vector<int>& Arr, int n)
{
	BuilHeap(Arr, n);
	for (int i = n - 1; i > 0; i--)
	{
		Swap(Arr[i], Arr[0]);
		Heapfiy(Arr, 0, i);
	}
}




int main()
{
	vector<int> Arr = { 3,2,1,4,0,8,2,1,3,4,5 };
	SortHeap(Arr, Arr.size());
	for (int i : Arr)
		cout << i << "  ";
	cout << endl;
}
