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

	//系统提供
	Point & operator=(const Point & rhs)
	//void operator=(const Point & rhs)
	{
		cout << "Point & operator=(const Point & )" << endl;
		this->_ix = rhs._ix;
		this->_iy = rhs._iy;
		return *this;
	}


	//this指针代表的是当前对象
	void print(/*    Point * const this    */)
	{
		//this = 0x1000;//error
		cout << "(" << this->_ix
			 << "," << this->_iy
			 << ")" << endl;
	}

private:
	int _ix;
	int _iy;
};


 
int main(void)
{
	int a = 3;
	int b = a;
	int c = 4;
	int d = 5;

	a = (c = (b = d));


	//int & ref = 1;//字面值常量, 非const引用不能绑定到右值
	const int & ref2 = 1;// const引用可以绑定到右值
	cout << "ref2 = " << ref2 << endl;

	Point pt1(1, 2);
	cout << "pt1 = ";
	pt1.print();

	Point pt2(3, 4);
	cout << "pt2 = ";
	pt2.print();// Point::print(&pt2);

	Point pt3(5, 6);

	pt2 = pt1 = pt3;//系统提供了赋值运算符函数
	pt2.operator=(pt1);// Point::operator=(&pt2, pt1);
	cout << "pt2 = ";
	pt2.print();


	return 0;
}
