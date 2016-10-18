#ifndef SPHERE_H
#define SPHERE_H
#include"ThreeDimensionalShape.h"
class Sphere :public ThreeDimensionalShape
{
public:
	Sphere(float, float, float, float);//constructor
	float getSurfaceArea();//caculate the sphere surface area
	void set(float, float, float, float);//set all value
	float getVolume();//calculate the sphere volume
	virtual void print();//print
	~Sphere();//destructor
private:
};
#endif
