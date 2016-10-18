// Name : Junjie Feng
// Course : 16:332:503:01 , Programming Financial
// Title : Homework-2 Monte Carlo Calculation of Pi
//Date of Submission: 09/17/2015

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cmath>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
	double x, y, pi; //delare the x & y & pi & range are double data type
	int i,iterations, hit = 0; //declare the hit number starts from zero, loop number starts from one. they are both integer
	cout << "please enter the number of iterations: "; //prompt
	cin >> iterations;
	srand(time(0)); //generate the random number based on time
	cout << setw(15) << "x" << setw(15) << "y" << endl;
	ofstream file;
	file.open("X-Ycorrdinate.txt"); //opens the file X-Ycorrdinate.txt
	file << setw(15) <<" x "<< setw(15) <<" y" << endl;
	for (i = 1; i <= iterations; i++)
	{
		x = (double)rand() / RAND_MAX; //generate the random x-coordinate
		y = (double)rand() / RAND_MAX; //generate the random y-coordinate
		file << setw(15) << x << setw(15) << y << endl; //write the values to the file
		cout << setw(15) << x << setw(15) << y << endl;
		if (y <= sqrt(1 - pow(x, 2))) //check whether the darts hitted the circle area
			hit++;
	}
	pi = (double)4 * hit / iterations; //calculated the pi value
	cout << " The estimated value of pi using Monte Carlo Calculation is " << fixed << setprecision(15) << pi << endl;
	file << " The estimated value of pi using Monte Carlo Calculation is " << fixed << setprecision(15) << pi << endl;
	return 0; // show the successful termination of the program
}//end main