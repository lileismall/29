 ///
 /// @file    AbstractClass.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-28 14:47:46
 ///
 
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

//抽象类的第二种形式：定义了protected构造函数的类称为抽象类
class Base
{
public:
	Base(const char * base)
	: _base(new char[strlen(base) + 1]())
	{	
		cout << "Base(double)" << endl;	
		strcpy(_base, base);
	}

	virtual
	void print() const 
	{	cout << "Base::_base = " << _base << endl;	}

	//规定: 一旦当类中定义了虚函数，都要将析构函数设为虚函数
	virtual
	~Base()  //只有一个
	{
		delete [] _base;
		cout << "~Base()" << endl;
	}

private:
	char * _base;
};

class Derived
: public Base
{
public:
	Derived(const char * base, const char * derived)
	: Base(base)
	, _derived(new char[strlen(derived) + 1]())
	{
		cout << "Derived(double,double)" << endl;
		strcpy(_derived, derived);
	}

	void print() const
	{	
		Base::print();
		cout << "Derived::_derived = " << _derived << endl;
	}

	~Derived()
	{
		delete [] _derived;
		cout << "~Derived()" << endl;
	}

private:
	char * _derived;
};


 
int main(void)
{
	Base * pbase = new Derived ("hello", "wolrd");
	pbase->print();
	delete pbase;//使用虚函数机制，调用到派生类的析构函数

//	Derived * pderived = (Derived*) pbase;
//	delete pderived;

	return 0;
}
