//Name : Junjie Feng
//Course : Programming Financial
//Title : In Class 5
//Date of Submission:10/20/2015


// SetTest.cpp
// Driver program for class IntegerSet.
#include <iostream>
#include<iomanip>
using namespace std;

#include "IntegerSet.h" // IntegerSet class definition

int main()
{
	IntegerSet a;
	IntegerSet b;
	IntegerSet c;

	cout << "Enter set A:\n";
	a.inputSet();
	cout << "\nSet A is : \n";
	a.printSet();

	cout << "\nEnter set B:\n";
	b.inputSet();
	cout << "\nSet B is : \n";
	b.printSet();

	a.UnionOfSets(b,c);/* unionOfSets for object a, passing b as argument and assigning the result to c */

	cout << "\nUnion of A and B is:\n";
	c.printSet();

	return 0;
}