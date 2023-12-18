// Implement Doubly Linked List Using Pointer in c++
// Different Function of Linked List

#include <iostream>
using namespace std;
class node
{
public:
    int value;
    node *next = nullptr;
    node *prev = nullptr;
    node(int v)
    {
        value = v;
    }
};
class DoublyLinkedList
{
public:
    node *head = nullptr;
    node *tail = nullptr;

    void insertathead(int num)
    {
        node* temp=new node(num);
        if(head==NULL)
        {
            head=tail=temp;
        }
        else
        {
            temp->next=head;
            head->prev=temp;
            head=temp;
        }
    }

    void insertattail(int num)
    {
        node* temp=new node(num);
        if(tail==NULL)
        {
            head=tail=temp;
        }
        else
        {
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
        }
    }

    void insertatindex(int index,int num)
    {
        node* fast=head;
        node* slow=head;
        for(int i=0;i<index;i++)
        {
            slow=fast;
            fast=fast->next;
        }
        node* temp=new node(num);
        slow->next=temp;
        temp->next=fast;
    }

    void deleteindex(int index)
    {
        if(index==0)
        {
            node* temp=head;
            head=temp->next;
            head->prev=NULL;
            delete(temp);
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

    void deletefromhead()
    {
        node* current=head;
        head=current->next;
        head->prev=NULL;
        delete(current);
    }
     void deletefromtail()
    {
        node* current=tail;
        tail=current->prev;
        tail->next=NULL;
        delete(current);
    }

    void printhead()
    {
        node* temp=head;
        if(temp==NULL)
        {
            cout<<"List is Empty\n";
        }
        else
        {
            while(temp!=NULL)
            {
                cout<<temp->value<<endl;
                temp=temp->next;
            }
        }
    }
    void printend()
    {
        node* temp=tail;
        if(temp==NULL)
        {
            cout<<"List is Empty\n";
        }
        else
        {
            while(temp!=NULL)
            {
                cout<<temp->value<<endl;
                temp=temp->prev;
            }
        }
    }
};

int main()
{
    DoublyLinkedList obj;
    obj.insertattail(5);
    obj.insertattail(10);
    obj.insertattail(15);
    obj.insertatindex(2,100);
    obj.printhead();
}