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
	{	cout << "A::print() _a = " << _a << endl;	}

private:
	double _a;
};

class B
: //virtual 
public A
{

private:
	double _b;
};

class C
: //virtual 
public A
{

	double _c;
};

class D
: public B
, public C
{

	double _d;
};

 
int main(void)
{
	cout << "sizeof(A) = " << sizeof(A) << endl;
	cout << "sizeof(B) = " << sizeof(B) << endl;
	cout << "sizeof(C) = " << sizeof(C) << endl;
	cout << "sizeof(D) = " << sizeof(D) << endl;

	D d;
	//d.print();//存储布局的二义性
	d.B::print();//解决方案: 采用虚拟继承
	d.C::print();

	return 0;
}
