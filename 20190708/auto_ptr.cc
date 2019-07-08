 ///
 /// @file    auto_ptr.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-08 14:50:13
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::auto_ptr;
 
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
 
int main(void)
{
	Point * pt = new Point(1, 2);
	auto_ptr<Point> ap(pt);
	cout << "*ap = " << *ap << endl;
	cout << "ap.get() = " << ap.get() << endl;
	cout << "pt = " << pt << endl;

	auto_ptr<Point> ap2(ap);//在语法形式上是复制，
					        //但底层已经发生了所有权的转移
							//
							//语法形式与表达的语义是矛盾的，
							//存在缺陷, C++11之后被弃用
	cout << "*ap2 = " << *ap2 << endl;
	cout << "ap2.get() = " << ap2.get() << endl;
	//cout << "*ap = " << *ap << endl;
	//cout << "ap.get() = " << ap.get() << endl;

	auto_ptr<Point> ap3(new Point(3, 4));
	ap3 = ap2;//发生所有权的转移
	cout << "*ap3 = " << *ap3 << endl;
	cout << "ap3.get() = " << ap3.get() << endl;
	cout << "*ap2 = " << *ap2 << endl;
	cout << "ap2.get() = " << ap2.get() << endl;

	return 0;
}
