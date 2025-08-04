// Deque.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Deque
{
private:
	struct Node
	{
		int value;
		Node* Next;
		Node* Pre;
		Node(int val)
		{
			value = val;
			Next = Pre = NULL;
		}
	};
	Node* Front, * Back;

public:
	Deque()
	{
		Front = Back = NULL;
	}
	~Deque()
	{

	}

	bool InsertFront(int val)
	{
		Node* NewNode = new Node(val);
		if (!isEmpty())
		{
			NewNode->Next = Front;
			Front->Pre = NewNode;
			Front = NewNode;

		}
		else
		{
			Front = Back = NewNode;
		}
		return true;
	}
	bool InsertBack(int val)
	{
		if (isEmpty())
		{
			InsertFront(val);
		}
		else
		{
			Node* newNode = new Node(val);
			newNode->Pre = Back;
			Back->Next = newNode;
			Back = Back->Next;
		}
		return true;
	}

	bool RemoveFront()
	{
		if (isEmpty())
			return false;
		else if(Front->Next == NULL)
		{
			delete Front;
			Back = Front = NULL;
			return true;
		}
		Node* temp = Front;
		Front = Front->Next;
		Front->Pre = NULL;
		delete temp;
		return true;
	}
	bool RemoveBack()
	{
		if (isEmpty())
			return false;
		else if (Front == Back)
		{
			delete Front;
			Front = Back = NULL;
		}
		else
		{
			Node* temp = Back;
			Back = Back->Pre;
			Back->Next = NULL;
			delete temp;
		}

		return true;
	}

	bool isEmpty()
	{
		return Front == NULL;
	}

	int GetFront()
	{
		if (isEmpty())
			return INT64_MIN;
		return Front->value;
	}
	int GetBack()
	{
		if (isEmpty())
			return INT64_MIN;
		return Back->value;
	}
};


int main()
{
	Deque deque;
	deque.InsertFront(0);
	deque.InsertFront(4);
	deque.InsertFront(4);

	while (!deque.isEmpty())
	{
		cout << deque.GetBack() << " ";
		deque.RemoveBack();
	}
}



