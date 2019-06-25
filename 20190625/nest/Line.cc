 ///
 /// @file    Point.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-24 15:24:01
 ///
 
#include <math.h>
#include <iostream>
using std::cout;
using std::endl;

class Line
{
	//Point类只为Line服务
	//
	//希望隐藏Point的实现 ==> 设计模式 pimpl
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

	private:
		int _ix;
		int _iy;
	};


public:
	Line(int x1, int y1, int x2, int y2)
	: _pt1(x1, y1)
	, _pt2(x2, y2)
	{	cout << "Line(int,int,int,int)" << endl;}

	void printLine() const
	{
		_pt1.print();
		cout << " --> ";
		_pt2.print();
		cout << endl;
	}
private:
	Point _pt1;
	Point _pt2;
};
 
int main(void)
{
	Line::Point pt(1, 2);//error

	Line line(11, 12, 13, 14);
	line.printLine();

	return 0;
}
