#ifndef SHAPE_H
#define SHAPE_H
const float pi = 3.1415926f;
class Shape
{
public:
	Shape(float, float);//constructor
	void setx(float);//set x-coordinate value
	void sety(float);//set y-coordinate value
	float getx();//get x-coordinate value
	float gety();//get y-coordinate value
	~Shape();//destructor
private:
	float x;
	float y;
};

#endif
