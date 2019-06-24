 ///
 /// @file    Complex.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-24 16:10:26
 ///
 
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

	friend Complex operator+(const Complex & lhs, const Complex & rhs);

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
 
int main(void)
{
	int a = 3, b = 4;
	int c = a + b;

	a += b;// a = a + b

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
 
	return 0;
}
