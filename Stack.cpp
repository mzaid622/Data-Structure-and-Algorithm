// Implement Stack Using Pointer in c++
// Different Function of Linked List

#include <iostream>
using namespace std;
class node
{
public:
    int value;
    node *next=nullptr;
    node(int v)
    {
        value = v;
    }
};
class Stack
{
public:
    node *top = NULL;
    void push(int num)
    {
        if (top == NULL)
        {
            node* temp = new node(num);
            top=temp;
        }
        else
        {
            node *temp = new node(num);
            temp->next = top;
            top = temp;
        }
    }
    int topvalue()
    {
        if(top==NULL)
        return -1;
        else
        return top->value;
    }
    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack is Empty\n";
        }
        else
        {
            node *temp = top;
            top = temp->next;
            delete (temp);
        }
    }
    void print()
    {
        node *temp = top;
        if (temp == NULL)
        {
            cout << "Stack is Empty:\n";
        }
        else
        {
            while (temp != NULL)
            {
                cout << temp->value << endl;
                temp = temp->next;
            }
        }
    }
};
int main()
{
    Stack obj;
    obj.push(5);
    obj.push(10);
    obj.push(15);
    obj.pop();
    obj.print();
    cout<<obj.topvalue();
}