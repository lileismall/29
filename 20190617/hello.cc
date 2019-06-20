 ///
 /// @file    hello.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-17 14:44:32
 ///
 
#include <stdio.h>  //c标准头文件带有.h后缀
#include <iostream> //C++标准头文件没有后缀.h
					//是用模板实现的, 必须要知道其实现
					
using namespace std;//命名空间
 
int main(int argc, char ** argv)
{
	printf("hello,world!\n");//标准库函数
	cout << "hello,world!" << endl;//cout 对象, 输出流运算符
	//  operator<<(cout, "hello,world!");
	return 0;
}
