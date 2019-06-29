 ///
 /// @file    VirtualFunction.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-29 11:06:01
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
	Base(long data): _data(data) {	}

	virtual void func1() const
	{	cout << "Base::func1()" << endl;	}

	virtual void func2() const
	{	cout << "Base::func2()" << endl;	}

	virtual void func3() const
	{	cout << "Base::func3()" << endl;	}

private:
	long _data;
};

 
int main(void)
{
	Base base(10);
	//base._data;

	long ** pvtable = (long**)&base;

	//虚函数表是存在的
	long address = pvtable[0][0];
	
	typedef void(*Function)();

	Function f = Function(address);
	f();

	f = Function(pvtable[0][1]);
	f();

	f = Function(pvtable[0][2]);
	f();

	cout << long(pvtable[1]) << endl;

	return 0;
}
