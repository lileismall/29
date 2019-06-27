 ///
 /// @file    oversee.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-27 14:32:49
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
	Base(int x)
	: _x(x) 
	{	cout << "Base(int)" << endl;	}

	void display() const
	{	
		cout << "Base::_x = " << _x << endl;
	}

protected:
	double _x;
};

class Derived
: public Base
{
public:
	Derived(int x1, int x2)
	: Base(x1)
	, _y(x2)
	{
		cout << "Derived(int,int)" << endl;
	}

	void display() const
	{
		cout << "Derived::_y = " << _y << endl;
	}

private:
	double _y;
};

//派生类能够适应基类(派生类的功能要多于基类)
//> 可以把一个派生类对象赋值给基类对象
//> 可以把一个基类指针指向派生类对象
//> 可以把一个基类引用绑定到派生类对象
 
int main(void)
{
	Base base(10);
	base.display();
	Derived derived(11, 20);

	//derived = base;//error Derived & operator=(const Derived& rhs)
				   //const Derived & rhs = base;

	base = derived;//Base & operator=(const Base &rhs)
				   //const Base & rhs = derived;
	base.display();

	Base * pbase = &derived;
	pbase->display();

	//Derived * pderived = &base;//error




	return 0;
}

