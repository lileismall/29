 ///
 /// @file    atexit.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-25 15:20:53
 ///
 
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

void display()
{
	cout << "display()" << endl;
}
 
int main(void)
{
	cout << "enter main..." << endl;
	atexit(display);
	atexit(display);
	atexit(display);

	cout << "exit main..." << endl;
	return 0;
}
