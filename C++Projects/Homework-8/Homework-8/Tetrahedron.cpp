#include "Tetrahedron.h"
#include<iostream>
#include<math.h>
using namespace std;
//constructor fucntion
Tetrahedron::Tetrahedron(float xValue, float yValue, float zValue, float lengthValue)
	:ThreeDimensionalShape(xValue,yValue,zValue,lengthValue)
{
}
//set value function
void Tetrahedron::set(float xValue, float yValue, float zValue, float lengthValue)
{
	setx(xValue);
	sety(yValue);
	setz(zValue);
	setRorL(lengthValue);
}
////calculate area fucntion
float Tetrahedron::getSurfaceArea()
{
	return (float)sqrt(3)*getRorL()*getRorL();//calculate the area
}
//calculate volume fucntion
float Tetrahedron::getVolume()
{
	return (float)sqrt(2) / 12 * getRorL()*getRorL()*getRorL();//calculate the volume
}
//tetrahedron print function
void Tetrahedron::print()
{
	cout << "The regular tetrahedron with edge length " << getRorL() << " that is located at : ";
	ThreeDimensionalShape::print();
	cout << " has :" << endl
		<< "A surface area of : " << getSurfaceArea() << endl
		<< "A volume of : " << getVolume() << endl << endl;
}
//destructor function
Tetrahedron::~Tetrahedron()
{
}
