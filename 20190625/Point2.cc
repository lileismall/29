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

	operator int()
	{
		return _ix;
	}

#if 0
	operator double()
	{
		return _ix * _iy;
	}
#endif
	

	//friend std::ostream & operator<<(std::ostream & os, const Point& rhs);
private:
	int _ix;
	int _iy;
};

#if 0
std::ostream & operator<<(std::ostream &os, const Point & rhs)
{
	os << "(" << rhs._ix
	   << "," << rhs._iy
	   << ")";
	return os;
}
#endif
 
int main(void)
{
	Point pt1(1, 2), pt2(3, 4);

	cout << "pt1 = " << pt1 << endl;

	return 0;
}
