 ///
 /// @file    DerivedConstrut.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-27 11:04:38
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//错误的说法: 创建派生类对象时，先调用基类构造函数，
//		再调用派生类构造函数
//
//
//派生类对象创建时，先初始化基类部分，再初始化派生类部分
//	 先调用派生类构造函数, 在执行派生类构造函数的过程中，
//	 再去调用基类的构造函数
//


class Base
{
public:
	//Base(): _base(0) {	cout << "Base()" << endl;	}

	Base(double base)
	: _base(base)
	{	cout << "Base(double)" << endl;	}

	void print() const
	{	cout << "Base::_base = " << _base;	}

	~Base()
	{	cout << "~Base()" << endl;	}

private:
	double _base;
};

class Derived
: public Base
{
public:
	//当派生类有显式定义构造函数，基类没有显式定义构造函数，
	//要创建派生类对象时，
	//在执行派生类构造函数的初始化表达式时，调用基类的
	//无参构造函数, 完成基类部分的初始化
	Derived(double derived, double base)
	: Base(0) // 对于基类部分是通过类名调用构造函数
	, _derived(derived)
	, _base(base)//对于对象成员，是通过对象名调用构造函数
	{	cout << "Derived(double)" << endl;	}	

	Derived(double base, double derived, double base1)
	: Base(base)
	, _derived(derived)
	, _base(base1)
	{
		cout << "Derived(double, double)" << endl;
	}

	void display() const
	{
		print();
		cout << ", _derived = " <<  _derived << endl;
	}

	~Derived()
	{	cout << "~Derived()" << endl;	}

private:
	double _derived;
	Base _base;
};
 
int main(void)
{
	Derived derived(11.11, 12.12, 33.33);
	derived.display();

	Derived derived2(11.11, 22.22);
	derived2.display();

	return 0;
}
