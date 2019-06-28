 ///
 /// @file    VirtualFunction.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-27 16:02:12
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
	Base(double base)
	: _base(base)
	{	cout << "Base()" << endl;	}

	//在成员函数中访问，一样体现出动态多态特性
	void func1() 
	{
		this->display();
	}

	void func2()
	{
		Base::display();
	}

	virtual 
	void display() const
	{
		cout << ">> base = " << _base << endl;
	}

private:
	double _base;
};

class Child1
: public Base
{
public:
	Child1(double base, double child)
	: Base(base)
	, _child1(child)
	{
		cout << "Child(double, double)" << endl;
	}

	
	virtual
	void display() const
	{
		cout << ">> _child1 = " << _child1 << endl;
	}

private:
	double _child1;
};


int main(void)
{
	Base base(1);
	Child1 child1(11, 12);

	Base * pbase = &base;
	pbase->func1();
	pbase->func2();


	pbase = &child1;
	pbase->func1();
	pbase->func2();



	return 0;
}
 
