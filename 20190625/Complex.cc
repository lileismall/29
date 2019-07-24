 ///
 /// @file    Complex.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-24 16:10:26
 ///
 
#include <iostream>
#include <limits>
using std::cout;
using std::endl;

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
	
	friend class Complex;
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

class Complex
{
public:
	Complex(double dreal, double dimag)
	: _dreal(dreal)
	, _dimag(dimag)
	{}

	//explicit
	Complex(const Point & rhs)
	: _dreal(rhs._ix)
	, _dimag(rhs._iy)
	{
		cout << "Complex(const Point & )" << endl;
	}

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

	//输入输出流运算符都不能以成员函数形式重载
	//要求是流对象必须是左操作数;
	//如果以成员函数形式进行重载，则左操作数是
	//对象本身
	//std::ostream & operator<<(std::ostream & os)
	//{}


	friend Complex operator+(const Complex & lhs, const Complex & rhs);
	friend bool operator<(const Complex & lhs, const Complex & rhs);
	friend std::ostream & operator<<(std::ostream & os, const Complex & rhs);
	friend std::istream & operator>>(std::istream & is, Complex & rhs);

private:
	double _dreal; // i^2 = -1  欧拉公式
	double _dimag;
};


//运算符重载之友元函数
Complex operator+(const Complex & lhs, const Complex & rhs)
{
	return Complex(lhs._dreal + rhs._dreal,
				   lhs._dimag + rhs._dimag);
}

bool operator<(const Complex & lhs, const Complex & rhs)
{
	return lhs._dreal < rhs._dreal;
}
 
std::ostream & operator<<(std::ostream & os, const Complex & rhs)
{
	os << rhs._dreal << " + " << rhs._dimag << "i";
	return os;
}

void readDoubleValue(std::istream & is, double & value)
{
	cout << "pls input a valid double:" << endl;
	while(is >> value, !is.eof()) {
		if(is.bad()) {
			cout << "istream is corrupted!" << endl;
			return;
		} else if(is.fail()) {
			is.clear();
			is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "pls input a valid double:" << endl;
			continue;
		}
		break;
	}
}

std::istream & operator>>(std::istream & is, Complex & rhs)
{	//输入流容易被考到的点:  把一个字符串转换成数字
	//思维的完备性
	readDoubleValue(is, rhs._dreal);
	readDoubleValue(is, rhs._dimag);
	return is;
}


int test0(void)
{
	int a = 3, b = 4;
	int c = a + b;

	//a += b;// a = a + b

	&(++a); //4   4

	(a++);  //4   5

	Complex c1(1, 2);
	cout << "c1 = ";
	c1.print();
	Complex c2(1, 3);
	cout << "c2 = ";
	c2.print();
	Complex c3 = c1 + c2;
	cout << "c3 = ";
	c3.print();

	c1 += c2;// 推荐以成员函数形式重载
	cout << "c1 = ";
	c1.print();

	cout << endl << "C1执行自增运算符：" << endl;
	(++c1).print();
	c1.print();

	(c1++).print();
	c1.print();
 
	return 0;
}

int test1()
{
	int a = 3;
	cout << "a = " << a << endl;

	Complex c1(1, 2);
	cout << "c1 = " << c1 << endl;

	//c1.operator<<(cout);
	//c1 << cout;
	
	cout << "pls input a comlex value:" << endl;
	std::cin >> c1;
	cout << "c1 = " << c1 << endl;

	return 0;
}

int test2()
{
	Point pt(11, 12);
	cout << "pt = " << pt << endl;
	Complex c1 = pt;//通过构造函数进行  隐式转换
	cout << "c1 = " << c1 << endl;
	return 0;
}

int main(void)
{
	//test1();
	test2();
	return 0;
}
