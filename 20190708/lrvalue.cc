 ///
 /// @file    lrvalue.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-08 11:06:30
 ///
 
#include <iostream>
#include <string>
using std::cout;
using std::endl;
 
using std::string;
int main(void)
{
	int a = 1, b = 2;
	//&(a++);//error   右值
		  // Complex operator++(int)	
		  //
	&(++a);// Complex & operator();
	//&(a + b);//error 右值
	//&100;//error 右值
	
	string s1("hello");
	string s2("world");
	&(s1 + s2);//error

	&string("hello");//error
	&string();//error
 
	//万能引用,
	//作为函数参数时，不能区分出传递过来的是左值还是右值
	const int & m = 1;
	const int & n = a;

	//C++11提出的是右值引用, 做转移操作
	
	int && ref = 1;//右值引用只能绑定到右值
	int && ref2 = a; //error 不能绑定到左值

	return 0;
}
