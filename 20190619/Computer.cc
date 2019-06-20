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

	Computer(const Computer & rhs)
	: _brand(new char[strlen(rhs._brand) + 1]())
	, _price(rhs._price)
	{
		strcpy(_brand, rhs._brand);
		cout << "Computer(const Computer&)" << endl;
	}

	Computer & operator=(const Computer & rhs)
	{	//三部曲
		cout << "Computer & operator=(const Computer &)" << endl;
		if(this != &rhs) {// 自复制
			delete [] _brand;//回收左操作数开辟的空间
			_brand = new char[strlen(rhs._brand) + 1]();//深拷贝
			strcpy(_brand, rhs._brand);
			
			this->_price = rhs._price;
		}
		return *this;
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
	Computer pc1("MateBook.....", 6666);
	cout << ">> pc1: " << endl;
	pc1.print();

	//用一个已经存在的对象初始化另一个新对象
	Computer pc2 = pc1;
	cout << ">> pc2: " << endl;
	pc2.print();

	Computer pc3("Thinkpad", 8888);
	cout << ">> pc3: " << endl;
	pc3.print();

	pc3 = pc1;
	//pc3.operator=(pc1);
	cout << ">> pc3: " << endl;
	pc3.print();


	pc2 = pc2;
}

int main(void)
{
	test0();
	return 0;
}
