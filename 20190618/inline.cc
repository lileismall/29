 ///
 /// @file    inline.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-18 10:13:28
 ///
 
#include <iostream>
using std::cout;
using std::endl;

#define MAX(x,y) ((x)>(y)?(x):(y))

//带参数的宏定义过程中，容易犯错误
#define MULTIPY(x,y) ((x)*(y))

int test0(void)
{
	int a = 3, b = 4, c = 5;
	printf("MAX(a, b) = %d\n", MAX(a, b));

	cout << "MAX(a, b) = " << MAX(a,b) << endl;

	printf("(a + b) * c = %d\n", MULTIPY(a+b, c));
	return 0;
}

//inline函数的功能与带参数的宏定义效果一样

//尽量用inline函数替换带参数的宏定义
inline int max(int x, int y)
{
	return x > y ? x : y;
}

inline int multiply(int x, int y)
{
	return x * y;
}

void test1()
{
	int a = 3, b = 4, c = 5;

	cout << "MAX(a, b) = " << max(a,b) << endl;

	cout << "(a + b) * c = " << multiply(a + b, c) << endl;
}

int main()
{
	test1();
	return 0;
}

