 ///
 /// @file    Computer2.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-18 15:08:20
 ///
 
#pragma once
 
//类的声明
class Computer
{//class的默认访问权限是private的
public:
	void setBrand(const char * brand);
	void setPrice(double price);
	void print();

//通过private关键字表现封装的特性
private://类对象占据的空间只与数据成员有关，
		//成员函数存储在程序代码区, 不会占据对象的空间
	char _brand[20];
	double _price;
};
