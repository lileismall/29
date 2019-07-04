 ///
 /// @file    bind.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-04 14:32:25
 ///
 
#include <iostream>
#include <functional>
using std::cout;
using std::endl;
using std::function;

void display()
{
	cout << "display()" << endl;
}

void print()
{
	cout << "print()" << endl;
}

//
//函数类型   void()
//
void (* pointer)() = display;

typedef void(* Function)();



void test0()
{
	pointer();

	Function f = display;//注册回调函数

	f();//执行回调函数

	f = print;
	f();
}
 
//用C语言表达多态的特性
void FunctionCall(function<void()> f)
{
	f();
}


class Example
{
public:
	void display() const
	{
		cout << "Example::display()" << endl;
	}
};

void test1()
{
	FunctionCall(display);
	FunctionCall(print);
	//FunctionCall(Example::display);
}

void test2()
{
	//std::function函数的容器，可以容纳某一种函数类型的函数
	//
	//函数的形式可以是任意形式
	//	> 普通函数
	//	> 函数指针
	//	> 成员函数
	//
	Function f = print;
	function<void()> f1 = display;
	f1();
	f1 = f;
	f1();

	Example e;
	//.f1 = bind1st(Example::display, &e);
	f1 = std::bind(&Example::display, &e);
	f1();
}

int main(void)
{
	//test1();
	test2();

	return 0;
}
