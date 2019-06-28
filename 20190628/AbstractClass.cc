 ///
 /// @file    AbstractClass.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-28 14:47:46
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//抽象类的第二种形式：定义了protected构造函数的类称为抽象类
class Base
{
protected:
	Base(double base)
	: _base(base)
	{	cout << "Base(double)" << endl;	}

	void print() const 
	{	cout << "Base::_base = " << _base << endl;	}

private:
	double _base;
};

class Derived
: public Base
{
public:
	Derived(double base, double derived)
	: Base(base)
	, _derived(derived)
	{
		cout << "Derived(double,double)" << endl;
	}

	void display() const
	{	
		print();
		cout << "Derived::_derived = " << _derived << endl;
	}

private:
	double _derived;
};


 
int main(void)
{
	//Base base(1.11);
	Derived derived(11.11, 12.12);
	derived.display();

	return 0;
}
