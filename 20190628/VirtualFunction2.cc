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
	void display() const override
	{
		cout << ">> _child1 = " << _child1 << endl;
	}

private:
	double _child1;
};

//引用也可以表现多态的特性
void display(Base & pbase)
{
	pbase.display();
}

int main(void)
{
	Base base(1);
	Child1 child1(11, 12);
	display(base);
	display(child1);

	//通过对象名调用不会表现多态特性
	child1.display();//直接去代码区找到Child1::display()

	return 0;
}
 
