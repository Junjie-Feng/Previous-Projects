#include "TwoDimensionalShape.h"
#include<iostream>
using namespace std;
//constructor fucntion
TwoDimensionalShape::TwoDimensionalShape(float xValue, float yValue, float RorLvalue)
	:Shape(xValue,yValue)
{
	setRorL(RorLvalue);
}
//set radius or length value function
void TwoDimensionalShape::setRorL(float RorL_value)
{
	RadiusorLength = RorL_value;
}
//gete radius or length value fucntion
float TwoDimensionalShape::getRorL()
{
	return RadiusorLength;
}
//print x&y coordinate function
void TwoDimensionalShape::print()
{
	cout << '[' << getx() << ", " << gety() << ']';
}
//destructor function
TwoDimensionalShape::~TwoDimensionalShape()
{
}
