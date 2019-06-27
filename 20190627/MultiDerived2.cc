 ///
 /// @file    MultiDerived.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-27 10:16:39
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A
{
public:
	void print() const
	{	cout << "A::print()" << endl;	}

};

class B
{
public:
	void print() const
	{	cout << "B::display()" << endl;}

};

class C
{
public:
	void print() const
	{
		cout << "C::show()" << endl;
	}
};

//默认情况下是private继承
class D
: public A
, public B
, public C
{
};

 
int main(void)
{
	D d;
	//d.print();//成员名访问冲突的二义性
	d.A::print();//解决方案： 直接使用作用域限定符
	d.B::print();
	d.C::print();

	return 0;
}
