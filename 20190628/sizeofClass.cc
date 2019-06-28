 ///
 /// @file    sizeofClass.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-28 15:17:56
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//预处理指令   指定内存对齐字节数  4  2

#pragma  pack(push)
#pragma  pack(4)

class Base
{
public:
	Base(int & ref)
	: _ref(ref)
	{}

	virtual void display() const
	{	cout << "display()" << endl;	}
private:
	int _a;			 //  4
	double _b;		 //  8
	short _c[5];	 //  10
	char _d;		 //  1
	static int _e;	 //  4
	int & _ref;		 //  8
};
 
#pragma  pack(pop)

class Base2
{
public:
	Base2(int & ref)
	: _ref(ref)
	{}

	virtual void display() const
	{	cout << "display()" << endl;	}
private:
	int _a;			 //  4
	double _b;		 //  8
	short _c[5];	 //  10
	char _d;		 //  1
	static int _e;	 //  4
	int & _ref;		 //  8
};

int main(void)
{
	//系统是32位的还是64位
	cout << "sizeof(Base) = " << sizeof(Base) << endl;
	cout << "sizeof(Base2) = " << sizeof(Base2) << endl;

	return 0;
}
