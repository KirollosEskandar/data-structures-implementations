// ConsoleApplication55.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;


class MyHashSet {
    static const int Size = 1000;

    struct Node
    {
        int Key;
        Node* next;
        Node(int key)
        {
            this->Key = key;
            this->next = NULL;
        }
    };
    Node *Table[Size];
    int hash(int key)
    {
        return key % Size;
    }
public:
    MyHashSet() {
        for (int i = 0; i < Size; i++)
            Table[i] = NULL;
    }

    void add(int key) {
        int index = hash(key);
        if (Table[index] == NULL)
        {
            cout << key << endl;
            Table[index] = new Node(key);
            cout << "add : " << Table[index]->Key << endl;

            return;
        }
        Node* Temp = Table[index];
        while (Temp)
        {
            if (Temp->Key == key)
                return;
            else if (!Temp->next)
                break;
            Temp = Temp->next;
        }
        Temp->next = new Node(key);
    }

    void remove(int key) {
        int index = hash(key);
        Node* temp = Table[index];
        if (!temp)
            return;
        if (Table[index]->Key == key)
        {
            Table[index] = Table[index]->next;
            delete temp;
            return;
        }
        else
        {
            Node* Pre = temp;
            temp = temp->next;
            while (temp)
            {
                if (temp->Key == key)
                {
                    Pre->next = temp->next;
                    delete temp;
                    return;
                }
                Pre = temp;
                temp = temp->next;
            }
        }
    }

    bool contains(int key) {
        int index = hash(key);
        Node* Temp = Table[index];
        while (Temp)
        {
            cout << "contains : " << Temp->Key << endl;
            if (Temp->Key == key)
                return true;
            Temp = Temp->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */


int main()
{
    MyHashSet hashSet;
    hashSet.add(8);
    hashSet.add(2);
    hashSet.add(1);
    hashSet.add(8);
    hashSet.remove(8);
    cout << hashSet.contains(8) << endl;

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
