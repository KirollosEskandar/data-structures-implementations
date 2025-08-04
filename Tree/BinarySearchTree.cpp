// BinarySearchTree C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct Node
{
	int value;
	Node* Left, * Right;
	Node(int value)
	{
		this->value = value;
		Left = Right = NULL;
	}
};

class BinarySearchTree
{
	Node* Root;

	void AddHelper(Node* Temp, int val)
	{
		if (val < Temp->value)
		{
			if (Temp->Left == NULL)
			{
				Temp->Left = new Node(val);
			}
			else
			{
				AddHelper(Temp->Left, val);
			}
		}
		else
		{
			if (Temp->Right == NULL)
			{
				Temp->Right = new Node(val);
			}
			else
			{
				AddHelper(Temp->Right, val);
			}
		}
	}

	void InOrder(Node* Temp)
	{
		if (Temp != NULL)
		{
			InOrder(Temp->Left);
			cout << Temp->value << "  ";
			InOrder(Temp->Right);
		}
	}

	Node* FindMaxNode(Node* nRoot)
	{
		while (nRoot->Right != NULL)
		{
			nRoot = nRoot->Right;
		}
		return nRoot;
	}

	Node* Remove(Node* nRoot, int DelValue)
	{
		if (DelValue > nRoot->value)
		{
			nRoot->Right = Remove(nRoot->Right, DelValue);
		}
		if (DelValue < nRoot->value)
		{
			nRoot->Left = Remove(nRoot->Left, DelValue);
		}
		else
		{
			if (nRoot->Left == NULL)
			{
				Node* Temp = nRoot->Right;
				delete nRoot;
				return Temp;
			}
			if (nRoot->Right == NULL)
			{
				Node* Temp = nRoot->Left;
				delete nRoot;
				return Temp;
			}
			else
			{
				Node* MaxNode = FindMaxNode(nRoot->Left);
				nRoot->value = MaxNode->value;
				nRoot->Left = Remove(nRoot->Left, MaxNode->value);

			}
		}

		return nRoot;
	}

	Node* search(Node* temp, int val)
	{
		if (temp == NULL)
			return NULL;
		if (temp->value == val)
			return temp;
		if (val > temp->value)
			return search(temp->Right, val);
		if (val < temp->value)
			return search(temp->Left, val);
		return NULL;
	}


public:
	BinarySearchTree(int val)
	{
		Root = new Node(val);
	}

	void Add(int value)
	{
		if (Root == NULL)
		{
			Root = new Node(value);
		}
		else
		{
			AddHelper(Root, value);
		}
	}
	void Print()
	{
		InOrder(Root);
	}

	bool SerarchValue(int Target)
	{
		Node* Temp = Root;

		while (Temp != NULL)
		{
			if (Temp->value == Target)
				return true;
			else if (Target > Temp->value)
				Temp = Temp->Right;
			else
				Temp = Temp->Left;
		}
		return false;
	}
	bool Found(int val)
	{
		return search(Root, val) != NULL;
	}

	bool Search(int Target)
	{
		Node* Temp = Root;
		if (Temp == NULL)
			return false;

		while (Temp != NULL)
		{
			if (Temp->value == Target)
				return true;
			else if (Target < Temp->value)
				Temp = Temp->Left;
			else if (Target > Temp->value)
				Temp = Temp->Right;
		}
		return false;
	}
	void Delete(int val)
	{
		Root = Remove(Root, val);
	}
};
int main()
{
	BinarySearchTree BST(50);
	BST.Add(60);
	BST.Add(40);
	BST.Add(2);

	BST.Print();

	cout << endl << BST.Found(2) << endl;
}
