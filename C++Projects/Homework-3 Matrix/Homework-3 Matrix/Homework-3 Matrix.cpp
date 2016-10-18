// Name : Junjie Feng
// Course : 16:332:503:01 , Programming Financial
// Title : Homework 3 matrix 
//Date of Submission: 09/24/2015

#include<iostream>
#include <iomanip>
using namespace std;

void Inputting(int, float[][100], float[][100], int &, int &, int &, int &);
void Displaying(int, const float[][100], int, int);
void Addition(const float[][100], const float[][100], float[][100], int, int);
void Subtraction(const float[][100], const float[][100], float[][100], int, int);
void Multiplication(const float[][100], const float[][100], float[][100], int, int, int, int);
void Determinant(const float[][100], float[][100]);
void Transpose(const float[][100], float[][100], int, int);
void Inverse(const float[][100], float[][100], int, int);
int main()
{
	int choice = 0;
	while (1)//in order to come back to the menu after finishing one of the function
	{
		int row1, column1, row2, column2;
		float arrary1[100][100] = { 0 };
		float arrary2[100][100] = { 0 };
		float arrary3[100][100] = { 0 };
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
		cout << "Enter your choice : " << endl;//prompt
		cin >> choice;
		switch (choice)//in order to choose the right function
		{
		case 1://addition
			Inputting(choice, arrary1, arrary2, row1, column1, row2, column2);
			if (row1 == row2&&column1 == column2)
			{
				Addition(arrary1, arrary2, arrary3, row1, column1);
				Displaying(choice, arrary3, row1, column1);
			}
			else
				cout << "The operation is not supported." << endl;
			break;
		case 2://subtract
			Inputting(choice, arrary1, arrary2, row1, column1, row2, column2);
			if (row1 == row2&&column1 == column2)
			{
				Subtraction(arrary1, arrary2, arrary3, row1, column1);
				Displaying(choice, arrary3, row1, column1);
			}
			else
				cout << "The operation is not supported." << endl;
			break;
		case 3://multiplication
			Inputting(choice, arrary1, arrary2, row1, column1, row2, column2);
			if (column1 == row2)
			{
				Multiplication(arrary1, arrary2, arrary3, row1, column1, row2, column2);
				Displaying(choice, arrary3, row1, column2);
			}
			else
				cout << "The operation is not supported." << endl;
			break;
		case 4://determinant
			cout << "This program could only support the fixed matrix size of 3*3." << endl;
			Inputting(choice, arrary1, arrary2, row1, column1, row2, column2);
			if (row1 == 3 && column1 == 3)
			{
				Determinant(arrary1, arrary3);
				Displaying(choice, arrary3, row1, column1);
			}
			else
				cout << "The operation is not supported." << endl;
			break;
		case 5://transpose
			Inputting(choice, arrary1, arrary2, row1, column1, row2, column2);
			Transpose(arrary1, arrary3, row1, column1);
			Displaying(choice, arrary3, column1, row1);
			break;
		case 6://inverse
			cout << "This program could only support the fixed matrix size of 3*3." << endl;
			Inputting(choice, arrary1, arrary2, row1, column1, row2, column2);
			if (row1 == 3 && column1 == 3)
			{
				Determinant(arrary1, arrary3);
				if (arrary3[0][0] != 0)//check out whether the determinant of the matrix equal to zero
				{
					Inverse(arrary1, arrary3, row1, column1);
					Displaying(choice, arrary3, row1, column1);
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
void Inputting(int choice, float arrary1[][100], float arrary2[][100], int &row1, int &column1, int &row2, int &column2)
{
	int i, j, out = 0;
	if (choice == 1 || choice == 2 || choice == 3)//add&sub&multi need 2 input matrixs
	{
		cout << "Please enter the row number of the 1st matrix : ";//prompt
		cin >> row1;
		cout << "Please enter the column number of the 1st matrix : ";
		cin >> column1;
		cout << "Please enter the elements of the 1st matrix : " << endl;
		for (i = 0; i <= row1 - 1; i++)
		{
			for (j = 0; j <= column1 - 1; j++)
				cin >> arrary1[i][j];
		}
		Displaying(out, arrary1, row1, column1);//dispaly the input matrix
		cout << "Please enter the row number of the 2nd matrix : ";//prompt
		cin >> row2;
		cout << "Please enter the column number of the 2nd matrix : ";
		cin >> column2;
		cout << "Please enter the elements of the 2nd matrix : " << endl;
		for (i = 0; i <= row2 - 1; i++)
		{
			for (j = 0; j <= column2 - 1; j++)
				cin >> arrary2[i][j];
		}
		Displaying(out, arrary2, row2, column2); //dispaly the input matrix
	}
	else if (choice == 4 || choice == 5 || choice == 6)//det&inverse//transpose need 1 input matrix
	{
		cout << "Please enter the row number of the matrix : ";//prompt
		cin >> row1;
		cout << "Please enter the column number of the matrix : ";
		cin >> column1;
		cout << "Please enter the elements of the matrix : " << endl;
		for (i = 0; i <= row1 - 1; i++)
		{
			for (j = 0; j <= column1 - 1; j++)
				cin >> arrary1[i][j];
		}
		Displaying(out, arrary1, row1, column1); //dispaly the input matrix
	}
}
//outputting function
void Displaying(int choice, const float arrary3[][100], int row, int column)
{
	int i, j;
	if (choice == 1 || choice == 2 || choice == 3 || choice == 5 || choice == 6)//except the determinant, all of other function get a matrix as the result
	{
		cout << "This is the result of your choice: " << endl;
		for (i = 0; i < row; i++)
		{
			for (j = 0; j < column; j++)
				cout << setw(10) <<setprecision(3)<< arrary3[i][j];
			cout << endl;
		}
		cout << endl;
	}
	else if (choice == 4)//the result of the determinant function is a floating number.
	{
		cout << "The determinant of your matrix is : " << arrary3[0][0] << endl << endl;
	}
	else//display the input matrix
	{
		cout << "Your input is : " << endl;
		for (i = 0; i < row; i++)
		{
			for (j = 0; j < column; j++)
				cout << setw(10) << setprecision (3)<< arrary3[i][j];
			cout << endl;
		}
	}
}
//addition function
void Addition(const float arrary1[][100], const float arrary2[][100], float arrary3[][100], int row1, int column1)
{
	int i, j;
	for (i = 0; i < row1; i++)
	{
		for (j = 0; j < column1; j++)
			arrary3[i][j] = arrary1[i][j] + arrary2[i][j];
	}
}
//subtraction function
void Subtraction(const float arrary1[][100], const float arrary2[][100], float arrary3[][100], int row1, int column1)
{
	int i, j;
	for (i = 0; i < row1; i++)
	{
		for (j = 0; j < column1; j++)
			arrary3[i][j] = arrary1[i][j] - arrary2[i][j];
	}
}
//multiplication function
void Multiplication(const float arrary1[][100], const float arrary2[][100], float arrary3[][100], int row1, int column1, int row2, int column2)
{
	int i, j, m, n;
	for (i = 0; i < row1; i++)
	{
		for (j = 0; j < column2; j++)
		{
			for (m = 0, n = 0; m < row2; m++, n++)
			{
				arrary3[i][j] += arrary1[i][m] * arrary2[n][j];
			}
		}
	}
}
//determinant functiuon, only used for 3*3 matrix
void Determinant(const float arrary[][100], float arrary3[][100])
{
	arrary3[0][0] = arrary[0][0] * (arrary[1][1] * arrary[2][2] - arrary[1][2] * arrary[2][1]) - arrary[0][1] * (arrary[1][0] * arrary[2][2] - arrary[1][2] * arrary[2][0]) + arrary[0][2] * (arrary[1][0] * arrary[2][1] - arrary[1][1] * arrary[2][0]);
}
//transpose function
void Transpose(const float arrary[][100], float arrary3[][100], int row, int column)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			arrary3[j][i] = arrary[i][j];
		}
	}
}
//inverse function, only used for 3*3 matrix
void Inverse(const float arrary[][100], float arrary3[][100], int row, int column)
{
	int i, j;
	float det;
	Determinant(arrary, arrary3);
	if (arrary3[0][0] == 0)
		cout << "The operation is not supported. Because the determanint of the matrix should not equal to zero.";
	else
	{
		det = arrary3[0][0];
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
				arrary3[i][j] = static_cast<float> (arrary[(j + 1) % 3][(i + 1) % 3] * arrary[(j + 2) % 3][(i + 2) % 3] - arrary[(j + 1) % 3][(i + 2) % 3] * arrary[(j + 2) % 3][(i + 1) % 3]) / det;
		}
	}
}