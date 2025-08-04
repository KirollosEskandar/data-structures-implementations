class CircularQueue
{
private:
	int Front, Back, Size, Cap;
	int* Arr;

public:
	CircularQueue(int Cap)
	{
		this->Cap = Cap;
		Size = 0;
		Front = Back = -1;
		Arr = new int[Cap];
	}
	~CircularQueue()
	{
		delete[]Arr;
	}

	bool isEmpty()
	{
		return Size == 0;
	}
	bool isFull()
	{
		return Size == Cap;
	}

	bool EnQueue(int val)
	{
		if (isFull())
			return false;
		else if (isEmpty())
		{
			Back = Front = (Back + 1) % Cap;
		}
		else 
			Back = (Back + 1) % Cap;;
		Arr[Back] = val;
		Size++;
	}
	bool Dequeue()
	{
		if (isEmpty())
			return false;
		else if (Front == Back)
		{
			Front = Back = -1;
			Size = 0;
			return true;
		}
		Front = (Front + 1) % Cap;
		Size--;
		return true;
	}

	void GetFront()
	{
		if (isEmpty())
			cout << "Empty.." << endl;
		else
		{
			cout << Arr[Front] << " ";
		}
	}
};

