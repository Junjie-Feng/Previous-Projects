//Name : Junjie Feng
//Course : Programming Financial
//Title : Homewrok-5
//Date of Submission : 10/08/2015

#include<cmath>
#include<iostream>
#include<iomanip>
using namespace std;

void square_integer(int);
bool jump(int[], int);
const int size_of_arrary = 100;
int main()
{
	while (1)
	{
		int row[size_of_arrary] = { 0 }, number_of_integers = size_of_arrary, choice = 0, integer, i;
		cout << "Menu:" << endl
			<< "Number 1 : Print the squares of the integers from 1 to n" << endl
			<< "Number 2 : Puzzle Jump" << endl
			<< "Number 3 : Quit" << endl
			<< "Enter the number as your choice : " << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:// Fisrt assignment: print the prints the squares of the integers from 1 to n, separated by commas.
			cout << "Please input a integer : " << endl;//prompt
			cin >> integer;
			cout << "On input is " << integer << ", The series is ";
			square_integer(integer);
			cout << endl<<endl;
			break;
		case 2://Second assignment: puzzle jump
			cout << "Please enter a row of positive integers : " << endl;//prompt
			for (i = 0; i < number_of_integers; i++)//for loop gets the number of the integers.
			{
				cin >> row[i];
				if (row[i] == 0)
					number_of_integers = i;
			}
			if (jump(row, 0))//if jump function is true, means that the puzzle can be solved, otherwise, the puzzle can not be solved.
				cout << "True! The puzzle can be solved."<<endl<<endl;
			else
				cout << "False! The puzzle can not be unsolved."<<endl<<endl;
			break;
		case 3://Quit
			return 0;
		default:
			cout << "You should input a number among 1, 2, 3." << endl;
		}
	}
}

//Function for first assignment
void square_integer(int n)
{
	if (n % 2 == 1 && n >=1)//If the input integer is odd
	{
		cout << n*n << ", ";
		square_integer(n - 2);//Recursive case: to print the square of odd integers in descending order	
		if (n > 1)
			cout << (n - 1)*(n - 1)<<", ";//Print square of even integers in ascending order.
	}
	if (n % 2 == 0 && n > 0)//If the input inteher is even
	{
		cout << (n - 1)*(n - 1) << ", ";//Recursive case: to print the square of odd integers in descending order	
		square_integer(n - 2);
		cout << n*n << ", ";//print the square of even integers
	}
}
//Function for second assignment
bool jump(int row[], int index)
{
	int i, number_of_integers = size_of_arrary, right_index, left_index;
	for (i = 0; i < number_of_integers; i++)//To get the number of elements.
	{
		if (row[i] == 0)
			number_of_integers = i;
	}
	right_index = index + abs(row[index]);//Calculate the indexes of the two sides' element.
	left_index = index - abs(row[index]);
	if (right_index <= number_of_integers && row[right_index] != -1)//Check the right side
	{
		row[index] = -1;//Indicate that this element has been used
		if (row[right_index] == 0)//If reach the rightmost, indicate the puzzle can be solved.
			return true;
		if (jump(row, right_index))//Move to the right element
			return true;
	}
	if (left_index >= 0 && row[left_index] != -1)//Check the left side
	{
		row[index] = -1;//Indicate that this element has been used
		if (jump(row, left_index))//Move to the left element
			return true;//Indicate the puzzle can be solved
	}
	return false;//Indicate the puzzle can not be solved
}
