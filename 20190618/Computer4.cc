 ///
 /// @file    Computer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-18 14:46:25
 ///
 
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;


class Computer
{
public:
	Computer(const char * brand, double price)
	: _brand(new char[strlen(brand) + 1]())  
	, _price(price)
	{
		strcpy(_brand, brand);
		cout << "Computer(const char *, double)" << endl;
	}

	//系统提供的 已经不能满足需求
#if 0
	Computer(const Computer & rhs)
	: _brand(rhs._brand)//浅拷贝, 只传地址
	, _price(rhs._price)
	{
		cout << "Computer(const Computer&)" << endl;
	}
#endif
	Computer(const Computer & rhs)
	: _brand(new char[strlen(rhs._brand) + 1]())
	, _price(rhs._price)
	{
		strcpy(_brand, rhs._brand);
		cout << "Computer(const Computer&)" << endl;
	}

	void print()
	{
		printf("   brand = %p\n", _brand);
		cout << "   brand:" << _brand << endl
			 << "   price:" << _price << endl;
	}
	

	~Computer()
	{	
		delete [] _brand;
		cout << "~Computer()" << endl;
	}

private:
	char * _brand;
	double _price;
};

void test0()
{
	Computer pc1("MateBook", 6666);
	cout << ">> pc1: " << endl;
	pc1.print();

	//用一个已经存在的对象初始化另一个新对象
	Computer pc2 = pc1;
	cout << ">> pc2: " << endl;
	pc2.print();
}

int main(void)
{
	test0();
	return 0;
}
