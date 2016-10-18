#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H
#include "Package_JunjieFeng.h"
class TwoDayPackage:public Package
{
public:
	TwoDayPackage(char *, char *, char *, char *, char*, char *, char *, char *, char *, char*, float, float = 0.5, float = 2.00);
	//constructor, default cost per ounce is $0.5, flat fee for two day package is $2.00
	double calculateCost();//calculate the two day package cost
	void setflatfee(float);//set the additional flat fee for this package
	float getflatfee();//get the falt fee
	char * type_name();//type name as two day delivery
	~TwoDayPackage();//destructor
private:
	float flat_fee;//float point number store the flat fee 
};
#endif
