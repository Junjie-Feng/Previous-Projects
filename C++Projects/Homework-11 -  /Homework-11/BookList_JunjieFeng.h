#ifndef BOOKLIST_H//same statement as #program once
#define BOOKLIST_H
#include<vector>
using namespace std;
template<class T>//Specify class-template definition; type parameter T indicates type of booklist class to be created
class Booklist//define class name "Booklist"
{
public:
	Booklist();//constructor
	//declare member function for booklist management
	void insert();
	void isert_at();
	void find_linear();
	void find_binary();
	void delete_item_position();
	void delete_item_name();
	void sort_list_selection();
	void sort_list_bubble();
	void print() const;
	~Booklist();//destructor

private:
	//declare private functions invoked by member functions
	unsigned int find();
	void delete_();
	//declare variables 
	vector<T>mylist;//Array of elements of type T.
	T element;//variable of type T.
};
#endif
template<class T>//Member functions preceded with header 
Booklist<T>::Booklist()//construction
{}//end Booklist construction
//insert function
template<class T>//Member functions preceded with header 
void Booklist<T>::insert()
{
	cout << "Please type in the element" << endl;
	cin >> element;
	if (find() != -1)//if the book exists in the book list
		delete_();//delete the previous one first
	mylist.push_back(element);
}//end insert function


template<class T>//Member functions preceded with header 
void Booklist<T>::isert_at()
{
	unsigned int i, position;
	if (mylist.size() == 100)//check out whether the next insert will overflow
		cout << "The book list is full, you can not insert one more book." << endl;
	else
	{
		cout << "Please type in the element" << endl;
		cin >> element;
		cout << "At what position" << endl;
		cin >> position;
		if (find() != -1)//if the book exists in the book list
			delete_();//delete the previous one first
		if (position > mylist.size() + 1)//check out whether the position is bigger than last index of list
		{
			cout << "The position you typed in is bigger than the number of books in the list. Your book will be insert at the end of the list." << endl;
			insert();
		}
		else//insert
		{
			mylist.push_back(mylist[mylist.size() - 1]);
			for (i = mylist.size()-2; i >= position; i--)
			{
				mylist[i] = mylist[i - 1];
			}
			mylist[position - 1] = element;
		}
	}
}//end insert_at function
 //find by linear function
template<class T>//Member functions preceded with header 
void Booklist<T>::find_linear()
{
	unsigned int i, exist = 0;
	if (mylist.size() == 0)//check out whether the next insert will overflow
		cout << "Here is no book in the list. You need to insert at least one book first." << endl;
	else
	{
		cout << "Which element would you like to find by book name (linear search) ? " << endl;
		cin >> element;
		for (i = 0; i < mylist.size(); i++)//for loop is to compare every-element with the input-element
		{
			if (mylist[i] == element)
			{
				cout << "The book with name '" << element << "' is at the " << i + 1 << "th position of the list." << endl;
				exist = 1;//indicate the book exist in the book list
				break;
			}
		}
		if (!exist)
			cout << "The book has not been found." << endl;//indicate do not find the book
	}
}//end find by linear function
 //find by binary function
