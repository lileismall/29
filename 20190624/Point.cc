 ///
 /// @file    Point.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-24 15:24:01
 ///
 
#include <math.h>
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
		cout << "Point(int,int)" << endl;
	}

	void print() const
	{
		cout << "(" << _ix
		     << "," << _iy
			 << ")" ;
	}
	
	//友元函数之普通函数
	friend float distance(const Point & lhs, const Point & rhs);
	

private:
	int _ix;
	int _iy;
};

float distance(const Point & lhs, const Point & rhs)
{
	return sqrt((lhs._ix - rhs._ix) * (lhs._ix - rhs._ix) + 
				(lhs._iy - rhs._iy) * (lhs._iy - rhs._iy));
}
 
int main(void)
{
	Point pt1(1, 2), pt2(3, 4);

	pt1.print();
	cout << " ---> ";
	pt2.print();
	cout << "的距离是:" << distance(pt1, pt2) << endl;

	return 0;
}
