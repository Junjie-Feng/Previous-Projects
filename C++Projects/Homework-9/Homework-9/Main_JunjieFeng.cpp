//Name : Junjie Feng
//Course : Programming Financial
//Title : Homework-9
//Date of Submission : 11/13/2015

#include<iostream>
#include<iomanip>
#include<vector>
#include<cstring>
#include"Package_JunjieFeng.h"
#include"TwoDayPackage_JunjieFeng.h"
#include"OvernightPackage_JunjieFeng.h"

using namespace std;
void Display( Package *);
int main()
{
	
	Package regularpackage("John Smith", "1 Davidson Road", "Piscataway", "NJ", "08854",
		"Tom Smith", "2 Davidson Road", "Piscataway", "NJ", "08854", 10);
	//creat a regular_package object
	//10 is weight in ounces

	TwoDayPackage twodaypackage("Mary Smith", "3 Davidson Road", "Piscataway", "NJ", "08854",
		"Jennifer Smith", "4 Davidson Road", "Piscataway", "NJ", "08854", 5);
	//creat a two_day_package object
	//5 is weight in ounces

	OverNightPackage overnightpackage("John Smith", "1 Davidson Road", "Piscataway", "NJ", "08854",
		"Mary Smith", "3 Davidson Road", "Piscataway", "NJ", "08854", 2);
	//creat a ovenight_package object
	//2 is weight in ounces

	TwoDayPackage twodaypackage2("Ke Wang", "10 River Road", "New York", "NY", "10044",
		"Junjie Feng", "575 Easton Ave", "Somerset", "NJ", "08873", 20);
	//creat a two_day_package objectHP
	//20 is weight in ounces
	
	cout << "Package delivery services program" << endl << endl << setprecision(2) << fixed
		<< "Cost per ounce for a package: $" << regularpackage.getcostperounce() << "/ounce" << endl
		<< "Additional cost for two day delivery: $" << twodaypackage.getflatfee() << "/ounce" << endl
		<< "Additional cost for overnight delivery: $" << overnightpackage.getflatfee() << "/ounce" << endl << endl;//menu

	vector<Package *>PackageVector;
	PackageVector.push_back(&regularpackage); //aim PackageVector[0] at class Package object
	PackageVector.push_back(&twodaypackage);//aim PackageVector[1] at derived-class TwoDayPackage object
	PackageVector.push_back(&overnightpackage);//aim PackageVector[2] at derived-class OvernightPackage object
	PackageVector.push_back(&twodaypackage2);//aim PackageVector[3] at derived-class TwoDayPackage object
	
	static double total_cost = 0;//initialize the total cost of all packages
	
	// loop through PackageVector and call Dispaly funciton 
	//to print the sender and recipient name, address and package information of each object using dynamic binding
	for (unsigned int i = 0; i < PackageVector.size(); i++)
	{
		Display(PackageVector[i]);//call Display
		total_cost += PackageVector[i]->calculateCost();//keep track on the total cost of all packages
	}
	cout << "Total cost of all the packages : $" << total_cost<<endl;//print the total cost
	return 0;//indicate the success of main function
}