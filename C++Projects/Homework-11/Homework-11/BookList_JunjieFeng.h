#ifndef BOOKLIST_H//same statement as #program once
#define BOOKLIST_H
template<class T>//Specify class-template definition; type parameter T indicates type of booklist class to be created
class Booklist//define class name "Booklist"
{
public:
	Booklist(int=100);//constructor
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
	int find();
	void delete_();
	//declare variables 
	T *mylist;//Array of elements of type T.
	T element;//variable of type T.
	const int size;
	int num_in_list;
};
#endif

template<class T>//Member functions preceded with header 
Booklist<T>::Booklist(int size)//construction
	:size(size)
{
	mylist = new T[size];//Constructor creates array of type T. 
	num_in_list = 0;
}//end Booklist construction

//insert function
template<class T>//Member functions preceded with header 
void Booklist<T>::insert()
{
	cout << "Please type in the element" << endl;
	cin >> element;
	if (find() != -1)//if the book exists in the book list
		delete_();//delete the previous one first
	mylist[num_in_list] = element;
	num_in_list++;
}//end insert function
template<class T>//Member functions preceded with header 
void Booklist<T>::isert_at()
{
	int position;
	if (num_in_list == 100)//check out whether the next insert will overflow
		cout << "The book list is full, you can not insert one more book." << endl;
	else
	{
		cout << "Please type in the element" << endl;
		cin >> element;
		cout << "At what position" << endl;
		cin >> position;
		int i;
		if (find() != -1)//if the book exists in the book list
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
}//end insert_at function
 //find by linear function
template<class T>//Member functions preceded with header 
void Booklist<T>::find_linear()
{
	int i, exist = 0;
	if (num_in_list == 0)//check out whether the next insert will overflow
		cout << "Here is no book in the list. You need to insert at least one book first." << endl;
	else
	{
		cout << "Which element would you like to find by book name (linear search) ? " << endl;
		cin >> element;
		for (i = 0; i < num_in_list; i++)//for loop is to compare every-element with the input-element
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
	int i = 0, min_index = 0, max_index = num_in_list - 1, middle;
	if (num_in_list == 0)//check out whether the next insert will overflow
		cout << "Here is no book in the list. You need to insert at least one book first." << endl;
	else
	{
		while ((mylist[i] < mylist[i + 1]) && i < max_index)//indicate whether the list is sorted.
			i++;
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
	int i, position;
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
 //delete by book name function
template<class T>//Member functions preceded with header 
void Booklist<T>::delete_item_name()
{
	int i;
	if (num_in_list == 0)//check out whether the next insert will overflow
		cout << "Here is no book in the list. You need to insert at least one book first." << endl;
	else
	{
		cout << "Which element would you like to delete by book name? " << endl;
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
}//end delete by book name function
 //sort by selection function
template<class T>//Member functions preceded with header 
void Booklist<T>::sort_list_selection()
{
	int i, j, sm_index;
	T smallest, temp;
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
template<class T>//Member functions preceded with header 
void Booklist<T>::sort_list_bubble()
{
	int i, j, flag = 1;
	T  temp;
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
template<class T>//Member functions preceded with header 
void Booklist<T>::print() const
{
	int i;
	cout << "The list is : ";
	if (num_in_list == 0)//check out whether the next insert will overflow
		cout << "empty. " << endl;
	else
		for (i = 0; i < num_in_list; i++)
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
int Booklist<T>::find()
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
template<class T>//Member functions preceded with header 
void Booklist<T>::delete_()
{
	int i;
	for (i = find(); i < num_in_list; i++)
		mylist[i] = mylist[i + 1];
	num_in_list--;
}
//end delete function
