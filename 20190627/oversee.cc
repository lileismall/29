 ///
 /// @file    oversee.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-27 14:32:49
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
	Base(int x)
	: _x(x) 
	{	cout << "Base(int)" << endl;	}

	void display(int) const
	{	
		cout << "Base::_x = " << _x << endl;
	}

protected:
	int _x;
};

class Derived
: public Base
{
public:
	Derived(int x1, int x2)
	: Base(x1)
	, _x(x2)
	{
		cout << "Derived(int,int)" << endl;
	}

	void display() const
	{
		cout << "this->_x = " << this->_x << endl;
		cout << ">> Base::_x = " << Base::_x << endl;
		cout << "_x = " << _x << endl;//基类的同名_x被隐藏了
	}

	//void display(double); //overload

private:
	int _x;
};
 
int main(void)
{
	Derived d1(10, 20);
	d1.display();//基类的display方法也被隐藏了
	//d1.Base::display();
	//d1.display(11);//error 只要派生类中定义的成员函数名与基类相同，
				     //基类的同名成员函数被隐藏

	return 0;
}

