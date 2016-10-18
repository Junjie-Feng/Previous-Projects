#include "Booklist_Feng.h"//Booklist class in header file
#include<iostream>
#include<iomanip>
using namespace std;


Booklist::Booklist(int size)//construction
	:size(size)
{
	num_in_list = 0;
}//end Booklist construction

//insert function
void Booklist::insert()
{
	if (num_in_list == size)//check out whether the next insert will overflow
		cout << "The book list is full. You can not insert one more book." << endl;
	else
	{
		cout << "Please type in the element" << endl;
		cin >> element;
		if (find() == -1)//if the book is not exist in the book list
		{
			mylist[num_in_list] = element;
			num_in_list++;
		}
		else//if the book is exist in the book list
		{
			delete_();//delete the previous one first
			mylist[num_in_list] = element;
			num_in_list++;
		}
	}
}//end insert function

void Booklist::isert_at()
{
	if (num_in_list == 100)//check out whether the next insert will overflow
		cout << "The book list is full, you can not insert one more book." << endl;
	else
	{
		cout << "Please type in the element" << endl;
		cin >> element;
		cout << "At what position" << endl;
		cin >> position;
		int i;
		if (find() == -1)//if the book is not exist in the book list
		{
			if (position > num_in_list + 1)//check out whether the position is bigger than last index of list
			{
				cout << "The position you typed in is bigger than the number of books in the list. Your book will be insert at the end of the list." << endl;
				insert();
			}
			else//insert
			{
				for (i = num_in_list; i >= position; i--)
				{
					mylist[i] = mylist[i - 1];
				}
				mylist[position - 1] = element;
				num_in_list++;
			}
		}
		else//if the book is exist in the book list
		{
			delete_();//delete the previous one first
			if (position > num_in_list + 1)//check out whether the position is bigger than last index of list

			{
				cout << "The position you typed in is bigger than the number of books in the list. Your book will be insert at the end of the list." << endl;
				insert();
			}
			else//insert
			{
				for (i = num_in_list; i >= position; i--)
				{
					mylist[i] = mylist[i - 1];
				}
				mylist[position - 1] = element;
				num_in_list++;
			}
		}
	}
}//end insert_at function
//find by linear function
void Booklist::find_linear()
{
	int i, exist = 0;
	if (num_in_list == 0)//check out whether the next insert will overflow
		cout << "Here is no book in the list. You need to insert at least one book first." << endl;
	else
	{
		cout << "Which element would you like to find by ISBN (linear search) ? " << endl;
		cin >> element;
		for (i = 0; i < num_in_list; i++)//for loop is to compare every-element with the input-element
		{
			if (mylist[i] == element)
			{
				cout << "The book with " << element << " ISBN number is at the " << i + 1 << "th position of the list." << endl;
				exist = 1;//indicate the book exist in the book list
				break;
			}
		}
		if (!exist)
		cout << "The book has not been found." << endl;//indicate do not find the book
	}
}//end find by linear function
//find by binary function
void Booklist::find_binary()
{
	int i = 0, min_index = 0, max_index = num_in_list - 1, middle;
	if (num_in_list == 0)//check out whether the next insert will overflow
		cout << "Here is no book in the list. You need to insert at least one book first." << endl;
	else
	{
		while ((mylist[i] < mylist[i + 1]) && i < max_index)//indicate whether the list is sorted.
		{
			i++;
		}
		
		if (i == max_index)//if the list is sorted
		{
			cout << "Which element would you like to find by ISBN (binary search) ? " << endl;
			cin >> element;
			while (max_index >= min_index)//search for the book by binary logic.
			{
				middle = (min_index + max_index) / 2;
				if (element == mylist[middle])
				{
					cout << "The book with " << element << " ISBN number is at the " << middle + 1 << "th position of the list." << endl;
					break;
				}
				else if (element < mylist[middle])
					max_index = middle - 1;
				else if (element > mylist[middle])
					min_index = middle + 1;
			}
			if (max_index < min_index)
			cout << "The book has not been found." << endl;//indicate that do not find the book
		}
		else//if the list is not sorted
			cout << "The list needs to be sorted first before performing binary search." << endl;
	}
}//end find by binary function
//delete by position function
void Booklist::delete_item_position()
{
	int i;
	if (num_in_list == 0)//check out whether the next insert will overflow
		cout << "The book list is empty. You need to insert at least one book first." << endl;
	else
	{
		cout << "Which element would you like to delete at position? " << endl;
		cin >> position;
		if (position > num_in_list || position < 1)//if the position is not in the list
			cout << "The book has not been found." << endl;
		else
		{
			for (i = position; i < num_in_list; i++)//move the the books forward
				mylist[i - 1] = mylist[i];
			num_in_list--;
		}
	}
}//end delete by position function
//delete by ISBN function
void Booklist::delete_item_isbn()
{		
	int i;
	if (num_in_list == 0)//check out whether the next insert will overflow
		cout << "Here is no book in the list. You need to insert at least one book first." << endl;
	else
	{
		cout << "Which element would you like to delete by ISBN number? " << endl;
		cin >> element;
		if (find() == -1)//check out whether the book is exist in the book list
			cout << "The book has not been found." << endl;
		else
		{
			for (i = find(); i < num_in_list; i++)//move the books forward
				mylist[i] = mylist[i + 1];
			num_in_list--;
		}
	}
}//end delete by ISBN function
//sort by selection function
void Booklist::sort_list_selection()
{
	int i, j, smallest, sm_index, temp;
	if (num_in_list == 0)//check out whether the next insert will overflow
		cout << "Here is no book in the list. You need to insert at least one book first." << endl;
	else
	{
		for (i = 0; i < num_in_list - 1; i++)//find the smallest element
		{
			smallest = *(mylist + i);
			sm_index = i;
			for (j = i + 1; j < num_in_list; j++)
				if (smallest>*(mylist + j))
				{
					smallest = *(mylist + j);
					sm_index = j;
				}
			//swap
			temp = *(mylist + i);
			*(mylist + i) = *(mylist + sm_index);
			*(mylist + sm_index) = temp;
		}
	}
}//end sort by selection function
//sort by bubble function
void Booklist::sort_list_bubble()
{
	int i, j, temp, flag = 1;
	if (num_in_list == 0)//check out whether the next insert will overflow
		cout << "Here is no book in the list. You need to insert at least one book first." << endl;
	else
	{
		for (i = 0; (i < num_in_list - 1) && flag; i++)//flag is used to decrease the loop number when the list is already sorted.
		{
			flag = 0;
			for (j = 0; j < num_in_list - 1 - i; j++)//switch the next elements into ascending order.
				if (*(mylist + j)>*(mylist + j + 1))
				{
					temp = *(mylist + j + 1);
					*(mylist + j + 1) = *(mylist + j);
					*(mylist + j) = temp;
					flag = 1;//indicate whether the list is in ascending order.
				}
		}
	}
}//end sort by bubble function
//pirnt function
void Booklist::print() const
{
	int i;
	cout << "Your list is now ";
	if (num_in_list == 0)//check out whether the next insert will overflow
		cout << "empty. " << endl;
	else
	{
		cout << endl;
		for (i = 0; i < num_in_list; i++)
		{
			cout << i + 1 << ".	" << mylist[i] << endl;
		}
	}
}//end print function
//destructor
Booklist::~Booklist()
{
}
//Private: find function
int Booklist::find()
{
	int i;
	for (i = 0; i < num_in_list; i++)
	{
		if (mylist[i] == element)
			return i;//return the index of the certain element
	}
	return -1;//indicate do not find the element
}//end find function
//Private: delete function
void Booklist::delete_()
{
	int i;
	for (i = find(); i < num_in_list; i++)
		mylist[i] = mylist[i + 1];
	num_in_list--;
}//end delete function
