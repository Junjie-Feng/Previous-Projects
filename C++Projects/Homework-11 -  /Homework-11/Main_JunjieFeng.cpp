//Name : Junjie Feng
//Course : Programming Financial
//Title : Homework-11
//Date of submission : 11/21/2015

#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include "BookList_JunjieFeng.h"//Booklist class in header file

//#include "BookList_JunjieFeng.cpp"
//using TEMPLATE need to include .cpp file in the main function
//or instead of including the .cpp file, I can define all the class's fucntion in the .h file

using namespace std;

int main()
{
	Booklist<string> list;
	//creat a new object of class Booklist.
	//the type of this object is string
	int choice = 10;
	bool first_time = true;
	do//in order to come back to the menu after finishing one of the function
	{
		if (first_time)
		{
			cout << "Welcome to the book list program for book names." << endl;
			first_time = false;
		}
		//display the menu
		cout << "\nWhat would you like to do?" << endl
			<< "	1: add an element to end of list" << endl
			<< "	2: add an element at a location" << endl
			<< "	3: find an element by book name (linear search)" << endl
			<< "	4: find an element by book name (binary search)" << endl
			<< "	5: delete an element at position" << endl
			<< "	6: delete an element by book number" << endl
			<< "	7: sort the list (using selection sort)" << endl
			<< "	8: sort the list (using bubble sort)" << endl
			<< "	9: print the list" << endl
			<< "	0: exit" << endl;
		cout << "Enter your choice : ";//prompt
		cin >> choice;
		switch (choice)//in order to choose function
		{
		case 1://Insert new element at the end of the list
			list.insert();
			list.print();
			break;
		case 2://Insert new element at a certain position  
			list.isert_at();
			list.print();
			break;
		case 3://Find an element (with its name and list its position) using linear search
			list.find_linear();
			break;
		case 4://Find an element (with its name and list its position) of a sorted list using binary search
			list.find_binary();
			break;
		case 5://Delete an element at a certain position
			list.delete_item_position();
			list.print();
			break;
		case 6://Delete an element by book name
			list.delete_item_name();
			list.print();
			break;
		case 7://Sort the books by alphabetical order(using selection sort)
			list.sort_list_selection();
			list.print();
			break;
		case 8://Sort the books by alphabetical order(using bubble sort)
			list.sort_list_bubble();
			list.print();
			break;
		case 9://Print out the list
			list.print();
			break;
		case 0://exit the program
			cout << "Thanks for your time!" << endl;
			//indicate the successful termination of the program
			break;
		default:
			cout << "You need to enter a digit from 0 to 9." << endl;
		}
	} while (choice);
	return 0;
}//end main