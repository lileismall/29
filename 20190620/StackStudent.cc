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

//只能生成栈对象, 不能生成堆对象
//
//解决方案: 将operator new放入private区域
//
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

	~Student()
	{
		delete [] _name;
		cout  << "~Student()" << endl;
	}

private:
	static void * operator new(size_t sz);
	static void operator delete(void * pointer);

private:
	int _id;
	char * _name;
};
 
int main(void)
{
	Student s1(101, "John");
	s1.print();

	//Student * pstu = new Student(100, "Jackie");//error
	//pstu->print();
 
	//delete pstu;
	return 0;
}
