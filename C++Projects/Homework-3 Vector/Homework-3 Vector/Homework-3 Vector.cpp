// Name : Junjie Feng
// Course : 16:332:503:01 , Programming Financial
// Title : Homework 3 vector 
//Date of Submission: 09/24/2015

#include<iostream>
#include <iomanip>
#include<vector>
using namespace std;

void Inputting(int, vector<vector<float>>&, vector<vector<float>>&, int &, int &, int&, int &);
void Displaying(int, const vector<vector<float>>&, int, int);
void Addition(const vector<vector<float>>&, const vector<vector<float>>&, vector<vector<float>>&, int, int);
void Subtraction(const vector<vector<float>>&, const vector<vector<float>>&, vector<vector<float>>&, int, int);
void Multiplication(const vector<vector<float>>&, const vector<vector<float>>&, vector<vector<float>>&, int, int, int, int);
void Determinant(const vector<vector<float>>&, vector<vector<float>>&);
void Transpose(const vector<vector<float>>&, vector<vector<float>>&, int, int);
void Inverse(const vector<vector<float>>&, vector<vector<float>>&, int, int);
int main()
{
	int choice = 0;
	while (1)//in order to come back to the menu after finishing one of the function
	{
		int row1, column1, row2, column2;
		vector<vector<float>>vector1;
		vector<vector<float>>vector2;
		vector<vector<float>>vector3;
		//display the menu
		cout << "******Menu******" << endl
			<< "Choice 1: Addition" << endl
			<< "Choice 2: Subtraction" << endl
			<< "Choice 3: Multiplication" << endl
			<< "Choice 4: Determinant" << endl
			<< "Choice 5: Transpose" << endl
			<< "Choice 6: Inverse" << endl
			<< "Choice 7: Quit" << endl;
		if (choice != 0)
			cout << "What is your additional demand? please continue." << endl;
		cout << "Enter your choice: " << endl;//prompt
		cin >> choice;
		switch (choice)//in order to choose the right function
		{
		case 1://addition
			Inputting(choice, vector1, vector2, row1, column1, row2, column2);
			if (row1 == row2&&column1 == column2)
			{
				Addition(vector1, vector2, vector3, row1, column1);
				Displaying(choice, vector3, row1, column1);
			}
			else
				cout << "The operation is not supported." << endl;
			break;
		case 2://subtract
			Inputting(choice, vector1, vector2, row1, column1, row2, column2);
			if (row1 == row2&&column1 == column2)
			{
				Subtraction(vector1, vector2, vector3, row1, column1);
				Displaying(choice, vector3, row1, column1);
			}
			else
				cout << "The operation is not supported." << endl;
			break;
		case 3://multiplication
			Inputting(choice, vector1, vector2, row1, column1, row2, column2);
			if (column1 == row2)
			{
				Multiplication(vector1, vector2, vector3, row1, column1, row2, column2);
				Displaying(choice, vector3, row1, column2);
			}
			else
				cout << "The operation is not supported." << endl;
			break;
		case 4://determinant
			cout << "This program could only support the fixed matrix size of 3*3." << endl;
			Inputting(choice, vector1, vector2, row1, column1, row2, column2);
			if (row1 == 3 && column1 == 3)
			{
				Determinant(vector1, vector3);
				Displaying(choice, vector3, row1, column1);
			}
			else
				cout << "The operation is not supported." << endl;
			break;
		case 5://transpose
			Inputting(choice, vector1, vector2, row1, column1, row2, column2);
			Transpose(vector1, vector3, row1, column1);
			Displaying(choice, vector3, column1, row1);
			break;
		case 6://inverse
			cout << "This program could only support the fixed matrix size of 3*3." << endl;
			Inputting(choice, vector1, vector2, row1, column1, row2, column2);
			if (row1 == 3 && column1 == 3)
			{
				Determinant(vector1, vector3);
				if (vector3[0][0] != 0)//check out whether the determinant of the matrix equal to zero
				{
					Inverse(vector1, vector3, row1, column1);
					Displaying(choice, vector3, row1, column1);
				}
				else
					cout << "The operation is not supported. Because the determanint of the matrix should not equal to zero." << endl;
			}
			else
				cout << "The operation is not supported." << endl;
			break;
		case 7://exit the program
			cout << "Thanks for your time!" << endl;
			return 0;//indicate the successful termination of the program
			break;
		default:
			cout << "Should never be here!" << endl;
		}
	}
}//end main
 //inputting function
