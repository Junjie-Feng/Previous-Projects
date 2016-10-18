#include<iostream>
#include<iomanip>
#include "Polynomial_JunjieFeng.h"

using namespace std;
//constructor
Polynomial::Polynomial()
{
	poly = new float[7];
	for (int i = 0; i < 7; i++)
		poly[i] = 0;
}
//destructor
Polynomial::~Polynomial(){}
//set coefficient and exponent fucntion
void Polynomial::set(float coef, int exp)
{
	poly[exp]= coef;
}
//get coefficient and exponent function
float* Polynomial::get()
{
	return poly;
}
//overload + fucntion
Polynomial Polynomial::operator+(const Polynomial &b)
{
	Polynomial c;
	for (int i = 0; i < 7; i++)
		c.poly[i] = poly[i] + b.poly[i];
	return c;
}
//overload += fucntion
Polynomial &Polynomial::operator+=(const Polynomial &b)
{
	for (int i = 0; i < 7; i++)
		poly[i] = poly[i] + b.poly[i];
	return *this;
}
//overload - fucntion
Polynomial Polynomial::operator-(const Polynomial &b)
{
	Polynomial c;
	for (int i = 0; i < 7; i++)
		c.poly[i] = poly[i] - b.poly[i];
	return c;
}
//overload -= fucntion
Polynomial &Polynomial::operator-=(const Polynomial &b)
{
	for (int i = 0; i < 7; i++)
		poly[i] = poly[i] - b.poly[i];
	return *this;
}
//overload * fucntion
Polynomial Polynomial::operator*(const Polynomial &b)
{
	Polynomial c;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			c.poly[i + j] += poly[i] * b.poly[j];
		}
	}
	return c;
}
//overload *= fucntion
Polynomial &Polynomial::operator*=(const Polynomial &b)
{
	Polynomial c;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			c.poly[i + j] += poly[i] * b.poly[j];
		}
	}
	for (int i = 0; i < 7; i++)
		poly[i] = c.poly[i];
	return *this;
}
//overload = fucntion
void Polynomial::operator=(Polynomial &b)
{
	for (int i = 0; i < 7;i++)
		poly[i] = b.poly[i];
}
//overload << fucntion
ostream &operator << (ostream &output, const Polynomial &a)
{
	cout << setprecision(6);
	int flag=0;
	for (int i = 0; i < 7; i++)
	{
		if (a.poly[i] > 0)
		{		
			if (flag)
				output << " + ";
			if (i > 1 || i < 0)
			{
				output << a.poly[i] << "x^" << i;
				flag = 1;
			}
			if (i == 1)
			{
				output << a.poly[i] << "x";
				flag = 1;
			}
			if (i == 0)
			{
				output << a.poly[i];
				flag = 1;
			}
		}
		if (a.poly[i] < 0)
		{
			if (i > 1 || i < 0)
			{
				output << a.poly[i] << "x^" << i;
				flag = 1;
			}
			if (i == 1)
			{
				output << a.poly[i] << "x";
				flag = 1;
			}
			if (i == 0)
			{
				output << a.poly[i];
				flag = 1;
			}
		}
	}
	return output;
}



