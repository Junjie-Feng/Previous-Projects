#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H
#include"Package_JunjieFeng.h"
class OverNightPackage:public Package
{
public:
	OverNightPackage(char *, char *, char *, char *, char*, char *, char *, char *, char *, char*, float, float = 0.50, float = 5.00);
	//constructor, default cost per ounce is $0.5, flat fee for overnight package is $5.00
	double calculateCost();//calculate the ovenight package cost
	void setflatfee(float);//set the additional flat fee for this package
	float getflatfee();//get the falt fee
	char * type_name();//type name as ovenight delivery
	~OverNightPackage();//destructor
private:
	float flat_fee;//float point number store the flat fee 
};
#endif
