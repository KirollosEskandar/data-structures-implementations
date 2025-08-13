// Counting Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
vector<int> CountingSort(vector<int>& Arr, int MaxValue)
{
	vector<int> PreCount(MaxValue + 1, 0);

	// Count The Number
	for (int i : Arr)
	{
		PreCount[i]++;
	}

	// Make Pre Sum
	for (int i = 1; i < PreCount.size(); i++)
	{
		PreCount[i] += PreCount[i - 1];
	}


	vector<int> OutPut(Arr.size());
	for (int i = Arr.size() - 1; i >= 0; i--)
	{

		PreCount[Arr[i]]--;
		int indexV = PreCount[Arr[i]];
		OutPut[indexV] = Arr[i];
	}
	return OutPut;

}
int main()
{
	vector<int> Arr = { 3,2,5,1,1,2,2,9 };
	int MaxValue = 9;
	Arr = CountingSort(Arr, MaxValue);
	for (int i : Arr)
		cout << i << " ";
	cout << endl;
}

