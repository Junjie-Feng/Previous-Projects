#include <iostream>
#include <iomanip>
#include <cmath>	
#include<stack>
#include"Base.h"
#include"Derived.h"
using namespace std;
void f(int, const double);
void f(int);
static int count = 0;
void broccoli(stack<int>&);
int main()
{
	/*
	//1
	for (int j = 0; j < 3; j++)
		for (int k = 0; k <= j; k++)
			for (int i = 1; i < k; i++)
				cout << "Good luck" << endl<<i<<endl<<k<<endl<<j<<endl;
	//2
	int p;
	double k;
	cin >> p;
	k = pow(2, p);
	f(2, k);
	cout << ::count<<endl;

	//3
	int n;
	cin >> n;
	double a;
	a= n*log(n);
	cout << a<<endl;

	//4
	float i4, x4, *p4, *q4;
	p4 = &i4;
	*p4 = 10;
	q4 = &x4;
	*q4 = 8.6;
	cout << x4 << endl << i4 << endl;
	

	//6
	f(3);
	

	//7
	char *names[6];
	int count[6] = {1,1,1,1,1,1};
	string a, b;
	a = "fjj";
	b = "fjj";
	names[0] = "f00"; 
	names[1] = "f0"; 
	names[2] = "f0";
	names[3] = "f0000"; 
	names[4] = "f11"; 
	names[5] = "f11";

	for (int i = 0; i < 6; i++)
	{
		if(count[i]!=-1)
			for (int j = i+1; j < 6; j++)
			{
				if (count[j] != -1)
				{
					if (names[i] == names[j])//为什么不能用指针指向的内容做比较？？貌似是会按照字符挨个比较，即使不同也可能比较结果相等；
					{//直接比价指针，是可以确定是否相等的。但是逻辑上，两个相同的字符串应该分配了不一样的地址空间，为什么他们的指针会相同呢？
						count[i]++;
						count[j] = -1;
					}
				}
			}
	}
	int aa = 0,temp;
	char *temp2;
	for (aa = 0; aa < 4;aa++)
	if (count[aa] <= count[aa + 1])
	{
		temp = count[aa];
		count[aa] = count[aa + 1];
		count[aa + 1] = temp;
		temp2 = names[aa];
		names[aa] = names[aa + 1];
		names[aa + 1] = temp2;
	}
	//cout << count[0] << endl << names[0] << endl;

	int flag=0;
	int indec[6];
	for (int bb = 0; bb < 4; bb++)
	{
		static int i = 0;
		if (count[0] == count[bb])
		{
			flag++;
			indec[i] = bb;
			i++;
		}
	}
	for (int i = 0; i < flag; i++)
	{
		cout << count[indec[i]] << endl << names[indec[i]]<<endl;
	}

	//8
	stack<int> s;
	for (int i = 1; i < 8; i++)
		s.push(2 * i);
	broccoli(s);*/

	//12 is similar to one of the assignments.

	//1
Base *b;
Derived *d;
b = new Derived;
d = new Derived;
cout << b->f() << b->g() << d->f() << d->g();

	return 0;
}
void f(int j, const double r)
{
	if (j >= r)
		return;
	else
	{
		cout << "Ship!" << endl;
		++::count;
		f(2 * j, r);
	}
}
void f(int n)
{
	static int x = 1;
	if (n <= 1)
		return;
	f(n - 1);
	x++;
	f(n - 2);
	x++;
	cout << x << endl << n << endl << endl;
}
void broccoli(stack <int> &s)
{
	int i;
	if (s.empty())
		return;
	i = s.top();
	s.pop();
	broccoli(s);
	cout << i << endl;
	s.push(i);
	return;
}