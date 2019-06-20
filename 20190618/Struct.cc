 ///
 /// @file    Struct.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-18 15:18:09
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//后面要讲解的函数对象中会用到的
struct Example
{
//struct的默认访问权限是Public
	Example(int x)
	: _ix(_iy)
	, _iy(x)
	{
	}
	void setX(int ix)
	{	_ix = ix;	}

	void setY(int iy)
	{	_iy = iy;	}

	void print()
	{
		cout << "(" << _ix  << "," << _iy << ")" << endl;
	}
	
private:
	int _ix;
	int _iy;
};
 
int main(void)
{
	Example e1(1);
	//e1._ix = 100;
	//e1._iy = 101;

	e1.print();

	return 0;
}
