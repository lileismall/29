 ///
 /// @file    Computer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-18 14:46:25
 ///
 
#include "Computer2.h"
#include <string.h>

#include <iostream>
using std::cout;
using std::endl;
 
//类的实现
void Computer::setBrand(const char * brand)
{
	strcpy(_brand, brand);
}

void Computer::setPrice(double price)
{
	_price = price;
}

void Computer::print()
{
	cout << "brand:" << _brand << endl
		 << "price:" << _price << endl;
}
