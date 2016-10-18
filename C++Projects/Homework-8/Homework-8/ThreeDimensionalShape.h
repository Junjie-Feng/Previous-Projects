#ifndef THREEDIMENSIONALSHAPE_H
#define THREEDIMENSIONALSHAPE_H
#include"Shape.h"
class ThreeDimensionalShape : public Shape
{
public:
	ThreeDimensionalShape(float, float, float,float);//constructor
	void setz(float);//set z-coordinate value
	float getz();//get z-coordinate value
	void setRorL(float); //set radius value or set length value 
	float getRorL();// get radius value or set length value 
	virtual void print();//print the x&y&z coordinate
	~ThreeDimensionalShape();//destructor
private:
	float z;//z-coordinate value
	float RadiusorLength;//keep the value of sphere's radius or tetrahedron's length
};
#endif