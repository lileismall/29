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

//要求: 只能生成堆对象，不能生成栈对象
//解决方案:
//	  将析构函数放入private区域, 同时
//还需要定义一个destroy方法, 在destroy方法
//中去执行delete表达式

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


	void destroy()
	{
		//this->~Student();
		delete this;
	}


private:
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
	Student * pstu = new Student(100, "Jackie");//ok
	pstu->print();
	//delete pstu;//error
	pstu->destroy();

//	Student stu(101, "John");//error
//	stu.print();

	return 0;
}
