//Title: Final Project--Account Management System
//Course: 16:332:503 Programming Financial
//Name: Junjie Feng
//Date of Submission: 12/11/2013

#ifndef STOCKNODE_H
#define STOCKNODE_H
#include <string>
using namespace std;
using std::string;

class StockNode
{
	friend class StockAccount;//make StockAccount a friend
public:
	//constructor
	StockNode(string symbol, int no);
	//get the stock symbol of the node
	string getsymbol();
	//get the share number of the stock node
	int getShareNo();
	//set the Share number of the stock node
	void setShareNo(int);
	//destructor
	~StockNode();
private:
	//store the node information, the symbol and the share number of the stock
	string Stock_Symbol;
	int Share_No;
	//store the pointer point to the next node
	StockNode *next;
	//store the pointer point to the previous node
	StockNode *previous;
};
#endif
