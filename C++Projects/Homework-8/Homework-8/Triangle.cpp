#include "Triangle.h"
#include<iostream>
#include<math.h>
using namespace std;
//constructor function
Triangle::Triangle(float xValue, float yValue, float lengthValue)
	:TwoDimensionalShape(xValue,yValue, lengthValue)
{

	setRorL(lengthValue);
}
//set value function
void Triangle::set(float xValue, float yValue, float lengthValue)
{
	setx(xValue);
	sety(yValue);
	setRorL(lengthValue);
}
//calculate area function
float Triangle::getArea()
{
	return (float)sqrt(3)/4*getRorL()*getRorL();//calculate the area
}
//triangle print function
void Triangle::print() 
{
	cout << "The triangle with length " << getRorL() << " that is located at : ";
	TwoDimensionalShape::print();
	cout << " has : " << endl
		<< "An area of : " << getArea() << endl << endl;
}
//destructor funciton
Triangle::~Triangle()
{
}
