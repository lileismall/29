 ///
 /// @file    PointerContainer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-05 10:01:28
 ///
 
#include <iostream>
#include <vector>
#include <boost/ptr_container/ptr_container.hpp>
using std::cout;
using std::endl;
using std::vector;
 
class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int,int)" << endl;
	}

	Point(const Point & rhs)
	: _ix(rhs._ix)
	, _iy(rhs._iy)
	{
		cout << "Point(const Point & rhs)" << endl;
	}

	void print() const
	{
		cout << "(" << _ix
		     << "," << _iy
			 << ")" << endl;
	}

	void setX(int ix) {	_ix = ix;	}
	void setY(int iy) {	_iy = iy;	}

	~Point()
	{
		cout << "~Point()" << endl;
	}

private:
	int _ix;
	int _iy;
};


int test0(void)
{

	vector<Point *> points
	{
		new Point(1, 2),
		new Point(3, 4),
		new Point(5, 6)
	};


	for(auto it = points.begin(); it != points.end(); ++it) {
		(*it)->print();
	}

	return 0;
}

int test1()
{
	//指针容器
	boost::ptr_vector<Point> points;
	points.push_back(new Point(1, 2));
	points.push_back(new Point(3, 4));

	for(auto it = points.begin(); it != points.end(); ++it) {
		//(*it).print();
		it->print();
	}

	return 0;
}

int test2()
{
	//空间的分配与对象的创建是分离的
	vector<Point> numbers;
	numbers.reserve(100);

	Point pt(1, 2);
	numbers.push_back(pt);//对pt进行了复制的

	numbers[0].setX(10);
	numbers[0].setY(11);

	cout << "numbers[0] = ";
	numbers[0].print();

	cout << "pt = ";
	pt.print();

	//Point * pt = new Point(1, 2);

	return 0;
}

int main(void)
{
	//test1();
	test2();
}
