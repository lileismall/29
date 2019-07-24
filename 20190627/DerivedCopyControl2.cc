 ///
 /// @file    DerivedCopyControl1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-27 15:09:09
 ///
 
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

//对于基类的复制构造函数和赋值运算符函数，派生类
//没有继承

//当派生类与派生类对象进行复制控制操作时,
//1. 如果派生类没有显式定义复制控制函数,
//  则会自动调用基类的相应复制控制函数
//2. 如果是派生类有显式定义复制控制函数，基类也有显式
//定义复制控制函数，则基类部分不必再自动调用相应的
//复制控制函数，需要手动调用

class Base
{
public:
	Base(const char * data)
	: _data(new char[strlen(data) + 1]())
	{	
		cout << "Base(const char * data)" << endl;	
		strcpy(_data, data);
	}

	Base(const Base & rhs)
	: _data(new char[strlen(rhs._data) + 1]())
	{
		strcpy(_data, rhs._data);
		cout << "Base(const Base & )" << endl;
	}

	Base & operator=(const Base & rhs)
	{
		cout << "Base & operator=(const Base &)" << endl;
		if(this != &rhs) {
			delete [] _data;

			_data = new char[strlen(rhs._data) + 1]();
			strcpy(_data, rhs._data);
		}
		return *this;
	}

	~Base()
	{
		cout << "~Base()" << endl;
		delete [] _data;
	}

	const char * data() const
	{	return _data;	}



private:
	char * _data;
};

class Derived
: public Base
{
public:
	Derived(const char * data, const char * data2)
	: Base(data)
	, _data2(new char[strlen(data2) + 1]())
	{	
		cout << "Derived(const char *, const char *)" << endl;	
		strcpy(_data2, data2);
	}

	Derived(const Derived & rhs)
	: Base(rhs)
	, _data2(new char[strlen(rhs._data2) + 1]())
	{
		cout << "Derived(const Derived &)" << endl;
		strcpy(_data2, rhs._data2);
	}

	Derived & operator=(const Derived & rhs)
	{
		cout << "Derived & operator=(const Derived&)" << endl;
		if(this != & rhs) {
			Base::operator=(rhs);//显式调用赋值运算符函数
			delete [] _data2;
		
			_data2 = new char[strlen(rhs._data2) + 1]();
			strcpy(_data2, rhs._data2);
		}
		return *this;
	}


	~Derived()
	{	cout << "~Derived()" << endl;	}	

	friend std::ostream & operator<<(std::ostream & os, const Derived & rhs);
private:
	char * _data2;
};
 
std::ostream & operator<<(std::ostream & os, const Derived & rhs)
{
	os << rhs.data() << "," << rhs._data2;
	return os;
}

int main(void)
{
	Derived d1("hello", "world");
	cout << "d1 = " << d1 << endl;

	Derived d2 = d1;
	cout << "d2 = " << d2 << endl;

	Derived d3("guangdong", "shenzhen");
	cout << "d3 = " << d3 << endl;

	d3 = d1;
	cout << "d3 = " << d3 << endl;

	return 0;
}
