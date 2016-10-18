#ifndef CIRCLE_H
#define CIRCLE_H
#include"TwoDimensionalShape.h"
class Circle :public TwoDimensionalShape
{
public:
	Circle(float, float, float);//constructor
	void set(float, float, float);//set all value
	float getArea();//calculate the circlearea
	virtual void print();//print
	~Circle();//destructor
private:
};
#endif
