 ///
 /// @file    typecast.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-18 09:59:25
 ///
 
#include <iostream>
using std::cout;
using std::endl;

void test0()
{
	double val1 = 1.11;
	int val2 = (int)val1;
	int val3 = int(val1);
	
	cout << "val2 = " << val2 << endl;
	cout << "val3 = " << val3 << endl;
}

void test1()
{
	double val1 = 1.11;
	int val2 = static_cast<int>(val1);
	cout << "val2 = " << val2 << endl;

	int * p1 = static_cast<int*>(malloc(sizeof(int)));
	*p1 = 10;
	free(p1);

	//const_cast/dynamic_cast/reinterpret_cast
}
 
int main(void)
{
	//test0();
	test1();
	return 0;
}
