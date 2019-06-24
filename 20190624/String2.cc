 ///
 /// @file    String.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-24 09:40:00
 ///
 

#include <string.h>
#include <iostream>
using std::cout;
using std::endl;


class String
{
public:
	String()
	: _pstr(new char[1]())
	{
		cout << "String()" << endl;
	}

	String(const char * pstr)
	: _pstr(new char[strlen(pstr) + 1]())
	{
		strcpy(_pstr, pstr);
		cout << "String(const char * pstr)" << endl;
	}

	String(const String & rhs)
	: _pstr(new char[strlen(rhs._pstr) + 1]())
	{
		cout << "String(constb String &)" << endl;
		strcpy(_pstr, rhs._pstr);
	}

	String & operator=(const String & rhs)
	{
		cout << "String & operator=(const String&)" << endl;
		if(this != & rhs) {
			delete [] _pstr;

			_pstr = new char[strlen(rhs._pstr) + 1]();
			strcpy(_pstr, rhs._pstr);
		}
		return *this;
	}

	void print() const
	{
		cout << _pstr << endl;
	}

	~String()
	{
		delete [] _pstr;
		cout << "~String()" << endl;
	}

private:
	char * _pstr;
};
 
int main(void)
{
	String s1;
	s1.print();

	String s2 = "hello";
	cout << "s2 = ";
	s2.print();

	String s3 = s2;
	cout << "s3 = ";
	s3.print();

	String s4 = "world";
	s4 = s2;
	cout << "s4 = ";
	s4.print();

#if 0
	cout << "1111" << endl;
	int * p = nullptr;

	cout << "p = " << p << endl;
	cout << "222" << endl;
#endif

	return 0;
}
