#include<iomanip>
#include<iostream>
#include"Node_JunjieFeng.h"
#include"LinkedList_JunjieFeng.h"
using namespace std;
//constructor
LinkedList::LinkedList()
{
	//the innitialization of fisrt pointer and last pointer are bothr NULL
	this->myHead = NULL;
	this->myTail = NULL;
}//end of constructor
//destructor
LinkedList::~LinkedList()
{}
//add new node at beggining function
void LinkedList::addToStart()
{	
	int No;
	string name;
	cout << "Please enter product number to insert at beginning" << endl;//prompt
	cin >> No;
	cout << "Please enter the name for the product" << endl;
	cin >> name;
	Node *NewNode = new Node(name, No);//creat a pointer point to a new node
	if (myHead == NULL)//if the list is empty
	{
		myHead = NewNode;
		myTail = NewNode;
	}
	else
	{
		NewNode->next = myHead;
		myHead = NewNode;
	}
	printList();
}
//add new node at the end fucntion
void LinkedList::addToEnd()
{
	int No;
	string name;
	cout << "Please enter product number to insert at end" << endl;//prompt
	cin >> No;
	cout << "Please enter the name for the product" << endl;
	cin >> name;
	Node *NewNode = new Node(name, No);//creat a pointer point to a new node
	if (myHead == NULL)//if the list is empty
	{
		myHead = NewNode;
		myTail = NewNode;
	}
	else
	{
		myTail->next = NewNode;
		myTail = NewNode;
	}
	printList();
}
//display the list function
void LinkedList::printList()
{
	if (myHead == NULL)//if the list is empty
		cout << "The list is empty." << endl << endl;
	else
	{
		Node *current = myHead;
		cout << endl << "List" << endl;
		cout << left << setw(10) << "Item No." << setw(10) << "Item Name" << endl;
		while (current != NULL)//while the current pointer still point to an exist node
		{
			cout << setw(10) << current->itemNo << setw(10) << current->itemName << endl;
			current = current->next;
		}
		cout << endl << endl;
	}
}
//remove the first node function
void LinkedList::removeFromStart()
{
	if (myHead == NULL)//if the list is empty
	{
		cout << "Can not remove." << endl;
		printList();
	}
	else
	{
		Node * temp = myHead;
		if (myHead == myTail)//if there is only one node in the list
		{
			myHead = NULL;
			myTail = NULL;
			cout << temp->itemName << " has been romoved from the List." << endl;
			printList();
		}
		else
		{
			myHead = myHead->next;
			cout << temp->itemName << " has been romoved from the List." << endl;
			printList();
		}
		delete temp;
	}
}
//remove the last node funciton
void LinkedList::removeFromEnd()
{
	if (myHead == NULL)//if the list is empty
	{
		cout << "Can not remove." << endl;
		printList();
	}
	else
	{	
		Node * temp = myTail;
		if (myHead == myTail)//if there is only one node in the list
		{
			myHead = NULL;
			myTail = NULL;
			cout << temp->itemName << " has been romoved from the List." << endl;
			printList();
		}
		else
		{
			Node * current = myHead;
			while (current->next != myTail)
				current = current->next;
			myTail = current;
			myTail->next = NULL;
			cout << temp->itemName << " has been romoved from the List." << endl;
			printList();
			//delete current;
		}
		delete temp;
	}
}
//remove node by the item name function
void LinkedList::removeNodeByName()
{
	if (myHead == NULL)//if the list is empty
	{
		cout << "Can not remove." << endl;
		printList();
	}
	else
	{
		string name;
		cout << "Please enter the item name for the product" << endl;//prompt
		cin >> name;
		Node * current = myHead;
		if (myHead->itemName == name)//if the node is the first node
			removeFromStart();
		else if (myTail->itemName == name)//if the node is the last node
			removeFromEnd();
		else
		{
			while (current->next != NULL)
			{
				if (current->next->itemName != name)
					current = current->next;
				else
				{
					current->next = current->next->next;
					cout << name << " has been romoved from the List." << endl;
					printList();
				}
			}
			cout << "Item Not Found" << endl << endl;
			//delete current;
		}
	}
}
//remove node by the item number function
void LinkedList::removeNodeByNo()
{
	if (myHead == NULL)//if the list is empty
	{
		cout << "Can not remove." << endl;
		printList();
	}
	else
	{
		int No;
		cout << "Please enter the item number for the product" << endl;//prompt
		cin >> No;
		Node *temp;
		Node * current = myHead;
		if (myHead->itemNo == No)//if the node is the first node
			removeFromStart();
		else if (myTail->itemNo == No)//if the node is the last node
			removeFromEnd();
		else
		{
			while (current->next != NULL)
			{
				if (current->next->itemNo != No)
					current = current->next;
				else
				{
					temp = current->next;
					current->next = current->next->next;
					cout << temp->next->itemName << " has been romoved from the List." << endl;
					printList();
					delete temp;
				}
			}
			cout << "Item Not Found" << endl << endl;
		}
	}
}
