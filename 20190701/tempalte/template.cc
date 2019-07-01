 ///
 /// @file    template.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-01 11:46:45
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//模板参数列表之中可以使用的参数有两类:
//1. 类型参数
//2. 非类型参数，整型数据, (bool/char/short/int/long/long long)
//
//这两类参数都可以设置默认值, C++11之后支持
template <class T = int, int Number = 10>
T mutiply(T x, T y)
{
	return Number * x * y;
}
 
int main(void)
{
	int a = 3, b = 4;
	cout << "mutiply(x, y) = " << mutiply<int, 20>(a, b) << endl;
	cout << "mutiply(x, y) = " << mutiply(a, b) << endl;
	return 0;
}
