#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include"Node_JunjieFeng.h"
class LinkedList
{
public:
	//comstructor
	LinkedList();
	//all the functions of the list editing
	void addToStart();
	void addToEnd();
	void printList();
	void removeFromStart();
	void removeFromEnd();
	void removeNodeByName();
	void removeNodeByNo();
	//destrucotr
	~LinkedList();
private:
	//the pointer point to the first and last nodes of the list
	Node *myHead;
	Node *myTail;
};
#endif
