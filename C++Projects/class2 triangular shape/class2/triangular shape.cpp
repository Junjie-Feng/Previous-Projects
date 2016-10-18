// Name : Junjie Feng
// Course : 16:332:503 , PM for Financial Applications and Numerical Computing.
// Title : In class-2: Diamond Shape
// Date of Submission : 09/15/2015

#include<iostream>
using namespace std;

int main()
{
	int lines;// define the lines as the lines' number of the triangular shape
	int i,j;// integer type variable declaration
	cout << "how many lines you want in the triangular shape?" << endl;//prompt
	cin >> lines;
	for (i = 1; i <= lines; i++)//in order to print the triangular shape
	{
		for (j = 1; j <= i; j++)//with the increase of i, print more "*" in next line.
			cout << "*";
		cout << endl;
	}
	return 0;//indicate the successful termination of the program
}//end main