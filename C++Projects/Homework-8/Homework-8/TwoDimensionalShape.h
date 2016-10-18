#ifndef TWODIMENSIONALSHAPE_H
#define TWODIMENSIONALSHAPE_H
#include"Shape.h"
class TwoDimensionalShape : public Shape
{
public:
	TwoDimensionalShape(float, float,float);//constructor
	void setRorL(float); //set radius value or set length value 
	float getRorL(); // get radius value or set length value 
	virtual void print(); //print the x&y coordinate
	~TwoDimensionalShape();//destructor
private:
	float RadiusorLength;//keep the value of circle's radius or triangle's length
};
#endif