#include <iostream>;

using namespace std;



class SinglyLinkedList
{
private:
	struct Node
	{
		int Value;
		Node* Next;
	};
	Node* Head = NULL;
public:
	void InsertAtBeginning(int Val)
	{
		Node* NewNode = new Node;
		NewNode->Value = Val;
		NewNode->Next = Head;
		Head = NewNode;
	}

	int FindIndex(int Val)
	{
		Node* Temp = Head;
		int index = 0;
		while (Temp != NULL)
		{
			if (Temp->Value == Val)
				return index;
			Temp = Temp->Next;
			index++;

		}
		return -1;
	}
	Node* Find(int Val)
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
	bool InsertAfter(int AfterVal, int Val)
	{
		Node* FoundNode = Find(AfterVal);
		if (FoundNode != NULL)
		{
			Node* NewNode = new Node(Val);
			NewNode->Next = FoundNode->Next;
			FoundNode->Next = NewNode;
			return true;
		}
		return false;

	}
	void Print()
	{
		Node* Temp = Head;

		while (Temp != NULL)
		{
			cout << Temp->Value << "  ";
			Temp = Temp->Next;
		}
		cout << endl;
	}
	void InsertAtEnd(int Val)
	{
		Node* NewNode = new Node;
		NewNode->Next = NULL;
		NewNode->Value = Val;

		if (Head == NULL)
		{
			Head = NewNode;
		}
		else
		{
			Node* Temp = Head;
			while (Temp->Next != NULL)
			{
				Temp = Temp->Next;
			}
			Temp->Next = NewNode;
		}
	}
	void DeleteNode(int Val)
	{
		if (Head == NULL)
			return;
		else if (Head->Value == Val)
		{
			Node* temp = Head;
			Head = Head->Next;
			delete temp;
		}
		else
		{
			Node* Current = Head, * Pre;
			while (Current != NUL)
			{
				Pre = Current;
				Current = Current->Next;
				if (Current->Value == Val)
				{
					Pre->Next = Current->Next;
					delete Current;
					return;
				}
			}
		}
	}
	void DeleteFirstNode()
	{
		if (Head == NULL)
			return;
		else
		{
			Node* temp = Head;
			Head = Head->Next;
			delete temp;
		}
	}
	void DeleteLastNode()
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
			Node* temp = Head;
			while (temp->Next->Next != NULL)
				temp = temp->Next;
			Node* del = temp->Next;
			temp->Next = NULL;
			delete del;
		}

	}

};


int main()
{
	SinglyLinkedList List;
	List.InsertAtEnd(88);
	List.InsertAtEnd(2);
	List.Print();

	List.DeleteFirstNode();
	List.Print();
}