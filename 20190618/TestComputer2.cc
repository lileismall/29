 ///
 /// @file    TestComputer2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-18 15:09:31
 ///
 
#include "Computer2.h"
#include <iostream>
using std::cout;
using std::endl;

void display()
{
	int a = 100;
	cout << "display()" << endl;
	cout << "a = " << a << endl;
}
 
int main(void)
{
	display();

	Computer pc1;
	pc1.setBrand("Thinkpad");//Computer::serBrand()
	pc1.setPrice(8888);
	pc1.print();

	cout << "sizeof(Computer) = " << sizeof(Computer) << endl;
}
