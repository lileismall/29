 ///
 /// @file    testAdd.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-01 11:31:43
 ///
 
#include "add.h"

//int add<int>(int,int);

#include <iostream>
using std::cout;
using std::endl;
 
int main(void)
{
	int a = 3, b = 4;
	cout << "add(a, b) = " << add(a, b) << endl;
	return 0;
}
