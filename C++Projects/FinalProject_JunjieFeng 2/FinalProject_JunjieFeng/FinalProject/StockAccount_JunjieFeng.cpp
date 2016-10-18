//Title: Final Project--Account Management System
//Course: 16:332:503 Programming Financial
//Name: Junjie Feng
//Date of Submission: 12/11/2013

#include "Account_JunjieFeng.h"
#include "StockAccount_JunjieFeng.h"
#include"BankAccount_JunjieFeng.h"
#include"StockNode_JunjieFeng.h"
#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<ctime>
#include<vector>
#include<engine.h>//used for the ViewPortfolioHistory function which calls MATLAB
using namespace std;

const int num_of_stock = 49;//since the number of companies will not change commonly.

//constructor
StockAccount::StockAccount()
{
	//initialize the two pointers point to Null 
	this->myHead = NULL;
	this->myTail = NULL;
	//use vectors to restores the previous stock account information 
	vector<string>symbol;
	vector<int>share;
	string sym;
	int count = 0,num;
	//Read the results1_txt,Store the stock account information 
	ifstream readfile;
	readfile.open("stock_account_infromation.txt");
	//if the file exists, read the data. Otherwise, will not read any information
	if (readfile.is_open())
	{
		//cout << "The account information has been loaded." << endl;
		do
		{
			//read the information
			readfile >> sym;
			readfile >> num;
			//stores the symbol and share numbers in the vectors
			symbol.push_back(sym);
			share.push_back(num);
		}while (!readfile.eof());
		readfile.close();
		//Creat the 'doubly linked list' to restore the portfolio
		for (unsigned int i = 0; i < symbol.size(); i++)
		{

			StockNode *NewNode = new StockNode(symbol[i], share[i]);
			//if the list is empty
			if (myHead == NULL)
			{
				myHead = NewNode;
				myTail = NewNode;
			}
			//else, add the new node at the end of the list
			else
			{
				myTail->next = NewNode;
				NewNode->previous = myTail;
				myTail = NewNode;
			}
		}
	}
}

//Display the stock price function
void StockAccount::DisplayPrice(string *stock_symbol,float * price_per_share)
{
	int i;
	string target_stock,date;
	cout << "Please enter the stock symbol: ";
	cin >> target_stock;
	
	//compare the symbol with all the symbols in the result txt files
	for (i = 0; i < num_of_stock; i++)
	{
		//if find the same symbol, print the symbol and the price
		if (target_stock == *(stock_symbol + i))
		{
			cout << setw(16) << left << "Company-Symbol" << "Price-per-share" << endl
				<< setw(16) << *(stock_symbol + i) << "$" << *(price_per_share + i) << endl;
			break;
		}
	}
	//if do not find the same symbol
	if (i == num_of_stock)
		cout << "The symbol can not be found." << endl;
}

//display the portfolio function
void StockAccount::DipalyPortfolio(BankAccount * bank, string *stock_symbol, float * price_per_share)
{
	cout << "Cash balance = $" << bank->getBalance() << endl;
	
	//total portfolio equals to the sum of worth of owned shares and the cash balance
	float total_value= bank->getBalance();

	//if the portfolio is empty
	if (myHead == NULL)
		cout << "The portfolio is empty." << endl;
	else
	{
		//sort the list by the value of each owning stock
		SortList(bank, stock_symbol, price_per_share);

		StockNode * temp = myHead;
		//print the title
		cout << setw(16) << left << "Company-Symbol" << setw(8) << "Number" << setw(17) << "Price-per-share" << setw(13) << "Total-Value" << endl;
		//print out the sorted list one by one
		for (temp = myHead; temp != NULL; temp = temp->next)
		{
			//for loop in order to find out the current price of the each stock
			for (int i = 0; i < num_of_stock; i++)
			{
				if (temp->getsymbol() == *(stock_symbol + i))
				{
					cout << setw(16) << temp->getsymbol() << setw(8) << temp->getShareNo() << setw(17) << *(price_per_share + i) << setw(11) << temp->getShareNo()* *(price_per_share + i) << endl;
					//add each stock's current worth
					total_value += temp->getShareNo()* *(price_per_share + i);
					break;
				}
			}
		}
		//print the total value of the potfolio
		cout << fixed << setprecision(2) << "Total portfolio value: $" << total_value << endl;
	}
}

