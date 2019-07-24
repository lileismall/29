 ///
 /// @file    bracelet.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-24 17:24:47
 ///
 
#include <iostream>
using std::cout;
using std::endl;

void func1(int x)
{
	static int cnt = 0;
	++cnt;
	cout << "func1(int) x = " << x << endl;
	cout << " func1 has been called " << cnt << " times." << endl;
}

struct Example
{
	int operator()(int x, int y)
	{
		++cnt;
		cout << " operator()(int,int) has been called " << cnt << " times" << endl;
		return x + y;
	}

	int operator()(int x, int y, int z)
	{
		return x * y * z;
	}

	int cnt = 0;//函数对象携带的状态 => 闭包 => lambda表达式 => 匿名函数
};
 
int main(void)
{

	Example example;
	int a = 3, b = 4, c = 5;
	//重载了函数调用运算符的类创建的对象称为函数对象
	cout << "example(a, b) = " << example(a, b) << endl;
	cout << "example(a, b, c) = " << example(a, b, c) << endl;
	cout << "example(a, b) = " << example(a, b) << endl;

	Example example2;

	func1(a);
	func1(a);

	auto f1 = [](int number){
		cout << "lambda expression" << endl;
		cout << "number = " << number << endl;
	};
	f1(a);

	return 0;
}
