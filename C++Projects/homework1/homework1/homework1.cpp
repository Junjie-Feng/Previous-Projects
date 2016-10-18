// Name : Junjie Feng
// Course : 16:332:503:01 , Programming Financial
// Homework : Homework 1

#include<iostream>
using namespace std;

int main()
{
	float num1, num2, num3, num4, num5;// five numbers to be input by user
	float max, min;//variable in which the maximum and minimum of those numbers will be stored

	cout << "Enter five integer numbers: " << endl; //prompt

	cin >> num1 >> num2 >> num3 >> num4 >> num5;//store five numbers which are typed in by user

	if (num1 >= num2)
	{
		max = num1;
		min = num2;
	}
	if (num1 <= num2)
	{
		max = num2;
		min = num1;
	}
	if (num3 >= max)
		max = num3;
	if (num3 <= min)
		min = num3;
	if (num4 >= max)
		max = num4;
	if (num4 <= min)
		min = num4;
	if (num5 >= max)
		max = num5;
	if (num5 <= min)
		min = num5;        // comparison of those five numbers, find the maximum and the minimum

	cout << "The maximum number is : " << max <<endl<< "The minimum number is : " << min << endl;
	//display the maximum number and the minimum number

	return 0;  // indicates successful termination of the program
}  // end main