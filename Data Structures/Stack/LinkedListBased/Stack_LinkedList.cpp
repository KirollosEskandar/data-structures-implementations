class StackLinkedList
{
private:
	struct Node
	{
		int Value;
		Node* Next;
		Node(int vale, Node *head)
		{
			Value = vale;
			Next = head;
		}

	};
	Node* Head;

public:
	StackLinkedList()
	{
		Head = NULL;
	}
	bool Push(int value)
	{
		Node* newNode = new Node(value, Head);
		Head = newNode;
		return true;
	}
	bool Pop()
	{
		Node* Temp = Head;
		Head = Head->Next;
		delete Temp;
		return true;
	}
	bool isEmpty()
	{
		return Head == NULL;
	}

	int Top()
	{
		if (!isEmpty())
			return Head->Value;
		return -1;
	}
};

