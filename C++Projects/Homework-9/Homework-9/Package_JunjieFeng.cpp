#include "Package_JunjieFeng.h"
#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

//constructor
Package::Package(char *name1, char *address1, char *city1, char *state1, char *zipcode1, char *name2, char *address2, char *city2, char *state2, char *zipcode2, float weightvalue, float costvalue)
{
	//set all of the package information
	setsender(name1, address1, city1, state1, zipcode1);
	setrecipient(name2, address2, city2, state2, zipcode2);
	setweight(weightvalue);
	setcostperounce(costvalue);
}
//calculate cost function
double Package::calculateCost()
{
	return cost_per_ounce*weight;
}
//set sender information fucntion
void Package::setsender(char *name1, char *address1, char *city1, char *state1, char *zip1)
{
	sender_name = name1;
	sender_address = address1;
	sender_city = city1;
	sender_state = state1;
	sender_ZIPcode = zip1;
}
//set recipient information function
void Package::setrecipient(char *name2, char *address2, char *city2, char *state2, char *zip2)
{
	recipient_name = name2;
	recipient_address = address2;
	recipient_city = city2;
	recipient_state = state2;
	recipient_ZIPcode = zip2;
}
//set weight funciton
void Package::setweight(float weightvalue)
{
	weight = weightvalue > 0 ? weightvalue : 0;
}
//set cost per ounce function
void Package::setcostperounce(float cost)
{
	cost_per_ounce = cost > 0 ? cost : 0;
}
//all the get information functions
char *Package::getsendername()
{
	return sender_name;
}

char * Package::getsenderaddress()
{
	return sender_address;
}

char * Package::getsendercity()
{
	return sender_city;
}

char * Package::getsenderstate()
{
	return sender_state;
}

char * Package::getsenderzipcode()
{
	return sender_ZIPcode;
}

char * Package::getrecipientname()
{
	return recipient_name;
}

char * Package::getrecipientaddress()
{
	return recipient_address;
}

char * Package::getrecipientcity()
{
	return recipient_city;
}

char * Package::getrecipientstate()
{
	return recipient_state;
}

char * Package::getrecipientzipcode()
{
	return recipient_ZIPcode;
}

float Package::getweight()
{
	return weight;
}

float Package::getcostperounce()
{
	return cost_per_ounce;
}
//type name function
char * Package::type_name()
{
	return "Regular Delivery";
}
//destructor
Package::~Package()
{
}


