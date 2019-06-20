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
	: _ix(ix)   //对于数据成员的初始化，都要放在初始化表达式之中进行
	, _iy(iy)
	{
		//_ix = ix;//赋值语句
		//_iy = iy;
		cout << "Point(int=0,int=0)" << endl;
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
 
int main(void)
{
	Point pt1(1, 2);
	pt1.print();

	Point pt2;//调用无参(默认)构造函数
	pt2.print();

	return 0;
}
