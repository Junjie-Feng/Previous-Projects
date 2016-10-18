//Title: Final Project--Account Management System
//Course: 16:332:503 Programming Financial
//Name: Junjie Feng
//Date of Submission: 12/11/2013

#include"Account_JunjieFeng.h"
#include "BankAccount_JunjieFeng.h"
#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
//constructor
BankAccount::BankAccount()
{
	float balancevalue;
	//read the txt file for the cash balance 
	ifstream readfile;
	readfile.open("cash_balance.txt");
	//if the file open successful
	if (readfile.is_open())
	{
		readfile >> balancevalue;
		setBalance(balancevalue);
		readfile.close();
	}
	//if there is no history cash balance, then program will initialize the cash balance as $10000
	else
		setBalance(10000);
}

//set cash balance function
void BankAccount::setBalance(float BalanceValue)
{
	balance = BalanceValue;
}

//get cash balance fucniton
float BankAccount::getBalance()
{
	return balance;
}

//view the current cash balance fucntion 
void BankAccount::ViewBalance()
{
	cout << fixed << setprecision(2) << "You have $" << getBalance() << " in your bank account." << endl;
}

//buy share funciton
void BankAccount::BuyShares(float stock_value)
{
	//modify the cash balance
	setBalance(getBalance() - stock_value);
	//creat local time
	time_t t;
	tm *_time;
	t = time(NULL);
	_time = localtime(&t);
	char d[12];
	strftime(d, 12, "%m/%d/%Y", _time);
	//add this transaction in the bank transaction history
	ofstream writefile;
	writefile.open("bank_transaction_history.txt", ios::app);
	writefile << fixed << setprecision(2) << setw(12) << left 
		<< "Buy-Stock" << "$" << setw(11) << stock_value << setw(12) << d << "$" << setw(11) << getBalance() << endl;
	writefile.close();//close file
}

void BankAccount::SellShares(float stock_value)
{
	//modify the cash balance
	setBalance(getBalance() + stock_value);
	//creat local time
	time_t t;
	tm *_time;
	t = time(NULL);
	_time = localtime(&t);
	char d[12];
	strftime(d, 12, "%m/%d/%Y", _time);
	//add this transaction in the bank transaction history	
	ofstream writefile;
	writefile.open("bank_transaction_history.txt", ios::app);
	writefile << fixed << setprecision(2) << setw(12) << left 
		<< "Sell-Stock" << "$" << setw(11) << stock_value << setw(12) << d << "$" << setw(11) << getBalance() << endl;
	writefile.close();//close file
}

void BankAccount::Withdraw()
{
	float amount;
	//prompt and input
	cout << "Please enter the amount you wish to withdraw: " ;
	cin >> amount;
	//modify the cash balance
	setBalance(getBalance() - amount);
	//creat local time
	time_t t;
	tm *_time;
	t = time(NULL);
	_time = localtime(&t);
	char d[12];
	strftime(d, 12, "%m/%d/%Y", _time);
	//add this transaction in the bank transaction history	
	ofstream writefile;
	writefile.open("bank_transaction_history.txt", ios::app);
	writefile << fixed << setprecision(2) << setw(12) << left 
		<< "Withdraw" << "$" << setw(11) << amount << setw(12) << d << "$" << setw(11) << getBalance() << endl;
	writefile.close();//close file
}

void BankAccount::Deposit()
{
	float amount;
	//prompt and input
	cout << "Please enter the amount you wish to deposit: ";
	cin >> amount;
	//modify the cash balance
	setBalance(getBalance() + amount);
	//creat local time
	time_t t;
	tm *_time;
	t = time(NULL);
	_time = localtime(&t);
	char d[12];
	strftime(d, 12, "%m/%d/%Y", _time);
	//add this transaction in the bank transaction history
	ofstream writefile;
	writefile.open("bank_transaction_history.txt", ios::app);
	writefile << fixed << setprecision(2) << setw(12) << left 
		<< "Deposit" << "$" << setw(11) << amount << setw(12) << d << "$" << setw(11) << getBalance() << endl;
	writefile.close();//close file
}

//view cash transaction history
void BankAccount::ViewTranHistory()
{
	char data[256] = {};
	//read the txt file
	ifstream readfile;
	readfile.open("bank_transaction_history.txt");
	cout << fixed << setprecision(2) << setw(12) << left 
		<< "Event" << setw(12) << "Amount" << setw(12) << "Date" << setw(12) << "Balance" ;
	do
	{
		cout << data << endl;
		//read a line of history one time 
		readfile.getline(data, 256);
	} while (!readfile.eof());//reach the end of the file, then end the loop
	readfile.close();//close file
}

//destructor function, each time exit the program, the cash balance will be stored in the txt file
BankAccount::~BankAccount()
{
	//Store the bank account information in the txt file when exit the program
	//creat time object to recording Time
	time_t T;
	tm *T_time;
	char t[12];
	T = time(NULL);
	T_time = localtime(&T);
	strftime(t, 12, "%T", T_time);
	//creat time object to recording Date
	time_t D;
	tm *D_time;
	D = time(NULL);
	D_time = localtime(&D);
	char d[12];
	strftime(d, 12, "%m/%d/%Y", D_time);
	//wirte the file
	ofstream writefile;
	writefile.open("cash_balance.txt");
	writefile << fixed << setprecision(2) << setw(10) << left << balance << t << " " << d;
	writefile.close();//close file
}
