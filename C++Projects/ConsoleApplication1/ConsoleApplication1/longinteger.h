#ifndef LONGINTEGER_H
#define LONGINTEGER_H
class LongInteger
{
public:
	LongInteger();
	LongInteger(const LongInteger &);
private:
	struct ListNode
	{
		int iteml;
		ListNode *next;
	};
	int size;
	ListNode *head;
	ListNode *find(int) const;
	
};
#endif