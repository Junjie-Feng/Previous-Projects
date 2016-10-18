#include "Circle.h"
#include<iostream>
#include<iomanip>
using namespace std;
//constructor function
Circle::Circle(float xValue, float yValue, float radiusValue)
	:TwoDimensionalShape(xValue,yValue,radiusValue)
{
	setRorL(radiusValue);
}
//set value fucntion
void Circle::set(float xValue, float yValue, float radiusValue)
{
	setx(xValue);
	sety(yValue);
	setRorL(radiusValue);
}
//calculate area function
float Circle::getArea()
{
	return pi*getRorL()*getRorL();//calculate the area
}
//circle print function
void Circle::print()
{
	cout << "The circle with radius " << getRorL() << " that is located at : ";
	TwoDimensionalShape::print();
	cout<< " has : " << endl
		<< "An area of : " << getArea()<<endl<<endl;
}
//destructor function
Circle::~Circle()
{
}
