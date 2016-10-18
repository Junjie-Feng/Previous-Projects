// Name : Junjie Feng
// Course : 16:332:503 , PM for Financial Applications and Numerical Computing.
// Title : In class-2: Diamond Shape
// Date of Submission : 09/15/2015

#include<iostream>
using namespace std;

int main()
{
	int lines;//define lines as the lines' number of the shape
	int i, j; //integer type variable declaration
	cout << "how many lines you want in the diamond shape?" << endl;//prompt
	cin>>lines;
	for (; lines % 2 == 0;)
	{
		cout << "please enter an odd number as the lines' number of the diamond shape" << endl;//The lines'number must be even
		cin >> lines;
	}
		for (i = 1; i <= (lines + 1) / 2; i++)//in order to print the top half of the diamond shape
		{
			for (j = 1; j <= ((lines + 1) / 2 - i); j++)//With the i increasing, the number of " " decreasing
				cout << " ";
			for (j = 1; j <= 2 * i - 1; j++)//With the i increasing, the number of "*" increasing
				cout << "*";
			cout << endl;
		}
		for (i = (lines - 1) / 2; i >= 1; i--)//in order to print the bottom half of the diamond shape
		{
			for (j = 1; j <= ((lines + 1) / 2 - i); j++)//With the i decreasing, the number of " " increasing
				cout << " ";
			for (j = 1; j <= (2 * i - 1); j++)//With the i decreasing, the number of "*" decreasing
				cout << "*";
			cout << endl;
		}
	return 0;//indicate the successful termination of the program
}//end main