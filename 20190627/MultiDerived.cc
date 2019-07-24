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
	A() {	cout << "A()" << endl;}	
	void print() const
	{	cout << "A::print()" << endl;	}

private:
	int _a;
};

class B
{
public:
	B() {	cout << "B()" << endl;}	
	void display() const
	{	cout << "B::display()" << endl;}

private:
	int _b;
};

class C
{
public:
	C() {	cout << "C()" << endl;}	

	void show() const
	{
		cout << "C::show()" << endl;
	}

private:
	int _c;
};

//默认情况下是private继承
class D
: public A
, public B
, public C
{
public:
	D()
	: A()
	, B()
	, C()
	{
	
	}

private:
	int _d;
};

 
int main(void)
{
	D d;
	d.print();
	d.display();
	d.show();

	return 0;
}
