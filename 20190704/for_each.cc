 ///
 /// @file    for_each.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-04 10:12:44
 ///
 
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

#if 0
void display(int & number)
{
	//++number;
	cout << number << " ";
}
#endif

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{}

	double getDistance() const
	{
		return sqrt(_ix * _ix + _iy * _iy);
	}

	friend std::ostream & operator<<(std::ostream & os, const Point & rhs);
	friend bool operator==(const Point & lhs, const Point & rhs);
private:
	int _ix;
	int _iy;
};

#if 0
void display(Point & number)
{
	cout << number << " ";
}
#endif

std::ostream & operator<<(std::ostream & os, const Point & rhs)
{
	os << "(" << rhs._ix
	   << "," << rhs._iy
	   << ")";
	return os;
}

bool operator==(const Point& lhs, const Point & rhs)
{
	return (lhs._ix == rhs._ix) && (lhs._iy == rhs._iy);
}


struct PointComparator
{
	bool operator()(const Point & lhs,  const Point &rhs) const
	{
		return lhs.getDistance() < rhs.getDistance();
	}
};


int test1(void)
{
	vector<Point> numbers{
		Point(1, 2),
		Point(7, 8),
		Point(5, 6),
		Point(15, 6),
		Point(1, 12)
	};

	//lambda表达式  ==》 匿名函数
	for_each(numbers.begin(), numbers.end(), [](const Point & point ){
		cout << point << " ";		
	});
	cout << endl;

	//std::find 时间复杂度为O(N)
	auto it = std::find(numbers.begin(), numbers.end(), Point(7, 8));
	if(it != numbers.end())
		cout << "*it = " << *it << endl;
	else 
		cout << "元素没有找到!" << endl;

	//排序
	//std::sort(numbers.begin(), numbers.end(), PointComparator());
	std::sort(numbers.begin(), numbers.end(), 
		[](const Point & lhs, const Point & rhs){
			return lhs.getDistance() < rhs.getDistance();	
	});
	for_each(numbers.begin(), numbers.end(), [](const Point & point){
		cout << point <<  " ";
	});
	cout << endl;
	
	//二分查找 O(logN)
	auto it2 = std::lower_bound(numbers.begin(), numbers.end(),	Point(7, 8), PointComparator());
	cout << "*it2 = " << *it2 << endl; 
	//bool isexit = std::binary_search(numbers.begin(), numbers.end(), 10);
	//cout << "isexit = " << isexit << endl;

	return 0;
}

int main(void)
{
	test1();
	return 0;
}
 
#if 1
int test0(void)
{
	vector<int> numbers{1, 8, 10, 9, 2, 4, 3, 5};

	//for_each(numbers.begin(), numbers.end(), display);
	for_each(numbers.begin(), numbers.end(), [](int number){
		cout << number << " ";
	});
	cout << endl;

	//std::find 时间复杂度为O(N)
	auto it = std::find(numbers.begin(), numbers.end(), 10);
	if(it != numbers.end())
		cout << "*it = " << *it << endl;
	else 
		cout << "元素没有找到!" << endl;

	//排序
	std::sort(numbers.begin(), numbers.end());
	
	//二分查找 O(logN)
	auto it2 = std::lower_bound(numbers.begin(), numbers.end(),	10);
	cout << "*it2 = " << *it2 << endl;

	bool isexit = std::binary_search(numbers.begin(), numbers.end(), 10);
	cout << "isexit = " << isexit << endl;

	return 0;
}
#endif
