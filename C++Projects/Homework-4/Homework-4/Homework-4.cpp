// Name : Junjie Feng
// Course : 16:332:503:01 , Programming Financial
// Title : Homework 4 
//Date of Submission: 10/04/2015

#include<iostream>
#include <iomanip>
using namespace std;

void insert(int[], int&,int);
void isert_at(int[], int&);
int find_linear(const int[], int,int);
int find_binary(const int[], int, int, bool&);
void delete_item_position(int[], int&,int);
void delete_item_isb(int[], int&,int);
void sort_list_selection(int*, int);
void sort_list_bubble(int*, int);
void print(int[], int );
int main()
{
	const int size = 20;
	int choice = 10, num_in_list = 0, mylist[size] = { 0 };
	while (1)//in order to come back to the menu after finishing one of the function
	{
		int element=0,new_element,position;
		bool sorted = 0;
		if (choice == 10)
			cout << "Welcome to the Book list program."<< endl;
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
		switch (choice)//in order to choose the right function
		{
		case 1://Insert new element at the end of the list
			if (num_in_list == size)//check that do not insert more than 20 items
				cout << "The book list is full. You can not insert one more book." << endl;
			else
			{
				cout << "Please type in the element" << endl;
				cin >> new_element;
				insert(mylist, num_in_list, new_element);
			}
			break;
		case 2://Insert new element at a certain position  
			if (num_in_list == size)//check that do not insert more than 20 items
				cout << "The book list is full, you can not insert one more book." << endl;
			else
				isert_at(mylist, num_in_list);
			break;
		case 3://Find an element (with its ISBN number and list its position) using linear search
			if (num_in_list == 0)//check out that do not find a element from a list that has no items in it
				cout << "Here is no book in the list. You need to insert at least one book first." << endl;
			else
			{
				cout << "Which element would you like to find by ISBN (linear search) ? " << endl;
				cin >> element;
				if (find_linear(mylist, num_in_list, element) != -1)
					cout << "The book with " << element << " ISBN number is at the " << find_linear(mylist, num_in_list, element) + 1 << "th position of the list." << endl;
				else
					cout << "The book has not been found." << endl;
			}
			break;
		case 4://Find an element (with its ISBN number and list its position) of a sorted list using binary search
			if (num_in_list == 0)//check out that do not find a element from a list that has no items in it
				cout << "Here is no book in the list. You need to insert at least one book first." << endl;
			else
			{
				if (find_binary(mylist, num_in_list, element, sorted) == -2)//check out the list has been sorted or not 
					cout << "The list needs to be sorted first before performing binary search." << endl;
				else
				{
					cout << "Which element would you like to find by ISBN (binary search) ? " << endl;
					cin >> element;
					if (find_binary(mylist, num_in_list, element, sorted) == -1)
						cout << "The book has not been found." << endl;

					else
						cout << "The book with " << element << " ISBN number is at the " << find_binary(mylist, num_in_list, element, sorted) + 1 << "th position of the list." << endl;
				}
			}
			break;
		case 5://Delete an element that is at a certain position
			if (num_in_list == 0)//check out that do not delete from a list that has no items in it
				cout << "Here is no book in the list. You need to insert at least one book first." << endl;
			else
			{
				cout << "Which element would you like to delete at position? " << endl;
				cin >> position;
				delete_item_position(mylist, num_in_list, position);
				print(mylist, num_in_list);
			}
			break;
		case 6://Delete an element by using its ISBN number
			if (num_in_list == 0)//check out that do not delete from a list that has no items in it
				cout << "Here is no book in the list. You need to insert at least one book first." << endl;
			else
			{
				cout << "Which element would you like to delete by ISBN number? " << endl;
				cin >> element;
				delete_item_isb(mylist, num_in_list, element);
				print(mylist, num_in_list);
			}
			break;
		case 7://Sort the list by the ISBN numbers (using selection sort)
			if (num_in_list == 0)
				cout << "Here is no book in the list. You need to insert at least one book first." << endl;
			else
				sort_list_selection(mylist, num_in_list);
			break;
		case 8://Sort the list by the ISBN numbers (using bubble sort)
			if (num_in_list == 0)
				cout << "Here is no book in the list. You need to insert at least one book first." << endl;
			else
				sort_list_bubble(mylist, num_in_list);
			break;
		case 9://Print out the list
			print(mylist, num_in_list);
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
//print function
void print(int mylist[], int num_in_list)
{
	int i;
	cout << "Your list is now" << endl;
	for (i = 0; i < num_in_list; i++)
	{
		cout << i + 1 << ".	" << mylist[i] << endl;
	}
}
 //insert function
void insert(int mylist[], int & num_in_list,int new_element)
{
	if (find_linear(mylist, num_in_list, new_element) == -1)
	{
		mylist[num_in_list] = new_element;
		num_in_list++;
		print(mylist, num_in_list);
	}
	else
	{
		delete_item_isb(mylist, num_in_list, new_element);
		mylist[num_in_list] = new_element;
		num_in_list++;
		print(mylist, num_in_list);
	}
}
//insert at function
void isert_at(int mylist[], int &num_in_list)
{
	int new_element,position,i;
	cout << "Please type in the element" << endl;
	cin >> new_element;
	cout << "At what position" << endl;
	cin >> position;

	if (find_linear(mylist, num_in_list, new_element) == -1)
	{
		if (position > num_in_list + 1)//check out whether the position is bigger than last index of list

		{
			cout << "The position you typed in is bigger than the number of books in the list. Your book will be insert at the end of the list." << endl;
			insert(mylist, num_in_list, new_element);
		}
		else//insert
		{
			for (i = num_in_list; i >= position; i--)
			{
				mylist[i] = mylist[i - 1];
			}
			mylist[position - 1] = new_element;
			num_in_list++;
			print(mylist, num_in_list);
		}
	}
	else
	{
		delete_item_isb(mylist, num_in_list, new_element);
		if (position > num_in_list + 1)//check out whether the position is bigger than last index of list

		{
			cout << "The position you typed in is bigger than the number of books in the list. Your book will be insert at the end of the list." << endl;
			insert(mylist, num_in_list, new_element);
		}
		else//insert
		{
			for (i = num_in_list; i >= position; i--)
			{
				mylist[i] = mylist[i - 1];
			}
			mylist[position - 1] = new_element;
			num_in_list++;
			print(mylist, num_in_list);
		}
	}
}
//find linear function
int find_linear(const int mylist[], int num_in_list, int element)
{
	int i;
	for (i = 0; i < num_in_list; i++)
	{
		if (mylist[i] == element)
			return i;
	}
	return -1;//indicate do not find the book
}
//find binary
int find_binary(const int mylist[], int num_in_list, int element,bool &sorted)
{
	int i=0, low=0, high=num_in_list-1, middle;
	while (!sorted&&i<num_in_list-1)//bool sorted indicate whether the list is sorted.
	{
		sorted = ((mylist[i] > mylist[i + 1]));
		i++;
	}
	if (sorted == 0)//if the list is sorted
	{
		while (high >= low)
		{
			middle = (low + high) / 2;
			if (element == mylist[middle])
				return middle;
			else if (element < mylist[middle])
				high = middle - 1;
			else if (element > mylist[middle])
				low = middle + 1;
		}
		return -1;//indicate that do not find the book
	}
	else
		return -2;//indicate that the list is not sorted
}
//delete book at certain position
void delete_item_position(int mylist[], int &num_in_list,int position)
{
	int i;
	if (position > num_in_list||position<1)
		cout << "The book has not been found."<<endl;
	else
	{
		for (i = position; i < num_in_list; i++)
			mylist[i - 1] = mylist[i];
		num_in_list--;
	}
}
//delete book with certain ISBn number
void delete_item_isb(int mylist[], int &num_in_list, int element)
{
	int i, index;
	index = find_linear(mylist, num_in_list, element);
	if (index == -1)
		cout << "The book has not been found." << endl;
	else
	{
		for (i = index; i < num_in_list; i++)
			mylist[i] = mylist[i + 1];
		num_in_list--;
	}
}
//selection sort
void sort_list_selection(int *mylist, int num_in_list)
{
	int i, j,smallest,sm_index,temp;
	for (i = 0; i < num_in_list-1; i++)
	{
		smallest = *(mylist+i);
		sm_index = i;
		for (j = i + 1; j < num_in_list; j++)
			if (smallest>*(mylist+j))
			{
				smallest = *(mylist+j);
				sm_index = j;
			}
		//swap
		temp = *(mylist+i);
		*(mylist+i) = *(mylist+sm_index);
		*(mylist+sm_index) = temp;
	}
	print(mylist, num_in_list);
}
//bubble sort
void sort_list_bubble(int *mylist, int num_in_list)
{
	int i, j, temp,flag=1;
	for (i = 0; (i < num_in_list - 1) && flag; i++)//flag is used to decrease the loop number when the list is already sorted.
	{
		flag = 0;
		for (j = 0; j < num_in_list - 1 - i; j++)
			if (*(mylist+j)>*(mylist+j + 1))
			{
				temp = *(mylist+j+1);
				*(mylist+j + 1) = *(mylist+j);
				*(mylist+j) = temp;
				flag = 1;
			}
	}
	print(mylist, num_in_list);
}
