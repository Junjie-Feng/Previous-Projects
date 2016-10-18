// SetTest.cpp
// Driver program for class IntegerSet.

#include <iostream>
using namespace std;

#include "IntegerSet.h" // IntegerSet class definition

int main()
{
	int set[101];
	IntegerSet a;
	IntegerSet b;
	IntegerSet c;

	cout << "Enter set A:\n";
	a.inputSet(set);
	cout << "\nSet A is : \n";
	a.printSet(set);

	cout << "\nEnter set B:\n";
	b.inputSet(set);
	cout << "\nSet B is : \n";
	b.printSet(set);

	/* Write call to unionOfSets for object a, passing b as argument and assigning the result to c */

	cout << "\nUnion of A and B is:\n";
	c.printSet(set);

	return 0;
}