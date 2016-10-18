#include<iostream>
#include<iomanip>
#include<vector>
#include<cstring>
#include"Package_JunjieFeng.h"
#include"TwoDayPackage_JunjieFeng.h"
#include"OvernightPackage_JunjieFeng.h"
using namespace std;

void Display(Package *BasePackage)
{
	static int package_index = 1;//count the package number
	cout << "Package " << package_index++<<endl<<endl;
	cout << "Sender :" << endl//print sender
		<< BasePackage->getsendername() << endl//print sender name
		<< BasePackage->getsenderaddress() << endl//print sender address
		<< BasePackage->getsendercity() << ", " << BasePackage->getsenderstate() << " " << BasePackage->getsenderzipcode() << endl << endl;//print sender address
	cout<<"Recipient :"<<endl//print recipient
		<< BasePackage->getrecipientname() << endl//print recipient name
		<< BasePackage->getrecipientaddress() << endl//print recipient address
		<< BasePackage->getrecipientcity() << ", " << BasePackage->getrecipientstate() << " " << BasePackage->getrecipientzipcode() << endl << endl;//print recipient address
	cout << "Weight of package : " << BasePackage->getweight() << " ounces" << endl//print package weight
		<< "Type of delivery : " << BasePackage->type_name() << endl//print the delivery type name
		<< "Cost of package : $" << BasePackage->calculateCost() << endl << endl;//print the cost of the package
}