template<class T>//Member functions preceded with header 
void Booklist<T>::find_binary()
{
	unsigned int i = 0, min_index = 0, max_index, middle;
	max_index = mylist.size() - 1;
	if (mylist.size() == 0)//check out whether the next insert will overflow
		cout << "Here is no book in the list. You need to insert at least one book first." << endl;
	else
	{
		for (i = 0; i < max_index; i++)//indicate whether the list is sorted.
			if (!(mylist[i] < mylist[i + 1]))
				break;
		if (i == max_index)//if the list is sorted
		{
			cout << "Which element would you like to find by book name (binary search) ? " << endl;
			cin >> element;
			while (max_index >= min_index)//search for the book by binary logic.
			{
				middle = (min_index + max_index) / 2;
				if (element == mylist[middle])
				{
					cout << "The book with name '" << element << "' is at the " << middle + 1 << "th position of the list." << endl;
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
template<class T>//Member functions preceded with header 
void Booklist<T>::delete_item_position()
{
	unsigned int i, position;
	if (mylist.size() == 0)//check out whether the next insert will overflow
		cout << "The book list is empty. You need to insert at least one book first." << endl;
	else
	{
		cout << "Which element would you like to delete at position? " << endl;
		cin >> position;
		if (position > mylist.size() || position < 1)//if the position is not in the list
			cout << "The book has not been found." << endl;
		else
		{
			for (i = position; i < mylist.size(); i++)//move the the books forward
				mylist[i - 1] = mylist[i];
			mylist.pop_back();
		}
	}
}//end delete by position function
 //delete by book name function
template<class T>//Member functions preceded with header 
void Booklist<T>::delete_item_name()
{
	unsigned int i;
	if (mylist.size() == 0)//check out whether the next insert will overflow
		cout << "Here is no book in the list. You need to insert at least one book first." << endl;
	else
	{
		cout << "Which element would you like to delete by book name? " << endl;
		cin >> element;
		if (find() == -1)//check out whether the book is exist in the book list
			cout << "The book has not been found." << endl;
		else
		{
			for (i = find(); i < mylist.size()-1; i++)//move the books forward
				mylist[i] = mylist[i + 1];
			mylist.pop_back();
		}
	}
}//end delete by book name function
 //sort by selection function
template<class T>//Member functions preceded with header 
void Booklist<T>::sort_list_selection()
{
	unsigned int i, j, sm_index;
	T smallest, temp;
	if (mylist.size() == 0)//check out whether the next insert will overflow
		cout << "Here is no book in the list. You need to insert at least one book first." << endl;
	else
	{
		for (i = 0; i < mylist.size() - 1; i++)//find the smallest element
		{
			smallest = mylist[i];
			sm_index = i;
			for (j = i + 1; j < mylist.size(); j++)
				if (smallest>mylist[j])
				{
					smallest = mylist[j];
					sm_index = j;
				}
			//swap
			temp = mylist[i];
			mylist[i] = mylist[sm_index];
			mylist[sm_index] = temp;
		}
	}
}//end sort by selection function
 //sort by bubble function
template<class T>//Member functions preceded with header 
void Booklist<T>::sort_list_bubble()
{
	unsigned int i, j, flag = 1;
	T  temp;
	if (mylist.size() == 0)//check out whether the next insert will overflow
		cout << "Here is no book in the list. You need to insert at least one book first." << endl;
	else
	{
		for (i = 0; (i < mylist.size() - 1) && flag; i++)//flag is used to decrease the loop number when the list is already sorted.
		{
			flag = 0;
			for (j = 0; j < mylist.size() - 1 - i; j++)//switch the next elements into ascending order.
				if (mylist[j]>mylist[j + 1])
				{
					temp = mylist[j + 1];
					mylist[j + 1] = mylist[j];
					mylist[j] = temp;
					flag = 1;//indicate whether the list is in ascending order.
				}
		}
	}
}//end sort by bubble function
 //pirnt function
template<class T>//Member functions preceded with header 
void Booklist<T>::print() const
{
	unsigned int i;
	cout << "The list is : ";
	if (mylist.size() == 0)//check out whether the next insert will overflow
		cout << "empty. " << endl;
	else
		for (i = 0; i < mylist.size(); i++)
			cout << mylist[i] << "  ";
	cout << endl;
}//end print function
 //destructor
template<class T>//Member functions preceded with header 
Booklist<T>::~Booklist()
{
}
//Private: find function
template<class T>//Member functions preceded with header 
unsigned int Booklist<T>::find()
{
	unsigned int i;
	for (i = 0; i < mylist.size(); i++)
	{
		if (mylist[i] == element)
			return i;//return the index of the certain element
	}
	return -1;//indicate do not find the element
}//end find function
 //Private: delete function
template<class T>//Member functions preceded with header 
void Booklist<T>::delete_()
{
	unsigned int i;
	for (i = find(); i < mylist.size()-1; i++)
		mylist[i] = mylist[i + 1];
	mylist.pop_back();
}
//end delete function
