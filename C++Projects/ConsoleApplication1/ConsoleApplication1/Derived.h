#ifndef DERIVED_H
#define DERIVED_H
#include"Base.h"
class Derived:public Base
{
public:
	int f()
	{
		return 3;
	}
	int g()
	{
		return 4;
	}
};
#endif