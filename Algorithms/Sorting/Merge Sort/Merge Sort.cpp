// Merge Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> Merge(vector<int> &left , vector<int> &rihgt)
{
	int i = 0, j = 0;
	vector<int> res;
	while (i < left.size() && j < rihgt.size())
	{
		if (left[i] < rihgt[j])
			res.push_back(left[i++]);
		else
			res.push_back(rihgt[j++]);
	}
	while(i < left.size())
		res.push_back(left[i++]);
	while (j < rihgt.size())
		res.push_back(rihgt[j++]);
	return res;
}
vector<int> MergeSort(vector<int> Arr)
{
	if (Arr.size() <= 1)
		return Arr;

	int mid = Arr.size()/2;
	vector<int> left(Arr.begin(), Arr.begin() + mid);
	vector<int> right(Arr.begin()+mid, Arr.end());

	left = MergeSort(left);
	right = MergeSort(right);

	return Merge(left, right);
}
int main()
{
	vector<int> Arr = { 4,32,1,4,9,3,0 };
	Arr = MergeSort(Arr);
	for (int i : Arr)
		cout << i << "  ";
	cout << endl;
}