//buy shares function
void StockAccount::BuyShares(BankAccount *bank, string *stock_symbol, float *price_per_share)
{
	string target_stock;
	int num_of_shares, i;
	float max_price,actual_price;
	//prompt and input
	cout << "Please enter the stock symbol you wish to purchase: ";
	cin >> target_stock;
	cout << "Please enter the number of shares: ";
	cin >> num_of_shares;
	cout << "Please enter the maximum amount you are willing to pay per share: ";
	cin >> max_price;
	//find the buy-in price for this stock
	for (i = 0; i < num_of_stock; i++)
	{
		//compare the symbol with the existing symbols
		if (target_stock == *(stock_symbol + i))
		{
			actual_price = *(price_per_share + i);
			break;
		}
	}

	//if find the symbol in result.txt, 'i' will less than the number of stock
	if (i < num_of_stock)
	{
		//if the cash balance is not less than the total value of buy-in stock, could go futher step
		if (bank->getBalance() >= actual_price*num_of_shares)
		{
			//if the current price is not greater than the price user would like to buy-in, then transaction succeed
			if (actual_price <= max_price)
			{
				//modify the bank account balance
				//add the transaction into the bank balance history
				bank->BuyShares(actual_price*num_of_shares);

				//modify the stock aacount(add the these share into the portfolio)				
				//if the list is empty, add the new node as the first node in the list
				if (myHead == NULL)
				{
					StockNode *NewNode = new StockNode(target_stock, num_of_shares);
					myHead = NewNode;
					myTail = NewNode;
				}
				else
				{
					StockNode *temp = myHead;
					//find out whether this stock is already existing in the list before
					while (temp != NULL)
					{
						//if there already has this stock, add the shares to this node. 
						if (temp->getsymbol() == target_stock)
						{
							temp->setShareNo(temp->getShareNo() + num_of_shares);
							break;
						}
						else
							temp = temp->next;
					}
					//if the 'temp==null', there is no same stock
					//add new node at the end of the list
					if (temp == NULL)
					{
						StockNode *NewNode = new StockNode(target_stock, num_of_shares);
						myTail->next = NewNode;
						NewNode->previous = myTail;
						myTail = NewNode;
					}
				}
				//creat local time
				time_t t;
				tm *_time;
				char d[12];
				t = time(NULL);
				_time = localtime(&t);
				strftime(d, 12, "%T", _time);
				//add this transaction to the history	
				ofstream writefile;
				writefile.open("stock_transaction_history.txt", ios::app);
				writefile << fixed << setprecision(2) << setw(7) << left 
					<< "Buy" << setw(16) << target_stock << setw(8) << num_of_shares << setw(17) << actual_price << setw(13) << num_of_shares*actual_price << setw(12) << d << endl;
				writefile.close();
				//display the succeeded in purchasing
				cout << fixed << setprecision(2) << "You have purchased " << num_of_shares << " shares of " << target_stock << " at $" << actual_price << " each for a total of $" << num_of_shares*actual_price << "." << endl;

			}
			else
				cout << "The transaction fails, because the cost per stock is higher than the amount you are willing to pay." << endl;
		}
		else
			cout << "The transaction fails, because your bank balance is less than the value of stock you want to buy." << endl;
	}
	else
		cout << "The stock is not available" << endl;
}

