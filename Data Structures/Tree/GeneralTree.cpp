// General Tree C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
struct Node
{
	int Value;
	vector<Node*> Childreen;
	Node(int val)
	{
		this->Value = val;
	}
};

class Tree
{
	Node* root;

public:
	Tree(int val)
	{
		root = new Node(val);
	}

	Node* GetRoot()
	{
		return root;
	}

	void AddChild(Node* Parent, int value)
	{
		Node* child = new Node(value);
		Parent->Childreen.push_back(child);
	}

	void print(Node* node = nullptr, int depth = 0) {
		if (node == nullptr) node = root;

		for (int i = 0; i < depth; i++) cout << "--";
		cout << node->Value << endl;

		for (Node* child : node->Childreen) {
			print(child, depth + 1);
		}
	}
	Node* Find(int Target, Node* N = NULL)
	{
		if (N == NULL)
			N = root;
		if (N->Value == Target)
			return N;

		for (Node* Temp : N->Childreen)
		{
			Node* Found = Find(Target, Temp);

			if (Found != NULL)
				return Temp;
		}
		return NULL;
	}
};
int main()
{
	Tree MyTree(0);

	Node* NodeOne = new Node(1);
	Node* NodeTwo = new Node(2);

	Node* Root = MyTree.GetRoot();
	Root->Childreen.push_back(NodeOne);
	Root->Childreen.push_back(NodeTwo);

	MyTree.AddChild(NodeOne, 11);
	MyTree.AddChild(NodeOne, 111);
	MyTree.AddChild(NodeTwo, 22);
	MyTree.AddChild(NodeTwo, 222);
	//MyTree.print();

	Node* Found = MyTree.Find(11);
	cout << "Found : " << Found->Value << endl;
}

