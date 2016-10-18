#ifndef BASE_H
#define BASE_H
class Base
{
public:
	int f()
	{
		return 1;
	}
	virtual int g()
	{
		return 2;
	}
	virtual void setname(string);
	virtual void setid(int) = 0;
protected:
	int id;
private:
	string name;
};
#endif