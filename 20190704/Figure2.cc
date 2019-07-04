 ///
 /// @file    Figure.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-28 14:31:43
 ///
 
#include <math.h>
#include <iostream>
#include <functional>
using std::cout;
using std::endl;
using std::function;

//解耦
//
//基于对象的编程范式
//
//需求更直接，类的编写更灵活
//
class Figure
{
public:
	using DisplayCallback = function<void()>;
	using AreaCallback = function<double()>;

	void setDisplayCallback(DisplayCallback cb)
	{	_cb1 = cb;	}

	void setAreaCallback(AreaCallback cb)
	{	_cb2 = cb;	}

	void handleDisplayCallback()
	{
		if(_cb1)
			_cb1();
	}

	double handleAreaCallback()
	{
		if(_cb2)
			return _cb2();
		else
			return 0;
	}

private:
	function<void()> _cb1;
	function<double()> _cb2;
};

class Circle
{
public:
	Circle(double radius)
	: _radius(radius)
	{}

	void display() const
	{	cout << "circle";	}

	double area()
	{
		return 3.14159 * _radius * _radius;
	}

private:
	double _radius;
};

class Rectangle
{
public:
	Rectangle(double length, double width)
	: _length(length)
	, _width(width)
	{}

	void print() const
	{	cout << "rectangle";	}

	double calcArea()
	{	return _length * _width;	}

private:
	double _length;
	double _width;
};

class Triangle
{
public:
	Triangle(double a, double b, double c)
	: _a(a)
	, _b(b)
	, _c(c)
	{}

	void show() const
	{	cout << "triangle";}

	double getArea()
	{
		double p = (_a + _b + _c) / 2;
		return sqrt(p * (p - _a) * (p - _b) * (p - _c));
	}

private:
	double _a;
	double _b;
	double _c;
};

class Cube
: public Figure
{
public:
	Cube(double a)
	: _a(a)
	{}

	void display() const
	{	cout << "cube";	}

	double area()
	{
		return 6 * _a * _a;
	}

private:
	double _a;
};

void display(Figure & fig)
{
	//执行回调函数
	fig.handleDisplayCallback();
	cout << "的面积是:" << fig.handleAreaCallback() << endl;
}
 
int main(void)
{
	Figure fig;
	Circle circle(10);
	Rectangle rectangle(20, 30);
	Triangle triangle(3, 4, 5);
	Cube cube(10);

	//注册回调函数
	fig.setDisplayCallback(std::bind(&Circle::display, &circle));
	fig.setAreaCallback(std::bind(&Circle::area, &circle));
	display(fig);

	fig.setDisplayCallback(std::bind(&Rectangle::print, &rectangle));
	fig.setAreaCallback(std::bind(&Rectangle::calcArea, &rectangle));
	display(fig);

	fig.setDisplayCallback(std::bind(&Triangle::show, &triangle));
	fig.setAreaCallback(std::bind(&Triangle::getArea, &triangle));
	display(fig);

	fig.setDisplayCallback(std::bind(&Cube::display, &cube));
	fig.setAreaCallback(std::bind(&Cube::area, &cube));
	display(fig);


	return 0;
}
