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

	double getReal() const {	return _dreal;	}
	double getImage() const{	return _dimag;	}

private:
	double _dreal; // i^2 = -1  欧拉公式
	double _dimag;
};

#if 0
int operator+(int x, int y)
{
	return x - y;
}
#endif

//运算符重载之普通函数
Complex operator+(const Complex & lhs, const Complex & rhs)
{
	return Complex(lhs.getReal() + rhs.getReal(),
				   lhs.getImage() + rhs.getImage());
}
 
int main(void)
{
	int a = 3, b = 4;
	int c = a + b;

	Complex c1(1, 2);
	cout << "c1 = ";
	c1.print();
	Complex c2(1, 3);
	cout << "c2 = ";
	c2.print();
	Complex c3 = c1 + c2;
	cout << "c3 = ";
	c3.print();
 
	return 0;
}
