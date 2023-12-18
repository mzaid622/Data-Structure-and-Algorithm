// Implement Linked List Using Pointer in c++
// Different Function of Linked List


#include<iostream>
using namespace std;

// First We Make Class that have 2 variable
class node
{
public:
	int num;
	node* next;
	node(int n)
	{
		num = n;
	}

};

//Second Class for Function
class LinkList
{
public:
	node* head = NULL;
	void insertAtStart(int num)
	{
		if (head == NULL)
		{
			head = new node(num);
		}
		else
		{
			node* temp = new node(num);
			temp->next = head;
			head = temp;
		}
	}
	void insertAtEnd(int num)
	{
		node* temp = head;
		if (temp == NULL)
		{
			head = new node(num);
		}
		else
		{
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			node* temp2 = new node(num);
			temp->next = temp2;
		}
	}
	void deleteList(int index)
	{
		if (index == 0)
		{
			node* current = head;
			head = head->next;
			delete(current);
		}
		else
		{
			node* current = head;
			node* prev = head;
			for (int i = 0; i < index; i++)
			{
				prev = current;
				current = current->next;
			}
			prev->next = current->next;
			delete(current);
		}
	}
	void addAtIndex(int num, int index)
	{
		node* temp = new node(num);
		if (index == 0)
		{
			temp->next = head;
			head = temp;
		}
		else
		{
			node* fast = head;
			node* last = head;
			for (int i = 0; i < index; i++)
			{
				last = fast;
				fast = last->next;
			}
			last->next=temp;
			temp->next = fast;
		}
	}
	bool search(int value)
	{
		node* temp = head;
		while (temp != NULL)
		{
			if (temp->num == value)
			{
				return true;
			}
			temp = temp->next;
		}
		return false;
	}
	void print()
	{
		node* temp = head;
		if (temp == NULL)
		{
			cout << "List is Empty\n";
		}
		else
		{
			while (temp != NULL)
			{
				cout << temp->num << endl;
				temp = temp->next;
			}
		}
	}
};
int main()
{
	LinkList obj;
	obj.insertAtStart(20);
	obj.insertAtStart(30);
	obj.insertAtStart(40);
	obj.print();
	cout << "=====================================\n";
	obj.insertAtEnd(50);
	obj.insertAtEnd(60);
	obj.insertAtEnd(70);
	obj.print();
	cout << "=====================================\n";
	obj.deleteList(4);
	obj.print();
	cout << "=====================================\n";
	obj.addAtIndex(10, 3);
	obj.print();
	cout << "=====================================\n";
	int num;
	cout << "Enter number that you want in List: ";
	cin >> num;
	int is =obj.search(num);
	if (is == 1)
		cout << "Number is found in Linked List\n";
	else
		cout << "Number is not found in Linked List\n";

}