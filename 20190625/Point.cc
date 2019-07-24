 ///
 /// @file    Point.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-24 15:24:01
 ///
 
#include <math.h>
#include <iostream>
using std::cout;
using std::endl;

class Complex
{
public:
	Complex(double dreal, double dimag)
	: _dreal(dreal)
	, _dimag(dimag)
	{}

	void print() const
	{
		cout << _dreal << " + " << _dimag << " i" << endl;
	}

	//对象本身发生变化的，就用成员函数形式重载
	//复合赋值运算符 -= /= *= %=
	Complex & operator+=(const Complex & rhs)
	{
		cout << "Complex & operator+=(const Complex & rhs)" << endl;
		_dreal += rhs._dreal;
		_dimag += rhs._dimag;
		return *this;
	}

	//前置++ 的效率高于后置++的
	//前置返回的是引用
	Complex & operator++()
	{
		++_dreal;
		++_dimag;
		return *this;
	}

	//后置++
	//后置返回的是对象
	Complex operator++(int)// int 只是作为一个标识位存在，不需要传递参数
	{
		Complex tmp(*this);
		++_dreal;
		++_dimag;
		return tmp;
	}

	friend std::ostream & operator<<(std::ostream & os, const Complex & rhs);

private:
	double _dreal; // i^2 = -1  欧拉公式
	double _dimag;
};

 
std::ostream & operator<<(std::ostream & os, const Complex & rhs)
{
	os << rhs._dreal << " + " << rhs._dimag << "i";
	return os;
}

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int,int)" << endl;
	}

	void print() const
	{
		cout << "(" << _ix
		     << "," << _iy
			 << ")" ;
	}

	//类型转换函数的特点:
	//1. 成员函数
	//2. 没有返回值类型
	//3. 没有形参
	//4. 在函数体内必须以return语句返回一个目标类型的变量
	//
	//尽量不要使用
	operator int()
	{
		cout << "operator int()" << endl;
		return _ix;
	}

	operator double()
	{
		cout << "operator double()" << endl;
		return _ix * _iy;
	}

	operator Complex()
	{
		return Complex(_ix, _iy);
	}
	
	friend std::ostream & operator<<(std::ostream &os, const Point & rhs);

private:
	int _ix;
	int _iy;
};

std::ostream & operator<<(std::ostream &os, const Point & rhs)
{
	os << "(" << rhs._ix
	   << "," << rhs._iy
	   << ")";
	return os;
}
 
int main(void)
{
	Point pt1(1, 2);
	cout << "pt1 = " << pt1 << endl;

	pt1 = 10;//隐式转换, 调用构造函数
	cout << "pt1 = " << pt1 << endl;

	int x = pt1;//要调用类型转换函数
	cout << "x = " << x << endl;

	double y = pt1;
	cout << "y = " << y << endl;

	Complex c = pt1;//违反常规思维, 一般情况下不建议使用
	cout << "c = " << c << endl;
	return 0;
}
