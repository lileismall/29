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
	Point(int ix = 0, int iy = 0)
	: _ix(ix)   
	, _iy(iy)
	{
		cout << "Point(int=0,int=0)" << endl;
	}

	//系统提供的复制构造函数
	//问题1： 形参中的引用符号不能删除，如果删除，
	//会造成复制构造函数无穷递归调用，直到栈溢出，程序崩溃
	//
	//问题2:  形参中的const关键字可以去掉不?
	//	不可以去掉，如果去掉，当传递过来的参数是右值时，就会
	//	报错
	//Point(const Point rhs)：
	//Point(Point & rhs)
	Point(const Point & rhs)  //复制构造函数形式是固定的
	: _ix(rhs._ix)
	, _iy(rhs._iy)
	{
		cout << "Point(const Point & )" << endl;
	}

	void print()
	{
		cout << "(" << _ix
			 << "," <<_iy
			 << ")" << endl;
	}

private:
	int _ix;
	int _iy;
};

//形参与实参都是对象（值传递），会调用复制构造函数
void func1(Point pt)
{
	cout << "pt = ";
	pt.print();
}

//函数的返回值是对象时，执行return语句
//也会调用复制构造函数；但一般情况下，会
//被编译器优化掉；如要要看到完整形式，需要
//在编译时 加上编译选项  -fno-elide-constructors
Point func2()
{
	Point pt(11, 12);
	cout << ">> pt = ";
	pt.print();
	return pt;
}

 
int main(void)
{
	int a = 3;
	int b = a;

	//int & ref = 1;//字面值常量, 非const引用不能绑定到右值
	const int & ref2 = 1;// const引用可以绑定到右值
	cout << "ref2 = " << ref2 << endl;

	Point pt1(1, 2);
	cout << "pt1 = ";
	pt1.print();

	//Point(const Point rhs);
	//	const Point rhs = pt1;
	//	Point(const Point rhs);
	//		const Point rhs = pt1;
	Point pt2 = pt1;//调用复制（拷贝）构造函数
	cout << "pt2 = ";
	pt2.print();
	cout << "----" << endl << endl;

	func1(pt2);
	cout << "----" << endl << endl;
	
	func2();//临时对象, 右值

	Point pt3 = func2();//Point(Point & rhs);
						//非const引用无法绑定到右值
						//Point & rhs = func2();
	pt3.print();
	cout << "----" << endl << endl;
	func2().print();

	return 0;
}
