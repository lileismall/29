 ///
 /// @file    Student.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-20 10:17:20
 ///
 

#include <string.h>
#include <stdlib.h>

#include <iostream>
using std::cout;
using std::endl;

class Student
{
public:
	Student(int id, const char * name)
	: _id(id)
	, _name(new char[strlen(name) + 1]())
	{
		strcpy(_name, name);
		cout << "Student(int, const char *)" << endl;
	}

	void print() const
	{
		cout << "(" << _id << ", " << _name << ")" << endl;
	}

	//提供一个接口,可以自定义开辟空间的方式
	//放在类内部，只针对于Student类型起作用
	//放在类之外，对所有的类型都会起作用
	static void * operator new(size_t sz)
	{
		cout << "void * operator new(size_t) " << endl;
		return malloc(sz);
	}

	static void operator delete(void * pointer)
	{
		cout << "void operator delete(void*)" << endl;
		free(pointer);
	}

	~Student()
	{
		delete [] _name;
		cout  << "~Student()" << endl;
	}

private:
	int _id;
	char * _name;
};
 
int main(void)
{
	Student * pstu = new Student(100, "Jackie");
	pstu->print();
 
	delete pstu;
	return 0;
}
