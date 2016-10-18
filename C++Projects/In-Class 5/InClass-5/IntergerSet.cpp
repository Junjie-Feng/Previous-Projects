#include<iostream>
#include<iomanip>
#include "IntegerSet.h"
using namespace std;
IntegerSet::IntegerSet()
{
	for (int i = 0; i < 101; i++) set[i] = 0;
} // end IntegerSet constructor
void IntegerSet::inputSet()
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
	} while (number != -1); // end do...while

	cout << "Entry complete\n";
} // end function inputSet

  // prints the set to the output stream
void IntegerSet::printSet() const
{
	cout << "{ ";

	for (int u = 0; u < 101; u++)
		if (set[u]) cout << u << " ";

	cout << "}" << endl;
	} // end function printSet
//definition for UnionOfSets
 void IntegerSet::UnionOfSets(IntegerSet b, IntegerSet &c)
{
	int i;
	for (i = 0; i < 101; i++)
		c.set[i] = (set[i] || b.set[i]);
}//end function Union of Sets

