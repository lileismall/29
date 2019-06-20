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
		_totalPrice += _price;
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
		cout << "   brand:" << this->_brand << endl
			 << "   price:" << this->_price << endl;
	}

	//静态成员函数没有隐含的this指针
	static void printTotalprice()
	{//静态成员函数内部不能非静态的成员
		//cout << "   brand:" << this->_brand << endl
		cout << "   total price: " << _totalPrice << endl;
	}
	

	~Computer()
	{	
		delete [] _brand;
		cout << "~Computer()" << endl;
	}

private:
	char * _brand;
	double _price;
	//静态成员位于全局静态区, 被整个类所创建的所有对象共享
	static double _totalPrice;
};

//全局的位置进行初始化(在进入main函数之前)
double Computer::_totalPrice = 0;

void test0()
{
	cout << "sizeof(Computer) = " << sizeof(Computer) << endl;
	Computer pc1("MateBook.....", 6666);
	cout << ">> pc1: " << endl;
	pc1.print();
	//pc1.printTotalprice();
	Computer::printTotalprice();

	Computer pc3("Thinkpad", 8888);
	cout << ">> pc3: " << endl;
	pc3.print();
	//pc3.printTotalprice();
	Computer::printTotalprice();//静态成员函数可以直接通过类名调用
}

int main(void)
{
	test0();
	Computer::printTotalprice();
	return 0;
}
