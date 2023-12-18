// Implement Circular Linked List Using Pointer in c++
// Different Function of Linked List

#include <iostream>
using namespace std;
class node
{
public:
    int value;
    node *next = nullptr;
    node(int v)
    {
        value = v;
    }
};
class CircularLinkedList
{
    public:
    node* head=NULL;

    void insertstart(int num)
    {
        node* temp=new node(num);
        if(head==NULL)
        {
            head=temp;
            temp->next=head;
        }
        else
        {
            node* current=head;
            while(current->next!=head)
            {
                current=current->next;
            }
            current->next=temp;
            temp->next=head;
            head=temp;
        }
    }
    void insertend(int num)
    {
        node* temp=head;
        if(temp==NULL)
        {
            head=new node(num);
            head->next=head;
        }
        else{
            while(temp->next!=head)
            {
                temp=temp->next;
            }
            node* current=new node(num);
            temp->next=current;
            current->next=head;

        }
    }
    void deleteindex(int index)
    {
        if(index==0)
        {
            node * current=head;
            head=head->next;
            delete(current);
        }
        else
        {
            node* fast=head;
            node* slow=head;
            for(int i=0;i<index;i++)
            {
                slow=fast;
                fast=fast->next;
            }
            slow->next=fast->next;
            delete(fast);
        }
    }
    void print()
    {
        node* temp=head;
        if(temp==NULL)
        {
            cout<<"List is Empty\n";
        }
        else
        {
            do{
                cout<<temp->value<<endl;
                temp=temp->next;
            }while(temp!=head);
        }
    }
};

int main()
{
    CircularLinkedList obj;
    obj.insertend(51);
    obj.insertend(52);
    obj.insertend(53);
    obj.print();
}