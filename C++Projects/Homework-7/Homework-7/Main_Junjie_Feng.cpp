////Name : Junjie Feng
//Course : Programming Financial
//Title : Homewrok-7
//Date of Submission : 10/29/2015

#include<iostream>
#include<iomanip>
#include"Polynomial_JunjieFeng.h"

using namespace std;

int main()
{
	int i, num_term, exp;
	float coef;
	Polynomial p1;
	Polynomial p2;
	Polynomial p3;//creat objects
	Polynomial temp; //polunomial temp be used to show the result of +=, -= and *=
	cout << "Enter the number of polynomial terms : ";//prompt for fisrt polynomial
	cin >> num_term;
	for (i = 0; i < num_term; i++)
	{
		cout << "Enter coefficient and exponent : ";
		cin >> coef >> exp;
		p1.set(coef, exp);
	}
	cout << endl << "Enter the number of polynomial terms : ";//prompt for second polynomial
	cin >> num_term;
	for (i = 0; i < num_term; i++)
	{
		cout << "Enter coefficient and exponent : ";
		cin >> coef >> exp;
		p2.set(coef, exp);
	}
	//print two polynomials
	cout << endl << "First Polynomial is : " << p1 << endl
		<< "Second Polynomial is : " <<p2 << endl;
	//overload + and += 
	p3 = p1 + p2;
	temp = p1;//use overload =
	temp += p2;
	cout << endl << "Adding polynomial yields : " << p3 << endl//print
		<< "+= the polynomial yields : " << temp << endl;
	//overload - and -=
	p3 = p1 - p2;
	temp = p1;
	temp -= p2;
	cout << endl << "Subtracting the polynomial yields : " << p3 << endl //print
		<< "-= the polynomials yields : " << temp << endl;
	//overload * and *=
	p3 = p1*p2;
	temp = p1;
	temp*=p2;
	cout << endl << "Multiplying the polynomials yields: " << p3 <<endl //print
		<< "*= the polynomial yields: " << temp << endl;
	return 0;
}//end main