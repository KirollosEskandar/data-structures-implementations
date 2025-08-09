class QueueLinkedList
{
private:
	struct Node
	{
		int Value;
		Node* Next;

		Node(int value)
		{
			Value = value;
			Next = NULL;
		}
	};

	Node* Front, *Back;

public:
	QueueLinkedList()
	{
		Front = Back = NULL;
	}
	bool IsEmpty()
	{
		return Front == NULL;
	}
	bool Enqueue(int val)
	{
		Node* NewNode = new Node(val);
		if (IsEmpty())
		{
			Front = Back = NewNode;
		}
		else
		{
			Back->Next = NewNode;
			Back = Back->Next;
		}
		return true;
	}
	bool Dequeue()
	{
		if (IsEmpty())
			return false;
		else if (Front == Back)
		{
			delete Front;
			Front = Back = NULL;
			return true;
		}
		Node* Temp = Front;
		Front = Front->Next;
		delete Temp;
	}
	int GetFront()
	{
		if (IsEmpty())
			return false;
		else return Front->Value;
	}

	~QueueLinkedList()
	{
		while (!IsEmpty())
		{
			Dequeue();
		}
	}
};

