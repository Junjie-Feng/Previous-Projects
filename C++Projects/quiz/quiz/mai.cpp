#include<iostream>
#include<list>
using namespace std;
#include<iterator>
#include<algorithm>
#include<numeric>

int main()
{
	const int size = 10;
	int array[size] = { 1,3,6,2,5,4,9,0,7,8 };
	list<int> integers(array, array + size);
	ostream_iterator<int>output(cout, " ");

	cout << "1. List is: ";
	copy(integers.begin(), integers.end(), output);
	cout << endl;
	cout << "2. Remove the value of 5 from the list: ";
	integers.remove(5);
	copy(integers.begin(), integers.end(), output);
	cout << endl;
	cout << "9. ";
	ostream_iterator<int>out(cout, ", ");
	copy(integers.begin(), integers.end(), out);
	return 0;
}