#include "ThreeDimensionalShape.h"
#include<iostream>
using namespace std;
//constructor fucntion
ThreeDimensionalShape::ThreeDimensionalShape(float xValue, float yValue, float zValue,float RorLvalue)
	:Shape(xValue,yValue)
{
	setz(zValue);
	setRorL(RorLvalue);
}
//set z value function
void ThreeDimensionalShape::setz(float zValue)
{
	z = zValue;
}
//get z value fucntion
float ThreeDimensionalShape::getz()
{
	return z;
}
//set radius or length value fucntion
void ThreeDimensionalShape::setRorL(float RorL_value)
{
	RadiusorLength = RorL_value;
}
//get radius or length value function
float ThreeDimensionalShape::getRorL()
{
	return RadiusorLength;
}
//print x&y&z coordinate function
void ThreeDimensionalShape::print()
{
	cout << '[' << getx() << ", " << gety() << ", " << getz() << ']';
}
//destructor function
ThreeDimensionalShape::~ThreeDimensionalShape()
{
}
