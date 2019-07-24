 ///
 /// @file    Base.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-29 10:16:13
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base 
{
public:
	Base() {};

	virtual void display() const //final
	{
		cout << "Base::display()" << endl;
	}

private:
	int _base;
};

class Derived
: public Base
{
public:
	Derived()
	: Base()
	{}

	//在虚函数的末尾使用final关键字，表示该虚函数不能再被覆盖
	virtual void display() const final
	{	cout << "Derived::display()" << endl;	}
};

class Son
: public Derived
{
public:
	virtual void display() const
	{
		cout << "Son::display()" << endl;
	}
};
 
int main(void)
{
	Derived derived;
}
