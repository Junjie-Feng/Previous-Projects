// Name : Junjie Feng
// Course : 16:332:503:01 , Programming Financial
// Title : Homework-2 Monte Carlo Calculation of Pi
//Date of Submission: 09/17/2015

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cmath>
#include <iomanip>
#include<fstream>
using namespace std;

int main()
{
	const double PI = 3.14159265358979323846;//declare the accurate PI value as a constant
	double x, y, pi = 0, range; //delare the x & y & pi & range are double data type
	int hit = 0, loop = 1; //declare the hit number starts from zero, loop number starts from one. they are both integer
	cout << "What is the biggest difference you expect between the estimated pi and the accurate value?" << endl; //prompt
	cin >> range;
	srand(time(0));//generate the random number based on time
	cout << setw(15) << "x" << setw(15) << "y" << endl;
	ofstream file;
	file.open("X-Ycorrdinate__optional assignment.txt");//opens the file X-Ycorrdinate__optional assignment.txt
	file << setw(15) <<" x "<< setw(15) <<" y" << endl;
	for (; fabs(pi - PI) >= range;)
	{
			x = (double)rand() / RAND_MAX; //generate the random x-coordinate
			y = (double)rand() / RAND_MAX; //generate the random y-coordinate
			cout << setw(15) << x << setw(15) << y << endl;
			file << setw(15) << x << setw(15) << y << endl; //write the values to the file
			if (y <= sqrt(1 - pow(x, 2))) //check whether the darts hitted the circle area
				hit++;
		pi = (double)4 * hit / loop; //calculated the pi value
		loop++;
	}
	cout << " The estimated value of pi using Monte Carlo Calculation is " << fixed << setprecision(10) << pi << endl;
	file << " The estimated value of pi using Monte Carlo Calculation is " << fixed << setprecision(10) << pi << endl;
	return 0; // show the successful termination of the program
}//end main