//sell shares function
void StockAccount::SellShares(BankAccount *bank, string *stock_symbol, float *price_per_share)
{
	string target_stock;
	int num_of_shares, owned_shares,i;
	float min_price, actual_price;
	bool real_stock=false;
	//prempt and input
	cout << "Please enter the stock symbol you wish to sell: ";
	cin >> target_stock;
	cout << "Please enter the number of shares: ";
	cin >> num_of_shares;
	cout << "Please enter the minimum amount you are willing to sell each share for: ";
	cin >> min_price;
	//find out wherther the stock is in the result_txt file or not
	for (i = 0; i < num_of_stock; i++)
	{
		if (target_stock == *(stock_symbol + i))
		{
			real_stock = true;
			break;
		}
	}
	//find the stock is in the portfolio/stock account or not
	StockNode *temp;
	for (temp = myHead; temp!=NULL; temp=temp->next)
	{
		if (target_stock == temp->getsymbol())
		{
			owned_shares = temp->getShareNo();
			break;
		}
	}
	//find the sell-out price for this stock
	for (i = 0; i < num_of_stock; i++)
	{
		if (target_stock == *(stock_symbol + i))
		{
			actual_price = *(price_per_share + i);
			break;
		}
	}
	//if the stock exists in the result txt file
	if (real_stock)
	{
		//if the portfolio has this stock
		if (temp != NULL)
		{
			//if the sell-share-number is not bigger than the shares owning
			if (owned_shares >= num_of_shares)
			{
				//if the current price is not less than the price which user want to sell
				if (actual_price >= min_price)
				{
					//modify the bank account balance
					//add this tansaction in the bank history
					bank->SellShares(actual_price*num_of_shares);

					//modify the stock account/portfolio shares
					temp->setShareNo(temp->getShareNo() - num_of_shares);

					//if there is no shares of, kick out this stock
					if (temp->getShareNo() == 0)
					{
						//if this stock node is the only node in the list
						if (myHead == myTail)
						{
							myHead = NULL;
							myTail = NULL;
						}
						//if this stock node is the first node in the list
						else if (temp == myHead)
						{
							myHead = temp->next;
							temp->next->previous = NULL;
						}
						//if this stock node is the last node in the list
						else if (temp == myTail)
						{
							myTail = temp->previous;
							temp->previous->next = NULL;
						}
						//if this node is not either the first or the last.
						else
						{
							temp->previous->next = temp->next;
							temp->next->previous = temp->previous;
						}
					}
					//creat local time
					time_t t;
					tm *_time;
					char d[12];
					t = time(NULL);
					_time = localtime(&t);
					strftime(d, 12, "%T", _time);
					//add this transaction to the history	
					ofstream writefile;
					writefile.open("stock_transaction_history.txt", ios::app);
					writefile << fixed << setprecision(2) << setw(7) << left
						<< "Sell" << setw(16) << target_stock << setw(8) << num_of_shares << setw(17) << actual_price << setw(13) << num_of_shares*actual_price << setw(12) << d << endl;
					writefile.close();

					//display the succeded in selling
					cout << fixed << setprecision(2) << "You have sold " << num_of_shares << " shares of " << target_stock << " at $" << actual_price << " each for a total of $" << num_of_shares*actual_price << "." << endl;
				}
				else
					cout << "The transaction fails, because the price per share is lower than the amount you are willing to sell for." << endl;
			}
			else
				cout << "The transaction fails, because you do not own the amount of shares you want to sell." << endl;
		}
		else
			cout << "The transaction fails, because this stock is not in your portfolio." << endl;
	}
	else
		cout << "This stock symbol do not exist in the result.txt file." << endl;
}

//store the portfolio value in the txt file function
void StockAccount::StorePortValue(BankAccount *bank, string *stock_symbol, float *price)
{
	//this value is the amount of all the stock's current money worth! the portfolio value need to be added with cash balance(this is done in the main function)
	float total_value = 0;
	StockNode * temp = myHead;
	//add each stocknode's value to the total value 
	for (temp = myHead; temp != NULL; temp = temp->next)
	{
		for (int i = 0; i < num_of_stock; i++)
		{
			if (temp->getsymbol() == *(stock_symbol + i))
			{
				total_value += temp->getShareNo()* *(price + i);
				break;
			}
		}
	}
	//Time
	time_t T;
	tm *T_time;
	char t[12];
	T = time(NULL);
	T_time = localtime(&T);
	strftime(t, 12, "%T", T_time);

	//Date
	time_t D;
	tm *D_time;
	D = time(NULL);
	D_time = localtime(&D);
	char d[12];
	strftime(d, 12, "%m/%d/%Y", D_time);
	//when exit the program, store the port value in the .txt file
	ifstream check;
	check.open("portfolio_value_history.txt");
	bool havehistory = check.is_open();
	ofstream writefile;
	writefile.open("portfolio_value_history.txt", ios::app);//store new data following the existed data.
	if (havehistory)
		writefile << endl;
	writefile << fixed << setprecision(2) << setw(10) << left
		//the portfolio value equals to the sum of cash balance and total stock value
		<< total_value + bank->getBalance() << t << " " << d << "  " << T;
	writefile.close();
}

