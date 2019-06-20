 ///
 /// @file    bool.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-18 10:33:46
 ///
 
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;
 
int main(void)
{
	//C用0和非0代表错误和正确
	
	//_Bool
	
	cout << "sizeof(bool) = " << sizeof(bool) << endl;
	
	bool b1 = 100;
	bool b2 = 0;
	bool b3 = -1;
	bool b4 = true;
	bool b5 = false;
	bool b6 = 1;
	
	cout << "b1 = " << b1 << endl
		 << "b2 = " << b2 << endl
		 << "b3 = " << b3 << endl
		 << "b4 = " << b4 << endl
		 << "b5 = " << b5 << endl
		 << "b6 = " << b6 << endl;

}
