 ///
 /// @file    RAII.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-08 14:40:32
 ///
 
#include <iostream>
using std::cout;
using std::endl;

template <class Type>
class RAII
{
public:
	explicit
	RAII(Type * pointer)
	: _pointer(pointer)
	{}

	Type * operator->()
	{	return _pointer;	}

	Type & operator*()
	{	return *_pointer;	}

	Type * get() {	return _pointer;	}

	void reset(Type * pointer)
	{
		if(_pointer)
			delete _pointer;
		_pointer = pointer;
	}

	~RAII()
	{
		if(_pointer)
			delete _pointer;
	}

private:
	Type * _pointer;
};


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
	//智能指针的雏形
	RAII<Point> pointer(new Point(1, 2));
	pointer->print();
	(*pointer).print();

	cout << "*pointer= " << *pointer<< endl;

	return 0;
}
