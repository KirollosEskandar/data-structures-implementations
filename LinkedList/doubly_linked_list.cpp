#include <iostream>;
using namespace std;

class DoublyLinkedList
{
private:
	struct Node
	{
		int Value;
		Node* Next;
		Node* Prev;

		Node(int val)
		{
			Value = val;
			Next = Prev = NULL;
		}
	};

	Node* Head;

public:
	DoublyLinkedList()
	{
		Head = NULL;
	}
	void InsertAtBeginning(int Val)
	{
		Node* NewNode = new Node(Val);

		if (Head != NULL)
			Head->Prev = NewNode;
		NewNode->Next = Head;
		Head = NewNode;
	}
	Node* FindNode(int Val)
	{
		Node* Temp = Head;

		while (Temp != NULL)
		{
			if (Temp->Value == Val)
				return Temp;
			Temp = Temp->Next;
		}
		return NULL;
	}
	void InsertAfter(int AfterVal, int val)
	{
		Node* Found = FindNode(AfterVal);

		if (Found != NULL)
		{
			Node* NewNode = new Node(val);
			NewNode->Prev = Found;
			NewNode->Next = Found->Next;

			Found->Next = NewNode;
			if (NewNode->Next != NULL)
				NewNode->Next->Prev = NewNode;
		}
	}
	void InsertAtEnd(int val)
	{
		Node* NewNode = new Node(val);

		if (Head == NULL)
		{
			Head = NewNode;
		}
		else
		{
			Node* tmp = Head;

			while (tmp->Next != NULL)
			{
				tmp = tmp->Next;
			}
			NewNode->Prev = tmp;
			tmp->Next = NewNode;
		}
	}
	void DeleteNode(int val)
	{
		Node* Found = FindNode(val);

		if (Found != NULL)
		{
			if (Found->Prev == NULL)
			{
				Head = Found->Next;
				if (Head != NULL)
					Head->Prev = NULL;
				delete Found;

			}
			else if (Found->Next == NULL)
			{
				Found->Prev->Next = NULL;
				delete Found;
			}
			else
			{
				Found->Prev->Next = Found->Next;
				Found->Next->Prev = Found->Prev;
				delete Found;
			}
		}
	}
	void DeleteFirstNode()
	{
		if (Head == NULL)
			return;
		else if (Head->Next == NULL)
		{
			delete Head;
			Head = NULL;
		}
		else
		{
			Head = Head->Next;
			delete Head->Prev;
			Head->Prev = NULL;
		}
	}
	void DeleteLasttNode()
	{
		if (Head == NULL)
			return;
		else if (Head->Next == NULL)
		{
			delete Head;
			Head = NULL;
		}
		else
		{
			Node* Temp = Head;
			while (Temp->Next != NULL)
			{
				Temp = Temp->Next;
			}
			Temp->Prev->Next = NULL;
			delete Temp;
		}
	}

	void Display()
	{
		Node* Temp = Head;
		while (Temp != NULL)
		{
			cout << Temp->Value << " ";
			Temp = Temp->Next;
		}
		cout << endl;
	}
};


int main()
{
	DoublyLinkedList list;
	list.InsertAtBeginning(9);
	list.InsertAtBeginning(4);
	list.InsertAtBeginning(2);

	list.Display();


}