//Title: Final Project--Account Management System
//Course: 16:332:503 Programming Financial
//Name: Junjie Feng
//Date of Submission: 12/11/2013

#include "StockNode_JunjieFeng.h"
//constructor function
StockNode::StockNode(string symbol, int no)
	:Stock_Symbol(symbol), Share_No(no)
{
	this->next = NULL;//the innitialization of pointer next is NULL
	this->previous = NULL;
}
//get the symbol of the stock fucntion
string StockNode::getsymbol()
{
	return Stock_Symbol;
}
//get the share number of stock function
int StockNode::getShareNo()
{
	return Share_No;
}
//set the share number of the stock function
void StockNode::setShareNo(int share_num)
{
	Share_No = share_num;
}
//destructor fucntion
StockNode::~StockNode()
{
}
