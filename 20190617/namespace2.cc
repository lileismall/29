 ///
 /// @file    namespace1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-17 14:51:45
 ///
 
#include <iostream>

using std::cout;// using声明机制, 简化操作, 不会把所有的实体引进来
using std::endl;
             
void wd_display();
void tls_display();


struct Example
{
	int x;
	int y;

};


//命名空间在一个文件之中可以出现多次
//相当于一个黑洞
namespace wd
{
int number = 10;
void show();//声明
}//end of namespace wd


namespace tls
{

void display()
{
	cout << "tls::display() " << endl;
	wd::show();
}

}//end of namespace tls

namespace wd
{
void display()
{
	cout << "wd::display() " << endl;
	tls::display();
}

void show()//实现
{
	cout << "wd::show()" << endl;
}

}//end of namespace wd



 
int main(void)
{
	wd::display();//::  作用域限定符
	tls::display();

	cout << "wd::number = " << wd::number << endl;

	return 0;
}
