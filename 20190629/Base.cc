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
	static Base * getInstance()
	{
		return new Base();
	}
		

private:
	Base() {};

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
};
 
int main(void)
{
	Base base;

	Derived derived;
}
