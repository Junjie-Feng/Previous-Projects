#ifndef TETRAHEDRON_H
#define TETRAHEDRON_H
#include"ThreeDimensionalShape.h"
class Tetrahedron :public ThreeDimensionalShape
{
public:
	Tetrahedron(float, float, float, float);//constructor
	void set(float,float,float,float);//set all value
	float getSurfaceArea();//calculate the tetrahedron surface value
	float getVolume();//calculate the tetrahedron volume
	virtual void print() ;//print
	~Tetrahedron();//destructor
private:
};
#endif
