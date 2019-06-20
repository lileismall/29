 ///
 /// @file    Computer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-18 14:46:25
 ///
 
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;


//代码风格是非常重要的


//如果是自定义类类型，都要大写首字母
class Computer
{
public://public成员可以在类之外访问
	//public成员称为类对外的接口、功能、服务
	
	//对成员函数采用驼峰方式进行命名
	void setBrand(const char * brand)
	{
		strcpy(_brand, brand);
	}

	void setPrice(double price)
	{
		_price = price;
	}

//protected://保护成员不能在类之外访问
	void print()
	{
		cout << "brand:" << _brand << endl
			 << "price:" << _price << endl;
	}

//私有成员尽量放到类的底部
private://私有的成员不能在类之外访问
	char _brand[20];//brand_ /  m_brand
	double _price;
};
 
int main(void)
{
	int a;

	Computer pc1;
	pc1.setBrand("Thinkpad");
	pc1.setPrice(8888);
	pc1.print();

	
	//pc1._price = 1000;//error

	

	return 0;
}
