 ///
 /// @file    template2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-01 11:54:19
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//非模板的类
class Example
{
public:
	Example(double data)
	: _data(data)
	{}

	//函数模板还可以是一个成员函数形式
	template <class T>
	T  typecast() 
	{
		return T(_data);
	}

private: 
	double _data;
};
 
int main(void)
{
	Example e(11.11);
	cout << e.typecast<int>() << endl;

	return 0;
}
