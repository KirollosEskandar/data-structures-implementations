class QueueArrayNormail
{
	int *Arr;
	int Start, End, Size;

public:
	QueueArrayNormail(int Size)
	{
		this->Size = Size;
		Arr = new int[Size];
		Start = End = 0;
	}

	bool iSFull()
	{
		return End == Size;
	}
	bool isEmpty()
	{
		return Start == End;
	}
	int GetSize()
	{
		return End - Start;
	}
	bool Enqueue(int val)
	{
		if (iSFull())
			return false;
		else
		{
			Arr[End++] = val;
		}
		return true;
	}
	bool Dequeue()
	{
		if (isEmpty())
			return false;
		Start++;
		return true;
	}
	int GetFront()
	{
		if (isEmpty())
		{
			cout << "Empty.." << endl;
			return -1;
		}
		else
			return Arr[Start];
	}
};

