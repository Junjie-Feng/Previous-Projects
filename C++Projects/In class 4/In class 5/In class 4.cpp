//Name : Junjie Feng
//Course : 16:332:503:01 , Programming Financial
//Title : In-class 5
//Date of submission: 10/05/2015

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

long int get_sum(double, int);

int main()
{
	double num;
	int n = 19;
	cout << "please input a non-negative integer (no more than 2^64) :" << endl;
	cin >> num;
	cout << fixed << setprecision(0) << "The sum of the digits in " << num << " is " << get_sum(num, n) << endl;
	return 0;
}
long int get_sum(double a, int n)
{
	int sum = 0;
	if (n < 0)
		return sum;
	else
	{
		sum = static_cast<int> (a / pow(10, n));
		a = a - sum*pow(10, n);
		return sum + get_sum(a, n - 1);
	}
}