 ///
 /// @file    Point.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-18 15:57:18
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
#if 1
	//当没有显式定义构造函数时，系统会自动提供一个
	//默认构造函数
	Point()
	{
		_ix = 0;
		_iy = 0;
		cout << "Point()" << endl;
	}
#endif

#if 1
	//构造函数可以重载
	//
	//如果显式定义了有参构造函数时，系统就
	//不会再自动提供默认构造函数
	//
	//如果还希望通过默认构造函数创建对象，则必须
	//显式提供一个默认构造函数
	//
	Point(int ix, int iy)
	{
		_ix = ix;
		_iy = iy;
		cout << "Point(int,int)" << endl;
	}
#endif

	void print()
	{
		cout << "(" << _ix
			 << "," <<_iy
			 << ")" << endl;
	}

	// 析构函数没有返回值，函数名与类名相同，同时还需要在前面
	// 加上一个波浪号,与构造函数进行区分；
	// 析构函数没有形参, 析构函数只有一个
	//
	// 当一个对象的生命周期结束的时候，会自动调用析构函数
	//
	
	//系统提供的析构函数
	~Point()
	{}

#if 0
	~Point()
	{
		cout << "~Point()" << endl;
	}
#endif

private:
	int _ix;
	int _iy;
};
 
int main(void)
{
	//Point pt1(1, 2);
	//pt1.print();

	Point pt2;//调用无参(默认)构造函数
	pt2.print();

	return 0;
}
