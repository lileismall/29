 ///
 /// @file    Figure.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-28 14:31:43
 ///
 
#include <math.h>
#include <iostream>
using std::cout;
using std::endl;

class Figure
{
public:
	virtual void display() const =0;
	virtual double area()=0;
};

class Circle
: public Figure
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
: public Figure
{
public:
	Rectangle(double length, double width)
	: _length(length)
	, _width(width)
	{}

	void display() const
	{	cout << "rectangle";	}

	double area()
	{	return _length * _width;	}

private:
	double _length;
	double _width;
};

class Triangle
: public Figure
{
public:
	Triangle(double a, double b, double c)
	: _a(a)
	, _b(b)
	, _c(c)
	{}

	void display() const
	{	cout << "triangle";}

	double area()
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

void display(Figure * fig)
{
	fig->display();
	cout << "的面积是:" << fig->area() << endl;
}


//静态工厂方法
//
//缺点: 1. 不满足开闭原则
//		2. 不满足单一职责原则

class Factory
{
public:
	static Circle createCircle()
	{
		//load xml
		//....
		Circle circle(10);
		return circle;
	}

	static Rectangle createRectangle()
	{
		//load xml
		//...
		Rectangle rectangle(20, 30);

		return rectangle;
	}

	static Triangle createTriangle()
	{
		//load xml
		//....
		Triangle triangle(3, 4, 5);

		return triangle;
	}


	static Cube createCub()
	{
	
	}
};

 
int main(void)
{
	Circle circle = Factory::createCircle();
	Rectangle rectangle = Factory::createRectangle();
	Triangle triangle = Factory::createTriangle();

	display(&circle);
	display(&rectangle);
	display(&triangle);

	Cube cube(10);
	display(&cube);

	return 0;
}
