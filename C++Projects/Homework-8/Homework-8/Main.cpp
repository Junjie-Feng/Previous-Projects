////Name : Junjie Feng
//Course : Programming Financial
//Title : Homewrok-8
//Date of Submission : 10/29/2015
#include<iostream>
#include<iomanip>
#include<math.h>

#include"Shape.h"
#include"TwoDimensionalShape.h"
#include"ThreeDimensionalShape.h"
#include"Circle.h"
#include"Triangle.h"
#include"Sphere.h"
#include"Tetrahedron.h"//include all the header files

using namespace std;
int main()
{
	cout << setprecision(6);//set prescision
	Circle circle(0, 0, 0);
	Triangle triangle(0, 0, 0);
	Sphere sphere(0, 0, 0, 0);
	Tetrahedron tetrahedron(0, 0, 0, 0);//creat object
	int choice;
	do
	{
		float x = 0, y = 0, z = 0,radius=0, length=0;
		cout << "Please choose a shape or 0 to exit:" << endl
			<< "1: Circle" << endl
			<< "2: Triangle" << endl
			<< "3: Sphere" << endl
			<< "4: Regular Tetrahedron" << endl
			<< "0: Exit" << endl;
		cout << "Enter your choice : " ;//prompt
		cin >> choice;
		switch (choice)
		{
		case 1://circle
			cout << "You have choosen the circle." << endl
				<< "Please enter the center of the circle (x-coordinate and then the y-coordinate) :" ;
			cin >> x >> y;
			cout << "Please enter the radius of the circle : " << endl;
			cin >> radius;
			circle.set(x, y, radius);//set value
			circle.print();//print 
			break;
		case 2://triangle
			cout << "You have choosen the triangle." << endl
				<< "Please enter the center of the triangle (x-coordinate and then the y-coordinate) :";
			cin >> x >> y;
			cout << "Please enter the length of the triangle : " << endl;
			cin >> length;
			triangle.set(x, y, length);//set value
			triangle.print();//print 
			break;
		case 3://sphere
			cout << "You have choosen the sphere." << endl
				<< "Please enter the center of the sphere (x-coordinate, y-coordinate, then z-coordinate) :";
			cin >> x >> y >> z;
			cout << "Please enter the radius of the sphere : " << endl;
			cin >> length;
			sphere.set(x, y, z, length);//set value
			sphere.print();//print 
			break;
		case 4://regular tetrahedron
			cout << "You have choosen the regular tetrahedron." << endl
				<< "Please enter the center of the regular tetrahedron (x-coordinate, y-coordinate, then z-coordinate) :";
			cin >> x >> y >> z;
			cout << "Please enter the edge length of the regular tetrahedron : " << endl;
			cin >> length;
			tetrahedron.set(x, y, z, length);//set value
			tetrahedron.print();//print 
			break;
		case 0://exit
			return 0;
		default:
			cout << "You need to enter a digit from 0 to 4." << endl;
		}
	} while (1);//in order to come back to the menu after finishing one of the function
}