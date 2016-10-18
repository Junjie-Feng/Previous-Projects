//Name : Junjie Feng
//Course : Programming Financial
//Title : Homework-6
//Date of submission : 10/14/2015

#include<iostream>
#include<iomanip>
#include"Booklist_Feng.h"//Booklist class in header file

using namespace std;

int main()
{
	Booklist book_list(100);
	int choice = 10;
	while (1)//in order to come back to the menu after finishing one of the function
	{
		if (choice == 10)
			cout << "Welcome to the Book list program." << endl;
		//display the menu
		cout << "\nWhat would you like to do?" << endl
			<< "	1: add an element to end of list" << endl
			<< "	2: add an element at a location" << endl
			<< "	3: find an element by ISBN number (linear search)" << endl
			<< "	4: find an element by ISBN number (binary search)" << endl
			<< "	5: delete an element at position" << endl
			<< "	6: delete an element by ISBN number" << endl
			<< "	7: sort the list (using selection sort)" << endl
			<< "	8: sort the list (using bubble sort)" << endl
			<< "	9: print the list" << endl
			<< "	0: Quit" << endl;
		cout << "Enter your choice : " << endl;//prompt
		cin >> choice;
		switch (choice)//in order to choose function
		{
		case 1://Insert new element at the end of the list
			book_list.insert();
			book_list.print();
			break;
		case 2://Insert new element at a certain position  
			book_list.isert_at();
			book_list.print();
			break;
		case 3://Find an element (with its ISBN number and list its position) using linear search
			book_list.find_linear();
			break;
		case 4://Find an element (with its ISBN number and list its position) of a sorted list using binary search
			book_list.find_binary();
			break;
		case 5://Delete an element that is at a certain position
			book_list.delete_item_position();
			book_list.print();
			break;
		case 6://Delete an element by using its ISBN number
			book_list.delete_item_isbn();
			book_list.print();
			break;
		case 7://Sort the list by the ISBN numbers (using selection sort)
			book_list.sort_list_selection();
			book_list.print();
			break;
		case 8://Sort the list by the ISBN numbers (using bubble sort)
			book_list.sort_list_bubble();
			book_list.print();
			break;
		case 9://Print out the list
			book_list.print();
			break;
		case 0://exit the program
			cout << "Thanks for your time!" << endl;
			return 0;//indicate the successful termination of the program
			break;
		default:
			cout << "You need to enter a digit from 0 to 9." << endl;
		}
	}
}//end main