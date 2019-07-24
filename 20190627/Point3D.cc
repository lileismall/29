 ///
 /// @file    Point3D.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-27 09:44:44
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
		cout << "Point(int,int)" << endl;
	}

	void display() const
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

protected://对派生类内部开放的
	int getX() const
	{	return _ix; }

	int _iy;

private:
	int _ix;	
};

class Point3D
: public Point //接口继承
{
public:
	Point3D(int ix, int iy, int iz)
	: Point(ix, iy)
	, _iz(iz)
	{
		cout << "Point(int,int,int)" << endl;
	}

	void print() const
	{
		//cout << "(" << _ix // 派生类内部不能访问基类的私有成员
		cout << "(" << getX() // protected 
			 << "," << _iy //protected 派生类内部可以访问基类的非私有成员 
			 << "," << _iz
			 << ")" << endl;
	}


private:
	int _iz;
};
 
int main(void)
{
	Point3D pt1(1, 2, 3);
	pt1.display();//display在派生类内部还是public的，派生类对象只能访问基类的public成员
	//pt1.getX();//error
	//pt1._ix;//error

 
	return 0;
}
