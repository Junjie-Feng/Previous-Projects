#ifndef TRIANGLE_H
#define TRIANGLE_H
#include"TwoDimensionalShape.h"
class Triangle :public TwoDimensionalShape
{
public:
	Triangle(float, float, float);//constructor
	void set(float, float, float);//set all value
	float getArea(); //calculate the triangle value
	virtual void print() ;//print
	~Triangle();//destructor
private:
};
#endif
