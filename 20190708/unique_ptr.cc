 ///
 /// @file    unique_ptr.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-08 14:50:13
 ///
 
#include <iostream>
#include <memory>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::unique_ptr;
 
class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{	cout << "Point(int,int)" << endl;	}

	void print() const 
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

	~Point() {	cout << "~Point()" << endl;	}

	friend std::ostream & operator<<(std::ostream & os, const Point & rhs);
private:
	int _ix;
	int _iy;
};
 
std::ostream & operator<<(std::ostream & os, const Point & rhs)
{
	os << "(" << rhs._ix
		 << "," << rhs._iy
		 << ")";
	return os;
}


 
int test0(void)
{
	Point * pt = new Point(1, 2);
	unique_ptr<Point> ap(pt);
	cout << "*ap = " << *ap << endl;
	cout << "ap.get() = " << ap.get() << endl;
	cout << "pt = " << pt << endl;

	//unique_ptr<Point> ap2(ap);//error, unique_ptr不能进行复制或者赋值
	unique_ptr<Point> ap2(std::move(ap));//ok
	cout << "*ap2 = " << *ap2 << endl;
	cout << "ap2.get() = " << ap2.get() << endl;
	//cout << "*ap = " << *ap << endl;
	//cout << "ap.get() = " << ap.get() << endl;

	unique_ptr<Point> ap3(new Point(3, 4));


	Point * pt2 = new Point(11, 12);
	ap3.reset(pt2);
	//ap3 = ap2;//error

#if 1
	cout << "*ap3 = " << *ap3 << endl;
	cout << "ap3.get() = " << ap3.get() << endl;
#endif

	return 0;
}

unique_ptr<Point> getPoint()
{
	unique_ptr<Point> up(new Point(22, 23));		
	cout << "*up = " << *up << endl;
	return up;//调用unique_ptr的移动构造函数
}

int test1()
{
	unique_ptr<Point> up = getPoint();
	//unique_ptr<Point> up2 = up;
	
	//unique_ptr可以放入容器之中，需要采用移动语义
	using PointPtr = unique_ptr<Point>;
	//vector<unique_ptr<Point>> points;// 可以替代指针容器
	vector<PointPtr> points;// 可以替代指针容器
	points.push_back(std::move(up));

	cout << "*points[0] = " << *points[0] << endl;

	points.emplace_back(new Point( 11, 2));
	cout << "*points[1] = " << *points[1] << endl;
	
	return 0;
}

int main(void)
{
	test1();
	return 0;
}
