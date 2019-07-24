 ///
 /// @file    abuse.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-08 17:08:22
 ///
 
#include <iostream>
#include <memory>

using namespace std;

class Point
: public enable_shared_from_this<Point>   //辅助类
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

	//Point * addPoint(Point * pt)
	shared_ptr<Point> addPoint(Point * pt)
	{	//在成员函数内部希望通过this指针获取本对象的shared_ptr
		_ix += pt->_ix;
		_iy += pt->_iy;
		return shared_from_this();
		//return shared_ptr<Point>(this);//this就是原生裸指针
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
	//将一个原生裸指针交给了两个不同的智能指针托管
	Point * pt = new Point(1, 2);
	unique_ptr<Point> up1(pt);
	unique_ptr<Point> up2(pt);
	cout << "*up1 = " << *up1 << endl
		 << "*up2 = " << *up2 << endl;

}
 
void test1()
{
	//错误的原因: 将一个原生裸指针交给了两个不同的智能指针托管
	Point * pt = new Point(1, 2);
	shared_ptr<Point> up1(pt);
	shared_ptr<Point> up2(pt);
	cout << "*up1 = " << *up1 << endl
		 << "*up2 = " << *up2 << endl;
}

void test2()
{
	shared_ptr<Point> sp1(new Point(1, 2));	
	shared_ptr<Point> sp2(new Point(11, 12));	

	sp2.reset(sp1.get());//error
}

void test3()
{
	shared_ptr<Point> sp1(new Point(1, 2));	
	shared_ptr<Point> sp2(new Point(11, 12));	
	
	shared_ptr<Point> sp3(sp1->addPoint(sp2.get()));
	cout << "sp3's use_count = " << sp3.use_count() << endl;
}

int main(void)
{
	//test0();
	//test1();
	//test2();
	test3();
	return 0;
}
