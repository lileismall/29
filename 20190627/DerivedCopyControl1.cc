 ///
 /// @file    DerivedCopyControl1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-27 15:09:09
 ///
 
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

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
	Derived(const char * data)
	: Base(data)
	{	cout << "Derived()" << endl;	}


	~Derived()
	{	cout << "~Derived()" << endl;	}	
};
 
std::ostream & operator<<(std::ostream & os, const Derived & rhs)
{
	os << rhs.data();
	return os;
}

int main(void)
{
	Derived d1("hello");
	cout << "d1 = " << d1 << endl;

	Derived d2 = d1;
	cout << "d2 = " << d2 << endl;

	Derived d3("world");
	cout << "d3 = " << d3 << endl;

	d3 = d1;
	cout << "d3 = " << d3 << endl;

	return 0;
}