//view the portfolio history function
void StockAccount::ViewPortfolioHistory()
{
	string null;
	int i = 0;
	double time, value,start;
	double Y[500] = { 0 }, X[500] = { 0 };
	//Read the results1_txt, Store the stock account information 
	ifstream readfile;
	readfile.open("portfolio_value_history.txt");
	//if the file exists, read the data. Otherwise, will not read any information
	if (readfile.is_open())
	{
		do
		{
			readfile >> value;
			readfile >> null;
			readfile >> null;
			readfile >> time;
			//store the starting-time as the basic.
			if (i == 0)
				start = time;
			//the unit for x axis is hour
			//the the first element of time always equals to 0
			//Subsequent elements store the amount of time change since the account create
			X[i] = (time-start)/60/60;
			Y[i] = value;
			i++;
		} while (!readfile.eof());//if the all the history is read, then end the loop
		readfile.close();
	}
	//create a engine object
	Engine *ep;
	//open the matlab engine
	ep = engOpen(NULL);
	//if the engine does not open
	if (ep == NULL)
	{
		cout << "Error: Not Found." << endl;
		exit(1);
	}
	// end
	//create two objects of matlab array
	mxArray *A,*B;
	//allocate the space for them
	A = mxCreateDoubleMatrix(1, i, mxREAL);
	B = mxCreateDoubleMatrix(1, i, mxREAL);
	//transfer data two these array
	memcpy((void *)mxGetPr(A), (void *)X,i*sizeof(double));
	engPutVariable(ep, "X", A);
	memcpy((void *)mxGetPr(B), (void *)Y, i*sizeof(double));
	engPutVariable(ep, "Y", B);
	//plot the graph X as x-axis and Y and Y-axis
	engEvalString(ep, "plot(X,Y);");
	engEvalString(ep, "title('The Portfolio Value History');");
	//destroy the two array
	mxDestroyArray(B);
	mxDestroyArray(A);
	//let the system wait
	system("pause");
}

//view the stock transaction history
void StockAccount::ViewTranHistory()
{
	char data[256] = {};
	//read the txt file
	ifstream readfile;
	readfile.open("stock_transaction_history.txt");
	cout << setw(7) << left << "Event" << setw(16) << "Company-Symbol" << setw(8) << "Number" << setw(17) << "Price-per-share" << setw(13) << "Total-Value" << setw(8) << "Time" ;
	do {
		cout << data << endl;
		//read the whole line as a char string
		readfile.getline(data, 256);
	} while (!readfile.eof());//if reach the end of file, then end the loop
	readfile.close();//close the file
}

//destructor function
StockAccount::~StockAccount()
{
	//Store the stock account information in the txt file when exit the program 
	ofstream writefile;
	writefile.open("stock_account_infromation.txt");
	StockNode *temp;
	//store the stock node one by one
	for (temp = myHead; temp != NULL; temp = temp->next)
	{
		if (temp != myHead)
			writefile << endl;
		writefile << setw(8) << left << temp->getsymbol() << temp->getShareNo();
	}
	//close the file
	writefile.close();
}

//sort the doubly linked list function (private fucntion)
void StockAccount::SortList(BankAccount * bank, string *stock_symbol, float * price_per_share)
{
	StockNode *temp,*temp2;
	float value[num_of_stock],container;
	int count = 0;

	//find out the value of each sotck which is in the list
	//store the value in a array as the same order of the unsorted stock list
	for (temp = myHead; temp != NULL; temp = temp->next)
	{
		//count the number of stocks cuurently owned
		count++;
		for (int i = 0; i < num_of_stock; i++)
		{
			if (temp->getsymbol() == *(stock_symbol + i))
				*(value + count-1) = temp->getShareNo()**(price_per_share + i);
		}
	}

	//sort the list, using bubble-sort, as the value descend 
	for (int i = 0; i < count - 1; i++)
	{
		temp = myHead;
		for (int j = 0; j < count - 1 - i; j++)
		{
			if (*(value + j) < *(value + j + 1))
			{
				//temp2 is alway pointer which points to the node behind the temp node 
				temp2 = temp->next;
				//swap the value array
				container = *(value + j);
				*(value + j) = *(value + j + 1);
				*(value + j + 1) = container;
				
				//swap the two node
				//if one node is the head of list and the other one is not the tail of list
				if (temp == myHead&&temp2 != myTail)
				{
					myHead = temp2;
					temp2->next->previous = temp;

					temp2->previous = NULL;
					temp->next = temp2->next;

					temp->previous = temp2;
					temp2->next = temp;
				}
				else
				{
					//else if the one node is not the head of list and the other one is the tail of the list
					if (temp2 == myTail&&temp != myHead)
					{
						myTail = temp;
						temp->previous->next = temp2;

						temp->next = NULL;
						temp2->previous = temp->previous;

						temp2->next = temp;
						temp->previous = temp2;

					}
					
					else
					{
						//else if one the head and the other is tail
						if (temp == myHead&&temp2 == myTail)
						{
							myHead = temp2;
							myTail = temp;
							temp->next = NULL;
							temp->previous = temp2;
							temp2->next = temp;
							temp2->previous = NULL;
						}
						else
						{
							//else if either of them is the head or the tial of the list
							temp->previous->next = temp2;
							temp2->next->previous = temp;

							temp->next = temp2->next;
							temp2->previous = temp->previous;

							temp->previous = temp2;
							temp2->next = temp;
						}
					}
				}
			}
			else
				temp = temp->next;
		}
	}

}