void Inputting(int choice, vector<vector<float>>&vector1, vector<vector<float>>&vector2, int &row1, int &column1, int &row2, int &column2)
{
	int i, j, out = 0;
	if (choice == 1 || choice == 2 || choice == 3)//add&sub&multi need 2 input matrixs
	{
		cout << "Please enter the row number of the 1st matrix : ";//prompt
		cin >> row1;
		cout << "Please enter the column number of the 1st matrix : ";
		cin >> column1;
		cout << "Please enter the value of elements of the 1st matrix :" << endl;
		for (i = 0; i <= row1 - 1; i++)
		{
			vector1.push_back(vector<float>(column1));
			for (j = 0; j <= column1 - 1; j++)
				cin >> vector1[i][j];
		}
		Displaying(out, vector1, row1, column1);//dispaly the input matrix
		cout << "Please enter the row number of the 2nd matrix : ";//prompt
		cin >> row2;
		cout << "Please enter the column number of the 2nd matrix : ";
		cin >> column2;
		cout << "Please enter the elements of the 2nd matrix : " << endl;
		for (i = 0; i <= row2 - 1; i++)
		{
			vector2.push_back(vector<float>(column2));
			for (j = 0; j <= column2 - 1; j++)
				cin >> vector2[i][j];
		}
		Displaying(out, vector2, row2, column2);//dispaly the input matrix
	}
	else if (choice == 4 || choice == 5 || choice == 6)//det&inverse//transpose need 1 input matrix
	{
		int out = -1;
		cout << "Please enter the row number of the matrix : ";//prompt
		cin >> row1;
		cout << "Please enter the column number of the matrix : ";
		cin >> column1;
		cout << "Please enter the elements of the matrix : " << endl;
		for (i = 0; i <= row1 - 1; i++)
		{
			vector1.push_back(vector<float>(column1));
			for (j = 0; j <= column1 - 1; j++)
				cin >> vector1[i][j];
		}
		Displaying(out, vector1, row1, column1);//dispaly the input matrix
	}
}
//outputting function
void Displaying(int choice, const vector<vector<float>>&vector3, int row, int column)
{
	int i, j;
	if (choice == 1 || choice == 2 || choice == 3 || choice == 5 || choice == 6)//except the determinant, all of other function get a matrix as the result
	{
		cout << "This is the result of your choice: " << endl;
		for (i = 0; i < row; i++)
		{
			for (j = 0; j < column; j++)
				cout << setw(10) << setprecision(3) << vector3[i][j];
			cout << endl;
		}
		cout << endl;
	}
	else if (choice == 4)//the result of the determinant function is a floating number.
	{
		cout << "The determinant of your matrix is : " << vector3[0][0] << endl << endl;
	}
	else//display the input matrix
	{
		cout << "Your input is : " << endl;
		for (i = 0; i < row; i++)
		{
			for (j = 0; j < column; j++)
				cout << setw(10) << setprecision(7)<< vector3[i][j];
			cout << endl;
		}
	}
}
//addition function
void Addition(const vector<vector<float>>&vector1, const vector<vector<float>>&vector2, vector<vector<float>>&vector3, int row1, int column1)
{
	int i, j;
	for (i = 0; i < row1; i++)
	{
		vector3.push_back(vector<float>(column1));
		for (j = 0; j < column1; j++)
			vector3[i][j] = vector1[i][j] + vector2[i][j];
	}
}
//subtraction function
void Subtraction(const vector<vector<float>>&vector1, const vector<vector<float>>&vector2, vector<vector<float>>&vector3, int row1, int column1)
{
	int i, j;
	for (i = 0; i < row1; i++)
	{
		vector3.push_back(vector<float>(column1));
		for (j = 0; j < column1; j++)
			vector3[i][j] = vector1[i][j] - vector2[i][j];
	}
}
//multiplication function
void Multiplication(const vector<vector<float>>&vector1, const vector<vector<float>>&vector2, vector<vector<float>>&vector3, int row1, int column1, int row2, int column2)
{
	int i, j, m, n;
	for (i = 0; i < row1; i++)
	{
		vector3.push_back(vector<float>(column2));
		for (j = 0; j < column2; j++)
		{
			for (m = 0, n = 0; m < row2; m++, n++)
			{
				vector3[i][j] += vector1[i][m] * vector2[n][j];
			}
		}
	}
}
//determinant functiuon, only used for 3*3 matrix
void Determinant(const vector<vector<float>>&vector1, vector<vector<float>>&vector3)
{
	float det;
	vector3.push_back(vector<float>(3));
	det = vector1[0][0] * (vector1[1][1] * vector1[2][2] - vector1[1][2] * vector1[2][1]) - vector1[0][1] * (vector1[1][0] * vector1[2][2] - vector1[1][2] * vector1[2][0]) + vector1[0][2] * (vector1[1][0] * vector1[2][1] - vector1[1][1] * vector1[2][0]);
	vector3[0][0] = det;
}
//transpose function
void Transpose(const vector<vector<float>>&vector1, vector<vector<float>>&vector3, int row, int column)
{
	int i, j;
	for (i = 0; i < column; i++)
	{
		vector3.push_back(vector<float>(row));
		for (j = 0; j < row; j++)
		{
			vector3[i][j] = vector1[j][i];
		}
	}
}
//inverse function, only used for 3*3 matrix
void Inverse(const vector<vector<float>>&vector1, vector<vector<float>>&vector3, int row, int column)
{
	int i, j;
	float det;
	Determinant(vector1, vector3);	
	det = vector3[0][0];
	for (i = 0; i < 3; i++)
	{
		vector3.push_back(vector<float>(row));
		for (j = 0; j < 3; j++)
			vector3[i][j] = static_cast<float> (vector1[(j + 1) % 3][(i + 1) % 3] * vector1[(j + 2) % 3][(i + 2) % 3] - vector1[(j + 1) % 3][(i + 2) % 3] * vector1[(j + 2) % 3][(i + 1) % 3]) / det;
	}
}
