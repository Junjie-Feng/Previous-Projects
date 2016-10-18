//Title: Final Project--Account Management System
//Course: 16:332:503 Programming Financial
//Name: Junjie Feng
//Date of Submission: 12/11/2013

#ifndef STOCKACCOUNT_H
#define STOCKAACOUNT_H
#include"StockNode_JunjieFeng.h"
#include"BankAccount_JunjieFeng.h"
#include"Account_JunjieFeng.h"
#include<string>
using namespace std;
class StockAccount :public Accout
{
public:
	//comstructor
	StockAccount();
	//all the functions of the list editing
	void DisplayPrice(string *,float *);//displaying the price of the user's chosen stock
	void DipalyPortfolio(BankAccount *, string *, float * );//displaying the portfolio value of this account
	void BuyShares(BankAccount *,string *, float *);//buying shares of the chosen stock 
	void SellShares(BankAccount *, string *, float *);//selling the shares of the owning stock
	void StorePortValue(BankAccount *, string *, float *);//storing the portfolio value into the txt file
	void ViewPortfolioHistory();//viewing the portfolio history by using matlab to plot the graph 
	void ViewTranHistory();
	//destrucotr
	~StockAccount();
private:
	//sort the portfolio list by the value of each stock
	void SortList(BankAccount *, string *, float *);
	//the pointer point to the first and last nodes of the list
	StockNode *myHead;
	StockNode *myTail;
};
#endif
