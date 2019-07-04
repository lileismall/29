 ///
 /// @file    bind.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-04 14:53:45
 ///
 
#include <iostream>
#include <functional>
using std::cout;
using std::endl;
using std::bind;

int add(int x, int y, int z)
{
	cout << "int add(int,int,int)" << endl;
	return x + y + z;
}

class Example
{
public:
	int add(int x, int y, int z)
	{
		cout << "int Example::add(int,int,int)" << endl;
		return _data + x + y + z;
	}

	int _data = 10;
};

void test0()
{
	//参数全部提前绑定
	auto f1 = bind(add, 1, 10, 20);
	cout << "f1() = " << f1() << endl;

	//占位符:  不需要提前绑定的参数，需要使用占位符
	using namespace std::placeholders;
	//auto f2 = bind(add, 1, std::placeholders::_1, std::placeholders::_2);
	auto f2 = bind(add, 1, _3, _2);
	//cout << "f2(2, 3) = " << f2(2, 3) << endl;
	cout << "f2(2, 3, 4) = " << f2(2, 3, 4) << endl;
}

void display(int n1, int n2, int n3, const int & n4, int n5)
{
	cout << "(" << n1
	     << "," << n2
	     << "," << n3
	     << "," << n4
	     << "," << n5 
		 << ")" << endl;
}

void test1()
{
	using namespace std::placeholders;
	int x = 10, y = 20;
	//bind提前绑定参数时采用的是值传递
	//占位符本身所在的位置是形参的位置,
	//占位符本身的数字代表的是函数调用时参数的位置
	//
	//
	//auto f = bind(display, _1, _2, x, std::cref(y), y);

	//bin提前绑定参数之后，可以改变函数类型
	std::function<void(int,int)> f = bind(display, _1, _2, x, std::cref(y), y);
	y = 22;
	//f(111, 112, 333, 1, 2, 3, 4, 5, 6);
	f(111, 112);
}

void test3()
{
	//bin提前绑定参数之后，可以改变函数类型
	using namespace std::placeholders;
	std::function<int(int,int)> f = bind(add, _1, _2, 100);
	cout << "f(1, 2) = " << f(1, 2) << endl;

	{
	Example e;
	f = bind(&Example::add, &e, _1, 200, _2);
	cout << "f(1, 2) = " << f(1, 2) << endl;
	}
	//error, 指定的对象已经被销毁了，使用会出问题
	cout << "f(1, 2) = " << f(1, 2) << endl;
	
	//对于成员函数而言， 绑定的第一个参数就是this指针,
	//提前绑定时，可以传递指针，也可以传递对象
	Example e;
	f = bind(&Example::add, e, _1, 200, _2);
	cout << "f(1, 2) = " << f(1, 2) << endl;
}

int main(void)
{
	//test0();
	//test1();
	test3();
	return 0;
}
