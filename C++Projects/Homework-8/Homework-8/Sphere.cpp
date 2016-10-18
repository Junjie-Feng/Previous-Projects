#include "Sphere.h"
#include<iostream>
using namespace std;
//constructor function
Sphere::Sphere(float xValue, float yValue, float zValue, float radiusValue)
	:ThreeDimensionalShape(xValue,yValue,zValue,radiusValue)
{
}
//calculate area fucntion
float Sphere::getSurfaceArea()
{
	return 4*pi*getRorL()*getRorL();//calculate the area
}
//set value fucntion
void Sphere::set(float xValue, float yValue, float zValue, float radiusValue)
{
	setx(xValue);
	sety(yValue);
	setz(zValue);
	setRorL(radiusValue);
}
//calculate volume fucntion
float Sphere::getVolume()
{
	return 4*pi*getRorL()*getRorL()*getRorL()/3;//calculate the volume
}
//sphere print function
void Sphere::print()
{
	cout << "The sphere with radius " << getRorL() << " that is located at : ";
	ThreeDimensionalShape::print();
	cout << " has : " << endl
		<< "A surface area of : " << getSurfaceArea() << endl 
		<< "A volume of : " << getVolume() << endl << endl;
}
//destructor function
Sphere::~Sphere()
{
}
