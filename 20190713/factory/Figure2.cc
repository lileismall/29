 ///
 /// @file    Figure.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-28 14:31:43
 ///
 
#include <math.h>
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;

class Figure
{
public:
	virtual ~Figure() {	cout << "~Figure()" << endl;	}

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

	~Circle() {	cout << "~Circle()" << endl;	}

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

	~Rectangle() {	cout << "~Rectangle()" << endl;	}

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

	~Triangle() {	cout << "~Triangle()" << endl;	}

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


//工厂模式

class Factory
{
public:
	virtual Figure * create()=0;

	virtual ~Factory() {	cout << "~Factory()" << endl;	}
};

class CircleFactory
: public Factory
{
public:
	Figure * create() override
	{
		//load xml
		//....
		return new Circle(10);
	}

	~CircleFactory() {	cout << "~CircleFactory()" << endl;	}
};


class RectangleFactory
: public Factory
{
	Figure * create() override
	{
		//load xml
		//...
		return 	new Rectangle(20, 30);
	}
	~RectangleFactory() {	cout << "~RectangleFactory()" << endl;	}
};


class TriangleFactory
: public Factory
{
	Figure * create() override
	{
		//load xml
		//....
		return new Triangle(3, 4, 5);
	}
	~TriangleFactory() {	cout << "~TriangleFactory()" << endl;	}
};


//工厂模式应用场景:
//1. 针对于复杂对象(如果是简单对象，没有必要使用工厂模式)
//2. 批量创建对象
 
int main(void)
{
	unique_ptr<Factory> circleFactory(new CircleFactory());
	unique_ptr<Figure> circle(circleFactory->create());

	unique_ptr<Factory> rectangleFactory(new RectangleFactory());
	unique_ptr<Figure> rectangle(rectangleFactory->create());

	unique_ptr<Factory> triangleFactory(new TriangleFactory());
	unique_ptr<Figure> triangle(triangleFactory->create());

	display(circle.get());
	display(rectangle.get());
	display(triangle.get());

	//Cube cube(10);
	//display(&cube);

	return 0;
}
