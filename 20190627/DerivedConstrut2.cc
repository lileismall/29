 ///
 /// @file    DerivedConstrut.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-27 11:04:38
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
	Base(): _base(0) {	cout << "Base()" << endl;	}
	
	Base(double base)
	: _base(base)
	{	cout << "Base(double)" << endl;}

	void print() const
	{	cout << "Base::_base = " << _base;	}

private:
	double _base;
};

class Derived
: public Base
{
public:
	//当派生类没有显式定义构造函数，基类有显式定义构造函数，
	//要创建派生类对象时，
	//在执行派生类构造函数的初始化表达式时，调用基类的
	//无参构造函数, 完成基类部分的初始化
	Derived()
	{	cout << "Derived()" << endl;	}	

	void display() const
	{
		print();
		cout << ", _derived = " <<  _derived << endl;
	}

private:
	double _derived;
};
 
int main(void)
{
	Derived derived;
	derived.display();

	return 0;
}
