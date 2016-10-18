#ifndef POLY_H//youmeiyou _H youshenme yingxiang me ?
#define POLY_H

#include<iostream>
using namespace std;
using std::ostream;

class Polynomial
{
	friend ostream &operator<<(ostream &, const Polynomial &);//overload << print fucntion
public:
	Polynomial();//constructor
	void set(float, int);//set polynomial coefficient and exponent
	float* get();//get polynomial coefficient and exponent
	Polynomial operator+ (const Polynomial &);//overload +
	Polynomial &operator+=(const Polynomial &);//overload +=
	Polynomial operator-(const Polynomial &);//overload -
	Polynomial &operator-=(const Polynomial &);//overload -=
	Polynomial operator*(const Polynomial&);//overload *
	Polynomial &operator*=(const Polynomial&);//overload *=
	void operator=( Polynomial&);//overload =
	~Polynomial();//destructor
private:
	float *poly;//store the coefficient and exponent
	float num_term;//number of terms in the polynomial
};
#endif
