 ///
 /// @file    TemplateFunction.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-01 11:10:10
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//			 实例化
// 函数模板   ==》 模板函数
//		   模板参数推导
//
// 模板就是一个代码生成器
//		   

template <class T>
T add(T x, T y);//函数模板的声明


//函数模板与函数模板之间可以重载
template <class T>
T add(T x, T y, T z)
{
	cout << "T add(T, T, T) " << endl;
	return x + y + z;
}

//函数模板与普通函数可以重载, 普通函数优先于函数模板的执行


#if 0
int add(int x, int y)
{
	cout << "int add(int,int)" << endl;
	return x + y;
}
#endif

#if 0
template <class T1, class T2>
T1 add(T1 x, T2 y)
{
	return x + y;
}
#endif
 
int main(void)
{
	int x1 = 3, x2 = 4;
	double y1 = 1.11, y2 = 2.22, y3 = 3.33;
	char c1 = 'a', c2 = 2;
	cout << "add(x1, x2) = " << add(x1, x2) << endl;// 隐式实例化
	cout << "add(y1, y2) = " << add<double>(y1, y2) << endl;// 显式实例化
	cout << "add(c1, c2) = " << add(c1, c2) << endl;
	cout << "add(y1, y2, y3) = " << add(y1, y2, y3) << endl;
	//cout << "add(x1, y1) = " << add(x1, y1) << endl;//error

	return 0;
}


template <class T>
T add(T x, T y)
{
	cout << "T add(T,T) " << endl;
	return x + y;
}
