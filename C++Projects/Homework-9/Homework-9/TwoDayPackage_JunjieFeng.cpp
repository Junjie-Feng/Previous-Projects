#include "TwoDayPackage_JunjieFeng.h"
//constructor
TwoDayPackage::TwoDayPackage(char *name1, char *address1, char *city1, char *state1, char *zip1, char *name2, char *address2, char *city2, char *state2, char *zip2, float weightvalue, float costvalue, float flat)
	:Package(name1, address1, city1, state1, zip1, name2, address2, city2, state2, zip2, weightvalue, costvalue)
{
	setflatfee(flat);//set flat fee
}
//calculate cost function
double TwoDayPackage::calculateCost()
{
	return (flat_fee+cost_per_ounce)*weight;
}
//set flat fee function
void TwoDayPackage::setflatfee(float flat)
{
	flat_fee = flat > 0 ? flat : 0;
}
//get flat fee funciton
float TwoDayPackage::getflatfee()
{
	return flat_fee;
}
//type name function
char * TwoDayPackage::type_name()
{
	return "Two Day Delivery";
}
//destructor
TwoDayPackage::~TwoDayPackage()
{
}


