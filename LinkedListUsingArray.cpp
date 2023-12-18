// Implement Linked List Using Array in c++
// Different Function of Linked List

#include <iostream>
using namespace std;

class array1
{
public:
    int* arr;
    int size;
    int arraysize;
    int currentindex;
    array1(int s) : size(0), arraysize(s),currentindex(0)
    {
        arr = new int[arraysize];
    }
    ~array1()
    {
        delete[] arr;
    }
    void InsertatStart(int num)
    {
        if (size >= arraysize)
        {
            arraysize *= 2;
            int* newarray = new int[arraysize];
            for (int i = size - 1; i >= 0; i--)
            {
                newarray[i + 1] = arr[i];
            }
            delete[] arr;
            arr = newarray;
        }
        else
        {
            for (int i = size - 1; i >= 0; i--)
            {
                arr[i + 1] = arr[i];
            }
        }

        arr[0] = num;
        size++;
    }
    void InsertatEnd(int num)
    {
        if (size >= arraysize)
        {
            arraysize *= 2;
            int* newarray = new int[arraysize];
            for (int i = 0; i < size; i++)
            {
                newarray[i + 1] = arr[i];
            }
            delete[]arr;
            arr = newarray;
        }
        arr[size] = num;
        size++;
    }
    void removeatindex(int index)
    {
        if (index >= 0 && index < size)
        {
            for (int i = index; i < size - 1; i++)
            {
                arr[i] = arr[i - 1];
            }
            size--;
        }
    }
    void update(int index, int newvalue)
    {
        if (index >= 0 && index < size)
        {
            arr[index] = newvalue;
        }
    }
    bool search(int num)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] = num)
            {
                return true;
            }
        }
        return false;
    }
    void back()
    {
        if (currentindex > 0)
        {
            currentindex--;
        }
    }
    void front()
    {
        if (currentindex < size-1)
        {
            currentindex++;
        }
    }
    void indexat()
    {
        cout << "Current Index: " << currentindex << endl;
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << endl;
        }
    }
    int getsize()
    {
        return size+1;
    }
};

int main()
{
    array1 obj(4);
    obj.InsertatStart(4);
    obj.InsertatEnd(8);
    obj.InsertatEnd(12);
    obj.InsertatStart(16);
    cout << "Original Array:\n";
    obj.print();

    obj.removeatindex(3);
    cout << "After Remove element in array:\n";
    obj.print();

    obj.update(1, 0);
    cout << "After Update element:\n";
    obj.print();
    int value;
    cout << "Enter value that find in array:";
    cin >> value;
    int index = obj.search(value);
    if (index == 1)
    {
        cout << "\nValue is found in array:"<<value<<endl;
    }
    else
    {
        cout << "\nValue is not found in array:\n";
    }
    
    cout << "Current Size of array:" << obj.getsize();
    cout << endl << "-----------------------------------------------\n";
    obj.back();
    obj.indexat();
    obj.front();
    obj.indexat();
}
