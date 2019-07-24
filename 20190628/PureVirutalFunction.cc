 ///
 /// @file    PureVirutalFunction.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-28 11:40:34
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//面向抽象编程:
//	只要接口不变，扩展随便实现
//
//开闭原则:
//	对修改关闭，对扩展开放
class A
{
public:
	//纯虚函数就是没有实现，只作为接口存在
	//定义了纯虚函数的类称为抽象类
	virtual void display()=0;

	virtual void print()=0;

	virtual
	~A() { cout << "~A()" << endl;	}
};

class B
: public A
{//当一个类继承了抽象类之后，它必须实现所有的纯虚函数
//如果有一个纯虚函数没有实现，该派生类也会成为抽象类
public:
	void display()
	{	cout << "B::display()" << endl;	}

	~B() {	cout << "~B()" << endl;	}
};

class C
: public B
{
public:
	void print()
	{	cout << "C::print()" << endl;	}

	~C()
	{	cout << "~C()" << endl;	}
};

void display(A * pa)
{
	pa->display();
}
 
int main(void)
{
	//A a;//error;
	//B b;
	//A * pa = &b;
	//pa->display();
	
#if 0
	C c;
	A * pa = &c;
	pa->display();
	pa->print();
#endif

	A * pa2 = new C();
	pa2->display();
	pa2->print();

	delete pa2;
 
	return 0;
}
