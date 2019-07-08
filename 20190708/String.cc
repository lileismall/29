 ///
 /// @file    String.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-08 10:55:41
 ///
 
#include <string.h>

#include <iostream>
#include <vector>
using namespace std;
 
class String
{
public:
	String()
	: _pstr(nullptr)
	{
		cout << "String()" << endl;
	}

	String(const char * pstr)
	: _pstr(new char[strlen(pstr) + 1]())
	{
		strcpy(_pstr, pstr);
		cout << "String(const char * pstr)" << endl;
	}

	//具有移动语义的函数要优先于具有复制控制语义函数的执行

	//复制构造函数
	String(const String & rhs)
	: _pstr(new char[strlen(rhs._pstr) + 1]())
	{
		cout << "String(const String &)" << endl;
		strcpy(_pstr, rhs._pstr);
	}

	//赋值函数
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

#if 1
	//移动构造函数
	String(String && rhs)
	: _pstr(rhs._pstr)
	{
		rhs._pstr = nullptr;
		cout << "String(String && )" << endl;
	}
#endif

	//移动赋值函数
	String & operator=(String && rhs)
	{
		cout << "String & operator=(String&&)" << endl;
		if(this != &rhs) {
			delete [] _pstr;

			_pstr = rhs._pstr;
			rhs._pstr = nullptr;
		}
		return *this;
	}

	char & operator[](int idx)
	{
		if(idx >= 0 || idx < strlen(_pstr)) {
			return _pstr[idx];
		} else {
			cout << " idx 越界!" << endl;
			static char nullchar = '\0';
			return nullchar;
		}
	}

	void print() const
	{
		if(_pstr)
			cout << _pstr << endl;
	}

	~String()
	{
		if(_pstr)
			delete [] _pstr;
		cout << "~String()" << endl;
	}

	int	size()const 
	{	return strlen(_pstr);}

	friend std::ostream & operator<<(std::ostream & os, const String & rhs);
private:
	char * _pstr;
};

std::ostream & operator<<(std::ostream & os, const String & rhs)
{
	os << rhs._pstr;
	return os;
}
int test0(void)
{
	vector<String> vec;
	vec.push_back("hello,world");//临时对象 右值

	vec[0].print();

//	String s("wangdao");// 左值
//	vec.push_back(s);

	return 0;
}

void test1()
{
	String s1 = "hello";//左值
	cout << "s1 = " << s1 << endl;

	String s2("world");
	//s2 = String("wangdao");
	s2 = std::move(s1);//将一个左值显式的转换为右值
	//...
	cout << "s2 = " << s2 << endl;
	//cout << "s1 = " << s1 << endl;//s1 本身的内容已经被转移走了
	
	cout << "...." << endl;

	//s1 = std::move(s1);

	vector<String> vec;
	vec.push_back(std::move(s2));
}

int main(void)
{
	test1();
	return 0;
}
