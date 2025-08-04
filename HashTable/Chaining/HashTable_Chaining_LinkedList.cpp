// HashTable  Chaining using Linked Lists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class HashTable
{
	struct Node
	{
		int Value;
		int Key;

		Node* Next;

		Node(int val, int key)
		{
			this->Key = key;
			this->Value = val;
			Next = NULL;
		}
	};
	static const int Size = 5;
	Node* Table[Size];

	int Hash(int key)
	{
		return key % Size;
	}

public:
	HashTable()
	{
		for (int i = 0; i < Size; i++)
		{
			Table[i] = NULL;
		}
	}
	bool insert(int Value, int Key)
	{
		if (Get(Key) != INT_MIN)
			return false;
		Node* newNode = new Node(Value, Key);
		int Index = Hash(Key);
		if (Table[Index] == NULL)
		{
			Table[Index] = newNode;
		}
		else
		{
			Node* temp = Table[Index];
			while (temp != NULL)
			{
				if (temp->Next == NULL)
				{
					temp->Next = newNode;
					break;
				}
			}
		}
		return true;
	}
	bool Remove(int key)
	{
		int index = Hash(key);
		Node* temp = Table[index];
		if (Table[index]->Key == key)
		{
			Table[index] = temp->Next;
			delete temp;
			return true;
		}
		else
		{
			Node* Pre = NULL;
			while (temp != NULL)
			{
				if (temp->Key == key)
				{
					Pre->Next = temp->Next;
					delete temp;
					return true;
				}
				Pre = temp;
				temp = temp->Next;
			}
		}
		return false;
	}
	int Get(int Key)
	{
		int Index = Hash(Key);
		Node* temp = Table[Index];
		while (temp != NULL)
		{
			if (temp->Key == Key)
				return temp->Value;
			temp = temp->Next;
		}
		return INT_MIN;
	}
};
int main()
{
	HashTable ht;
	ht.insert(11, 1);
	ht.insert(11, 1);
	ht.insert(33, 3);
	ht.insert(22, 2);
	ht.insert(111, 11);
	ht.Remove(1);
	cout << ht.Get(1) << endl;
	cout << ht.Get(11) << endl;
	cout << ht.Get(2) << endl;
	cout << ht.Get(3) << endl;
	cout << ht.Get(4) << endl;
	cout << "Done .." << endl;

}


