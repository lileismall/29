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

	void setX(int ix)
	{	_ix = ix;	}


	void print()
	{
		cout << "(" << this->_ix
			 << "," << this->_iy
			 << ")";
	}

	~Point()
	{
		cout << "~Point()" << endl;
	}

private:
	int _ix;
	int _iy;
};

class Line
{
public:
	//对象成员都要放在初始化列表中进行初始化
	//即使忘记了，也会自动调用相应类型的默认构造函数
	Line(int x1, int y1, int x2, int y2)
	: _pt1(x1, y1)
	, _pt2(x2, y2)
	{
		cout << "Line(int,int,int,int)" << endl;
	}

	void printLine()
	{
		_pt1.print();
		cout << " ---> ";
		_pt2.print();
		cout << endl;
	}
private:
	Point _pt1;
	Point _pt2;
};


 
int main(void)
{
	Line line(1, 2, 3, 4);
	line.printLine();

	return 0;
}
