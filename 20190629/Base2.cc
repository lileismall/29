 ///
 /// @file    Base.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-29 10:16:13
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//一个类不能被继承, 在定义类的时候，在类名加上final关键字
class Base final
{
public:
	Base() {};

private:
	int _base;
};

class Derived
: public Base
{
public:
	Derived()
	: Base()
	{}
};
 
int main(void)
{
	Derived derived;
}
