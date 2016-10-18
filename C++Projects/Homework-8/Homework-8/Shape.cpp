#include "Shape.h"
#include<iostream>
using namespace std;
//constructor fucntion
Shape::Shape(float xValue, float yValue)
{
	setx(xValue);
	sety(yValue);
}
//set x value function
void Shape::setx(float xValue)
{
	x = xValue;
}
//set y value function
void Shape::sety(float yValue)
{
	y = yValue;
}
//get x function
float Shape::getx()
{
	return x;
}
//get y function
float Shape::gety()
{
	return y;
}
//destructor fucntion
Shape::~Shape()
{
}
