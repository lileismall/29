 ///
 /// @file    VirtualFunction5.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-28 11:22:22
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Grandpa
{
public:
	Grandpa()
	{	cout << "Grandpa()" << endl;	}

	virtual void func1() {	cout << "void Grandpa::func1()" << endl;	}
	virtual void func2() {	cout << "void Grandpa::func2()" << endl;	}

	//静态成员函数不能直接访问虚函数，因为其没有this指针,
	//而虚函数的调用是要有this指针的
	//static void func3()
	static void func3(Grandpa * pointer)
	{
		//func1();//error
		pointer->func1();
	}

	~Grandpa() {	cout << "~Grandpa()" << endl;	}

};
 
class Parent 
: public Grandpa
{
public:
	Parent()
	{	
		cout << "Parent()" << endl;	
		func1();//静态联编, 不会表现动态多态特性
	}

	//virtual void func1() {	cout << "void Parent::func1()" << endl;	}
	//virtual void func2() {	cout << "void Parent::func2()" << endl;	}

	~Parent() 
	{	
		cout << "~Parent()" << endl;	
		func2();
	}

};

class Son
: public Parent
{
public:
	Son() 
	: Parent()
	{	cout << "Son()" << endl;	}

	virtual void func1() {	cout << "void Son::func1()" << endl;	}
	virtual void func2() {	cout << "void Son::func2()" << endl;	}

	~Son() {	cout << "~Son()" << endl;	}
};

int main(void)
{
	Son son;

	return 0;
}
