 ///
 /// @file    unordered_set.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-02 15:11:15
 ///
 
#include <math.h>
#include <iostream>
#include <unordered_set>
using std::cout;
using std::endl;
using std::unordered_set;

template <class Container>
void display(const Container & c)
{
	for(auto & elem : c) {
		cout <<  elem << " ";
	}
	cout << endl;
}

void test0()
{
	//unordered_set不能存放关键字相同的元素
	//
	//元素是无序的
	//
	unordered_set<int> numbers{3, 2, 5, 7, 9, 2, 3, 1, 3};

	display(numbers);
}
 
class Point
{
public:
	Point(int ix, int iy)
	: _ix(ix)
	, _iy(iy)
	{	cout << "Point(int,int)" << endl;	}


	Point(const Point & rhs)
	: _ix(rhs._ix)
	, _iy(rhs._iy)
	{
		cout << "Point(const Point &)" << endl;
	}

	~Point() {	cout << "~Point()" << endl;	}

	double getDistance() const
	{
		return sqrt(_ix * _ix + _iy * _iy);
	}

	int getX() const {	return _ix;	}
	int getY() const {	return _iy;	}

	friend std::ostream & operator<<(std::ostream & os, const Point & rhs);
	friend bool operator==(const Point & lhs, const Point & rhs);
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

namespace std
{
template <>
struct hash<Point>
{
	size_t operator()(const Point & point) const
	{
		return  (point.getX() * point.getX()- 1) ^ 
				(point.getY() * point.getY()- 1);
	}
};

}//end of namespace std

struct PointHasher
{
	size_t operator()(const Point & point) const
	{
		return  (point.getX() * point.getX()- 1) ^ 
				(point.getY() * point.getY()- 1);
	}
};

bool operator==(const Point & lhs, const Point & rhs)
{
	return lhs._ix == rhs._ix && lhs._iy == rhs._iy;
}

void test1()
{
	//空间的消耗是元素的2倍 
	//
	//以空间换时间
	//
	//hash表， 填充因子  0.5  rehash
	//
	//unordered_set<Point> points{
	unordered_set<Point, PointHasher> points{
		Point(1, 2),
		Point(3, 4),
		Point(5, 6),
		Point(7, 8),
		Point(3, 4)
	};
	display(points);
	auto it = points.begin();
	++it;// 只支持向前遍历

	auto it2 = points.end();
	//--it;//error 不支持向后进行遍历
	
	//points[0];//error
	
	//查找元素
	//count/find时间复杂度为O(1)
	size_t cnt = points.count(Point(-1, 2));
	if(cnt) {
		cout << "查找成功!" << endl;
	} else 
		cout << "查找失败!" << endl;
}

int main(void)
{
	//test0();
	test1();
	return 0;
}
