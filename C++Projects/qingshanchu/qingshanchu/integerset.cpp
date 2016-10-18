// IntegerSet.cpp
// Member-function definitions for class IntegerSet.

#include <iostream>
#include <iomanip>
#include "IntegerSet.h"
using namespace std;

IntegerSet::IntegerSet()
{
	for (int i = 0; i < 101; i++)
		set[i] = 0;
} // end IntegerSet constructor

  // input a set from the user
void IntegerSet::inputSet(int set[101])
{
	int number;

	do
	{
		cout << "Enter an element (-1 to end): ";
		cin >> number;

		if (validEntry(number))
			set[number] = 1;
		else if (number != -1)
			cout << "Invalid Element\n";
	}

	while (number != -1); // end do...while

	cout << "Entry complete\n";
} // end function inputSet

  // prints the set to the output stream
void IntegerSet::printSet(int set[101]) const
{
	cout << "{";

	for (int u = 0; u < 101; u++)
		if (set[u] == 1)
			cout << u << " ";

	cout << "}" << endl;
} // end function printSet