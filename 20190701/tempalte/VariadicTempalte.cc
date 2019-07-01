 ///
 /// @file    VariadicTempalte.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-01 14:34:41
 ///
 
#include <iostream>
using std::cout;
using std::endl;

template <class... Args> // Args 模板参数包
void print(Args... args) // args 函数参数包
{
	cout << sizeof...(Args) << endl;
	cout << sizeof...(args) << endl;
}


#if 0
void display()
{
	cout << endl;
}
#endif

template <class T>
void display(T t)
{
	cout << t << endl;
}

template <class T, class... Args>
void display(T t, Args... args)
{
	cout << t << endl;
	display(args...);// 函数参数包的展开(拆包)
}

 
int main(void)
{
	//print(10, 11.11, 'a', "hello");
	display(10, 11.11, 'a', "hello");
	//	cout << 10 << endl;
	//	display(11.11, 'a', "hello");
	//		cout << 11.11 << endl;
	//		display('a', "hello");
	//			cout << 'a' << endl;
	//			display("hello");
	//				cout << "hello" << endl;
	//				display();

	return 0;
}
