class StackArr
{
private:
	int Arr[1000];
	int Size;

public:
	StackArr()
	{
		Size = -1;
	}
	bool Push(int value)
	{
		if (Size >= 999)
			return false;

		Arr[++Size] = value;
		return true;
	}
	bool Pop()
	{
		if (Size < 0)
			return false;
		Size--;
		return true;
	}
	bool isEmpty()
	{
		return Size == -1;
	}

	int Top()
	{
		if (Size >= 0)
			return Arr[Size];
		return -1;

	}
};
