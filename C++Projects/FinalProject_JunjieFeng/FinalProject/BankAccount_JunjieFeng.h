//Title: Final Project--Account Management System
//Course: 16:332:503 Programming Financial
//Name: Junjie Feng
//Date of Submission: 12/11/2013

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include "Account_JunjieFeng.h"
class BankAccount :public Accout
{
public:
	//constructor
	BankAccount();
	//all the functions of the list editing
	void setBalance(float);
	float getBalance();
	void ViewBalance();
	void BuyShares(float);
	void SellShares(float);
	void Withdraw();
	void Deposit();
	void ViewTranHistory();
	//destrucotr
	~BankAccount();
private:
	//the pointer point to the first and last nodes of the list
	float balance;
};
#endif
