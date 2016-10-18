#ifndef BOOKLIST_H//same statement as #program once
#define BOOKLIST_H
class Booklist//define class name "Booklist"
{
public:
	Booklist(int);//constructor
	//declare member function for booklist management
	void insert();
	void isert_at();
	void find_linear();
	void find_binary();
	void delete_item_position();
	void delete_item_isbn();
	void sort_list_selection();
	void sort_list_bubble();
	void print() const;

	~Booklist();//destructor

private:
	//declare private functions invoked by member functions
	int find();
	void delete_();
	//declare variables 
	int mylist[100];
	const int size;
	int num_in_list;
	int position;
	int element;
};
#endif