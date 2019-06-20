 ///
 /// @file    const.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-17 15:51:41
 ///
 
#include <iostream>
using std::cout;
using std::endl;



//编辑  --> 预处理(预编译) --> 编译 --> 汇编 --> 链接 --> 可执行程序
//			  -E                -S       as      -o
//
//概念 ==》沟通
//
//怎么表示学会了一个知识点?
//   完成任务 --> 讲出来 --> 别人还能够听的懂
//   
//
//宏定义与const的区别？(概念题是最容易丢分)
//1. 发生时机不一样: 宏定义发生在预处理时，const关键字发生编译时
//2. 宏定义仅仅只做了字符串的替换，没有类型检查; const关键字有类型
//检查，可以提前发现错误
//3. const关键字更推荐使用; 因为使用const关键字可以减小犯错误的概率
#define NUMBER 1024

void test0()
{
	cout << "NUMBER = " << NUMBER << endl;
}

void test1()
{
	const int number = 1;
	cout << ">> number = " << number << endl;

	number = 10;

	//const int number2;//error, 必须要进行初始化
}



//常量指针   指针常量
//
// int(*)[5]   int *[5]   
//数组指针    指针数组
//
//int(*p)()    int* p()
//函数指针   指针函数


void test2()
{
	int number = 10;
	int number2 = 100;
	int * p1 = &number;
	cout << "*p1 = " << *p1 << endl;
	cout << "&p1 = " << &p1 << endl;

	const int * p2 = &number;//常量指针(pointer to const)
	cout << "*p2 = " << *p2 << endl;
	cout << "&p2 = " << &p2 << endl;
	//*p2 = 100;//error 不能通过该指针修改所指变量的值
	p2 = &number2;//可以改变其指向
	cout << "*p2 = " << *p2 << endl;

	int const * p3 = &number;
	//*p3 = 1000;//error
	p3 = &number2;//可以改变其指向

	int * const p4 = &number;//指针常量(const pointer)
	*p4 = 1000;//可以通过该指针改变所指变量的值
	//p4 = &number2;//error 不能改变指向
	
	//两者都不能修改
	const int * const p5 = &number;
}

 
int main(void)
{
	//test0();
	test1();
	//test2();

	return 0;
}
