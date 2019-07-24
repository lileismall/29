 ///
 /// @file    shared_ptr.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-08 16:04:27
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;

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

void test0()
{
	Point * pt = new Point(1, 2);
	shared_ptr<Point> sp(pt);
	shared_ptr<Point> sp2(sp);//执行复制构造或者赋值操作时
							 //引用计数会加1
							 //
							 //当shared_ptr被销毁时，引用计数会减1
							 //
							 //只有当引用计数减为0时，才会真正
							 //销毁被托管的对象
							 //
	
	cout << "*sp = " << *sp << endl;
	cout << "*sp2 = " << *sp2 << endl;
	cout << "sp's use_count = " << sp.use_count() << endl;
	cout << "sp2's use_count = " << sp2.use_count() << endl;

	{
	shared_ptr<Point> sp3(new Point(11, 12));
	cout << "*sp3 = " << *sp3 << endl;
	sp3 = sp2;// 
	cout << "执行赋值操作之后:" << endl;
	cout << "*sp3 = " << *sp3 << endl;
	cout << "sp's use_count = " << sp.use_count() << endl;
	cout << "sp2's use_count = " << sp2.use_count() << endl;
	cout << "sp3's use_count = " << sp3.use_count() << endl;
	}
	cout << "sp's use_count = " << sp.use_count() << endl;
	cout << "sp2's use_count = " << sp2.use_count() << endl;
}
 
int main(void)
{
	test0();
	return 0;
}
