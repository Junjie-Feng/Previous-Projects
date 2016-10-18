#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int cubeByValue(int &n)
{
	//n =n*n*n;
   return n * n * n; // cube local variable n and return result
}


int main()
{
	int a[10] = { 1 }, number = 5;
	int ans;
	for (int i = 0; i < 10; i++)
		cout << a[i];
	ans = cubeByValue(number);
	cout << "\nThe new value of number is " << ans << endl;
	return 1;
}
