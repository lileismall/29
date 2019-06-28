 ///
 /// @file    VirtualFunction.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-27 16:02:12
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:

	//构造函数不能被声明为虚函数,为什么？
	//virtual
	Base(double base)
	: _base(base)
	{	cout << "Base()" << endl;	}

	virtual 
	void display() const
	{
		cout << ">> base = " << _base << endl;
	}

private:
	double _base;
};

class Child1
: public Base
{
public:
	Child1(double base, double child)
	: Base(base)
	, _child1(child)
	{
		cout << "Child(double, double)" << endl;
	}

	//对于派生类而言，当派生类重定义基类的虚函数时，
	//即使在其前面没有加上virtual，它也是虚函数
	
#if 1
	virtual
	void display(int idx) const//改参数相当于是一个新的函数
	//void display() const
	{
		cout << ">> _child1 = " << _child1 << endl;
		//return 0;
	}
#endif

private:
	double _child1;
};

class Child2
: public Base
{
public:
	Child2(double base, double child)
	: Base(base)
	, _child2(child)
	{
		cout << "Child(double, double)" << endl;
	}

	void display() const
	{
		cout << ">> _child2 = " << _child2 << endl;
	}

private:
	double _child2;
};


//派生类重定义基类虚函数时，必须与基类的虚函数完全保持一致

//虚函数的实现原理:
// 当类中定义了虚函数时，在其对象的存储布局之中会多一个虚函数指针
//   该虚函数指针指向了一张虚函数表，虚函数表中存放的就是虚函数的入口地址
//
//如何激活动态多态的特性(虚函数机制被激活的条件)? 
//1. 基类要定义虚函数，派生类要重定义（覆盖）虚函数
//2. 创建派生类对象
//3. 用基类指针(引用)指向派生类对象
//4. 用基类指针(引用)调用虚函数
//

//动态多态: 在运行时才会看到效果
//当发生动态多态时，调用的函数与指针本身的类型无关，
//只与其所指对象有关
//
void display(Base * pbase)
{
	pbase->display();
}

int main(void)
{
	cout << "sizeof(Base) = " << sizeof(Base) << endl;
	cout << "sizeof(Child1) = " << sizeof(Child1) << endl;
	cout << "sizeof(Child2) = " << sizeof(Child2) << endl;

	Base base(1);
	Child1 child1(11, 12);
	Child2 child2(21, 22);

	display(&base);
	display(&child1);
	display(&child2);

	Child1 * p = &child1;
	p->display(1);

	return 0;
}
 
