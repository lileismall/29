 ///
 /// @file    namespace3.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-17 15:15:05
 ///

//代码风格的限定  ==> code review 代码走查

//#include "myhead.h" //自定义头文件放在C头文件的上面

#include <stdio.h>    //头文件的顺序: C的头文件放在C++头文件的前面
#include <stdlib.h>

#include <iostream>

using std::cout;//选择区域
using std::endl;

int number = 10;

namespace wd
{
int number = 100;


namespace lwh
{

void display()
{
	cout << "wd::lwh::display()" << endl;
}
}//end of namespace lwh

}//end of namespace wd

namespace tls
{
int number = 1000;

void display(int number)//形参number会其他的number
{
	cout << "number = " << number << endl;
	cout << "wd::number = " << wd::number << endl;
	cout << "tls::number = " << tls::number << endl;
	cout << "全局变量 number = " << ::number << endl;//匿名命名空间
}

}//end of namespace tls
             
 
int test0(void)
{
	using wd::lwh::display;
	display();
	return 0;
}

int main(void)
{
	//display();
	test0();
	return 0;
}
