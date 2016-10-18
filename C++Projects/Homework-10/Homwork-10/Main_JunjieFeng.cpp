//Name : Junjie Feng
//Course : Programming Financial
//Title : Homework-10
//Submission Date : 11/15/2015

#include<iostream>
#include<iomanip>
#include"Node_JunjieFeng.h"//Node class definition
#include"LinkedList_JunjieFeng.h"//LinkedList class definition
using namespace std;
using std::string;

int main()
{
	int choice = 0;
	bool firsttime = true;
	LinkedList List;//creat a new object of LinkedList
	while (1)
	{
		if (firsttime)
		{
			cout << "Welcome to the shopping list program" << endl;
			firsttime = false;
		}
		//print the menu
		cout << "Please choose an option:" << endl
			<< "1.  Add a new node at the beginning" << endl
			<< "2.  Add a new node at the end" << endl
			<< "3.  Remove the beginning node" << endl
			<< "4.  Remove the end node" << endl
			<< "5.  Remove a node from the list by entering an item number" << endl
			<< "6.  Remove a node from the list by entering an item name" << endl
			<< "7.  Print out the list" << endl
			<< "8.  Quit the program" << endl
			<< "Your option is: ";
		cin >> choice;
		//choose the functions
		switch(choice)
		{
		case 1://Add a new node at the beginning
			List.addToStart();
			break;
		case 2://Add a new node at the end
			List.addToEnd();
			break;
		case 3://Remove the beginning node
			List.removeFromStart();
			break;
		case 4://Remove the end node
			List.removeFromEnd();
			break;
		case 5://Remove a node from the list by entering an item number
			List.removeNodeByNo();
			break;
		case 6://Remove a node from the list by entering an item name
			List.removeNodeByName();
			break;
		case 7://Quit the program
			List.printList();
			break;
		case 8:
			return 0;
		default:
			cout << "You should enter a number between 1 to 8" << endl;
		}
	}
}