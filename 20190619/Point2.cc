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
		///_ix = ix;//error
		//_iy = iy;
	}


	void print()
	{
		cout << "(" << this->_ix
			 << "," << this->_iy
			 << ")" << endl;
	}

	~Point()
	{
		cout << "~Point()" << endl;
	}

private:
	const int _ix;
	const int _iy;
};


 
int main(void)
{

	Point pt1(1, 2);
	cout << "pt1 = ";
	pt1.print();

	return 0;
}
