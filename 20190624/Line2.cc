 ///
 /// @file    Point.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-24 15:24:01
 ///
 
#include <math.h>
#include <iostream>
using std::cout;
using std::endl;

class Point;//类的前向声明

class Line
{
public:
	float distance(const Point & lhs, const Point & rhs);
	void setPoint(Point * pt, int ix, int iy);

	void setZ(int iz) {	_iz = iz;	}

private:
	int _iz;
};

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int,int)" << endl;
	}

	void print() const
	{
		cout << "(" << _ix
		     << "," << _iy
			 << ")" ;
	}

#if 0
	void setZ(Line * line, int iz)
	{	line->_iz = iz;	}
#endif
	
	//友元函数之友元类
	friend class Line;

private:
	int _ix;
	int _iy;
};

//A -> B,  B -> C, A -> C

//在C++中，友元确实破坏了类的封装性；
//但其使用是受到限制的，友元是单向的, 不具备传递性, 不能被继承
//
//友元是一把双刃剑，不要滥用

float Line::distance(const Point & lhs, const Point & rhs)
{
	return sqrt((lhs._ix - rhs._ix) * (lhs._ix - rhs._ix) + 
				(lhs._iy - rhs._iy) * (lhs._iy - rhs._iy));
}
 
void Line::setPoint(Point * pt, int ix, int iy)
{
	pt->_ix = ix;
	pt->_iy = iy;
}

int main(void)
{
	Point pt1(1, 2), pt2(3, 4);

	pt1.print();
	cout << " ---> ";
	pt2.print();
	Line line;
	cout << "的距离是:" << line.distance(pt1, pt2) << endl;//匿名对象, 临时对象

	cout << "修改pt2:" << endl;
	line.setPoint(&pt2, 6, 6);
	cout << "pt2 = ";
	pt2.print();
	cout << endl;

	return 0;
}
