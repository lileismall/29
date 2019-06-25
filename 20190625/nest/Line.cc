 ///
 /// @file    Point.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-24 15:24:01
 ///
 
#include "Line.h"

#include <math.h>
#include <iostream>
using std::cout;
using std::endl;

class Line::LineImpl
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

		~Point() {	cout << "~Point()" << endl;	}

	private:
		int _ix;
		int _iy;
	};

public:
	LineImpl(int x1, int y1, int x2, int y2)
	: _pt1(x1, y1)
	, _pt2(x2, y2)
	{	cout << "LineImpl(int,int,int,int)" << endl;}

	void printLine() const
	{
		_pt1.print();
		cout << " --> ";
		_pt2.print();
		cout << endl;
	}

	~LineImpl() {	cout << "~LineImpl()" << endl;	}
private:
	Point _pt1;
	Point _pt2;
};


Line::Line(int x1, int y1, int x2, int y2)
: _pimpl(new LineImpl(x1, y1, x2, y2))
{
	cout << "Line(int,int,int,int)" << endl;
}

Line::~Line()
{
	if(_pimpl)
		delete _pimpl;
}

void Line::printLine() const
{
	_pimpl->printLine();
}
