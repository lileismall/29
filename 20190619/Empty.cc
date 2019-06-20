 ///
 /// @file    Empty.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-19 09:54:18
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Empty
{};
 
int main(void)
{
	Empty e1;
	Empty e2;
	&e1;
	&e2;
	cout << "sizeof(e1) = " << sizeof(e1) << endl;
	return 0;
}
