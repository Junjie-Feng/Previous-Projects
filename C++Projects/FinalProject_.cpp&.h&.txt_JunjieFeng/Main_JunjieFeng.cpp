//Title: Final Project--Account Management System
//Course: 16:332:503 Programming Financial
//Name: Junjie Feng
//Date of Submission: 12/11/2013

#include<iostream>
#include<fstream>
#include<cmath>
#include <iomanip>
#include<string>
#include<ctime>
#include"Account_JunjieFeng.h"
#include"StockNode_JunjieFeng.h"
#include"StockAccount_JunjieFeng.h"
#include"BankAccount_JunjieFeng.h"
using namespace std;

const int num_of_stock = 49;//since the number of companies will not change commonly. The number of stocks in "Result_x.txt" files is 49 

int main()
{
	//using time to creat real random number
	srand((unsigned)time(0));

	//Read the results1_txt,Store the data 
	ifstream readfile;//creat a new object of ifstream class
	string stock_symbol_1[num_of_stock], date_1;
	float  price_per_share_1[num_of_stock];
	readfile.open("Results_1.txt");
	for (int i = 0; i < num_of_stock; i++)
	{
		readfile >> *(stock_symbol_1 + i);//store the stock symbol in the array
		readfile >> *(price_per_share_1 + i);//store the price of the this stock in the same index of this array
		readfile >> date_1;
	}
	readfile.close();//close the file

	//Read the results2_txt,Store the data 
	string stock_symbol_2[num_of_stock], date_2;
	float  price_per_share_2[num_of_stock];
	readfile.open("Results_2.txt");
	for (int i = 0; i < num_of_stock; i++)
	{
		readfile >> *(stock_symbol_2 + i);//store the stock symbol in the array
		readfile >> *(price_per_share_2 + i);//store the price of the this stock in the same index of this array
		readfile >> date_2;
	}
	readfile.close();//close the file


	//Creat the object of  two classes, one stock account and one bank account
	StockAccount stock;
	BankAccount bank;

	int choice;
	bool first_time = true;
	do
	{
		if (first_time)
		{
			cout << "Welcome to the Account Management System." << endl;
			first_time = false;
		}
		bool first_stock = true, first_bank = true;
		//main menu
		cout << "Please select an account to access: " << endl
			<< "1. Stock Portfolio Account" << endl
			<< "2. Bank Account" << endl
			<< "3. Exit" << endl
			<< "Option: ";
		cin >> choice;
		if (choice > 0 && choice < 4)
		{
			switch (choice)
			{
			case 1://the case 1 is entering the stock account
				do
				{
					if (first_stock)
					{
						cout << "Stock Portfolio Account" << endl;
						first_stock = false;
					}
					//stock account menu
					cout << "Please select an option: " << endl
						<< "1. Display the price for a stock symbol" << endl
						<< "2. Display the current portfolio" << endl
						<< "3. Buy shares" << endl
						<< "4. Sell shares" << endl
						<< "5. View a graph for the portfolio value" << endl
						<< "6. View transaction history" << endl
						<< "7. Return to previous menu" << endl
						<< "Option: ";
					cin >> choice;
					if (choice > 0 && choice < 8)
					{
						switch (choice)
						{
						case 1://the case 1 is displaying the price of the user's chosen stock
							//randomly choose stock price from one of the two "Result_x.txt" file
							if ((double)rand() / RAND_MAX < 0.5)
								stock.DisplayPrice(stock_symbol_1, price_per_share_1);
							else
								stock.DisplayPrice(stock_symbol_2, price_per_share_2);
							break;
						case 2://the case 2 is displaying the portfolio value of this account
							   //randomly choose stock price from one of the two "Result_x.txt" file
							if ((double)rand() / RAND_MAX < 0.5)
								stock.DipalyPortfolio(&bank, stock_symbol_1, price_per_share_1);
							else
								stock.DipalyPortfolio(&bank, stock_symbol_2, price_per_share_2);
							break;
						case 3://the case 3 is buying shares of the chosen stock
							   //randomly choose stock price from one of the two "Result_x.txt" file
							if ((double)rand() / RAND_MAX < 0.5)
								stock.BuyShares(&bank, stock_symbol_1, price_per_share_1);
							else
								stock.BuyShares(&bank, stock_symbol_2, price_per_share_2);
							break;
						case 4://the case 4 is selling the shares of the owning stock
							//randomly choose stock price from one of the two "Result_x.txt" file
							if ((double)rand() / RAND_MAX < 0.5)
								stock.SellShares(&bank, stock_symbol_1, price_per_share_1);
							else
								stock.SellShares(&bank, stock_symbol_2, price_per_share_2);
							break;
						case 5://the case 5 is viewing the portfolio history by using matlab to plot the graph 
							stock.ViewPortfolioHistory();
							break;
						case 6://the case 6 is viewing the stock transaction history
							stock.ViewTranHistory();
							break;
						case 7://the case 7 is exiting the stock account and back to the upper menu
							break;
						default:
							break;
						}
					}
					else//if the user do not enter the number between 1 to 7, the program will give him this prompt
					{
						cout << "Please enter a number between 1 to 7." << endl;
						cin.clear();
						cin.ignore();
					}
				} while (choice != 7);
				break;
			case 2://the case 2 is entering the banck account 
				do
				{
					if (first_bank)
					{
						cout << "Bank Account" << endl;
						first_bank = false;
					}
					//bank account menu
					cout << "Please select an option: " << endl
						<< "1. View account balance" << endl
						<< "2. Deposit money" << endl
						<< "3. Withdraw money" << endl
						<< "4. Print out history" << endl
						<< "5. Return to previous menu" << endl
						<< "Option: ";
					cin >> choice;
					if (choice > 0 && choice < 6)
					{
						switch (choice)
						{
						case 1://the case 1 is viewing the current cash balance
							bank.ViewBalance();
							break;
						case 2://the case 2 is depositing money to the cash balance
							bank.Deposit();
							break;
						case 3://the case 3 is withdrawing money from the cash balance
							bank.Withdraw();
							break;
						case 4://the case 4 is viewing the all the money transaction history
							bank.ViewTranHistory();
							break;
						case 5://the case 5 is exiting the bank account and back to the upper menu.
							break;
						default:
							break;
						}
					}
					else//if the user do not enter the number between 1 to 5, the program will give him this prompt
					{
						cout << "Please enter a number between 1 to 5." << endl;
						cin.clear();
						cin.ignore();
					}
				} while (choice != 5);
			case 3://the case 3 is exiting the program and storing the portfolio value into the txt file.
				   //randomly choose stock price from one of the two "Result_x.txt" file
				if ((double)rand() / RAND_MAX < 0.5)
					stock.StorePortValue(&bank, stock_symbol_1, price_per_share_1);
				else
					stock.StorePortValue(&bank, stock_symbol_2, price_per_share_2);
				break;
			default:
				break;
			}
		}
		else//if the user do not enter the number between 1 to 3, the program will give him this prompt
		{
			cout << "Please enter a number between 1 to 3." << endl;
			cin.clear();
			cin.ignore();
		}
	} while (choice != 3);
	
	//WHY THIS FILE IS TO BE WRITEN IN THE MAIN FUNCTION
	//this file need to store the information when exiting the programming, without any calling function. 
	//So the only way to realize this function is putting this in the destructor. which is the different from transaction history files.
	//However, this file need the current price which is diiferent from the account information files. 
	//The destructor should not contain any paramaters
	return 0;//indicate the suucess of main function
}//end of main