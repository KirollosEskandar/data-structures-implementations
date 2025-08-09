// DynamicArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
template<typename t>
class DynamicArray
{
    int size, Capsaty;
    t* arr;

    void ReSize()
    {
        Capsaty *= 2;
        t* newarr = new t[Capsaty];
        for (int i = 0; i < size; i++)
        {
            newarr[i] = arr[i];
        }
        delete[]arr;
        arr = newarr;
    }

public:
    DynamicArray()
    {
        size = 0;
        Capsaty = 5;
        arr = new t[Capsaty];
    }

    bool Push_back(int value)
    {
        if (size == Capsaty)
            ReSize();
        arr[size++] = value;
        return true;
    }
    bool Pop_back()
    {
        if (size <= 0)
            return false;
        size--;
    }
    int Get(int index)
    {
        if (size <= 0 || index >= size)
            return -1;
        return arr[index];
    }
    void Set(int index, t value)
    {
        if (size <= 0 || index >= size)
            return;
        arr[index] = value;

    }
    void Print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
   }
};
int main()
{
    DynamicArray<int> arr;
    arr.Push_back(1);
    arr.Push_back(2);
    arr.Push_back(3);
    arr.Push_back(4);
    arr.Push_back(5);
    arr.Push_back(5);
    arr.Push_back(5);
    arr.Print();
    arr.Pop_back();
    arr.Print();
    arr.Set(3, 66);
    arr.Print();
    cout << arr.Get(2);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

