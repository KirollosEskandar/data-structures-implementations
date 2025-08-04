// HashTable by Linear Probing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

const int Size = 5;
class HashTable
{
	enum EnumState {eEmpty = 0, eRemove = 1, eNotEmpty = 2};
	
	struct Enty
	{
		int value;
		int Key;
		EnumState State;

		Enty()
		{
			value = Key = -1;
			State = eEmpty;
		}
	};
	
	Enty Table[Size];
	int Hash(int Key)
	{
		return Key % Size;
	}
public:
	HashTable() {}
	bool Insert(int key, int value)
	{
		if (Get(key) != INT_MIN)
			return false;

		int index = Hash(key);
		for (int i = 0; i < Size; i++)
		{
			int tryIndex = (index + i) % Size;
			if (Table[tryIndex].State == eNotEmpty)
				continue;
			else
			{
				Table[tryIndex].State = eNotEmpty;
				Table[tryIndex].Key = key;
				Table[tryIndex].value = value;
				return true;;
			}
		}
		return false;
	}
	int Get(int key)
	{
		int index = Hash(key);
		for (int i = 0; i < Size; i++)
		{
			int tryindex = (index + i) % Size;
			if (Table[tryindex].State == eEmpty)
				return INT_MIN;
			else if (Table[tryindex].State == eNotEmpty && Table[tryindex].Key == key)
			{
				return Table[tryindex].value;
			}
		
		}
		return INT_MIN;
	}
	bool  Remove(int Key)
	{
		int index = Hash(Key);

		for (int i = 0; i < Size; i++)
		{
			int tryindex = (index + i) % Size;
			if (Table[tryindex].State == eEmpty)
				return false;
			else if (Table[tryindex].State == eNotEmpty && Table[tryindex].Key == Key)
			{
				Table[tryindex].State = eRemove;
				return true;
			}
		}
		return false;
	}

};


int main()
{
	HashTable ht;
	ht.Insert(9,99);
	ht.Insert(2,22);
	ht.Insert(1,11);
	ht.Remove(9);
	ht.Insert(9, -99);

	cout << ht.Get(9) << endl;
	cout << ht.Get(1) << endl;
	cout << ht.Get(2) << endl;
}

