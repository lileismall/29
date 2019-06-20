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
	Point()
	: _ix(0)
	, _iy(0)
	{
		cout << "Point()" << endl;
	}

	Point(int ix, int iy)
	: _ix(ix)   
	, _iy(iy)
	{
		cout << "Point(int,int)" << endl;
	}

	void setX(int ix)
	{	_ix = ix;	}


#if 0
	void print(/*     Point * const this    */)
	{
		//非const版本的成员函数是可以修改成员的
		//this = 0x1000;
		_ix = 100;

		cout << "void print()" << endl;
		cout << "(" << this->_ix
			 << "," << this->_iy
			 << ")" << endl;
	}
#endif

	//以后只要某一个函数不会对数据成员进行修改，都要将其设置为
	//const成员函数
#if 1
	void print(/*  const Point * const this    */) const
	{
		//_ix = 100;//error
		cout << "void print() const" << endl;
		cout << "(" << this->_ix
			 << "," << this->_iy
			 << ")" << endl;
	}
#endif

	~Point()
	{
		cout << "~Point()" << endl;
	}

private:
	int _ix;
	int _iy;
};

void func1(const Point & rhs)
{
	rhs.print();
}


 
int main(void)
{

	//Point pt1(1, 2);//非const对象调用的是非const成员函数
	//cout << "pt1 = ";//非const对象也可以调用const成员函数
	//pt1.print();

	//const Point pt2(3, 4);//const对象只能调用的const成员函数
	//pt2.print();

	//func1(pt1);
	
	Point points[5] = {
		Point(1, 2),
		Point(3, 4)
	};

	points[0].print();
	points[2].print();

	return 0;
}
