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
	void display(int idx = 0) const
	{
		cout << ">> base = " << _base << ", idx = " << idx << endl;
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
	void display(int idx = 1) const
	{
		cout << ">> _child1 = " << _child1 << ", idx = " << idx << endl;
	}

private:
	double _child1;
};


int main(void)
{
	Base base(1);
	Child1 child1(11, 12);

	//如果基类和派生类的虚函数都设置了默认值,且默认值还各有不同，
	//当通过指针或者引用调用虚函数时，默认值的使用只跟指针类型有关
	Base * pbase = &base;
	pbase->display();

	pbase = &child1;//易错题
	pbase->display();//??? 默认值使用的是基类的设置的默认值，不是派生类设置的默认值
	
	Child1 * pchild1 = &child1;
	pchild1->display();



	return 0;
}
 
