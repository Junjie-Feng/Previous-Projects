#ifndef NODE_H
#define NODE_H
#include <string>
using namespace std;
using std::string;

class Node
{
	friend class LinkedList;//make LinkedLIst a friend
public:
	//constructor
	Node(string name, int no)
		:itemName(name), itemNo(no)
	{
		this->next = NULL;//the innitialization of pointer next is NULL
	}
	//destructor
	~Node(){}
private:
	//store the node information
	string itemName;
	int itemNo;
	//store the pointer point to the next node
	Node *next;
};
#endif
