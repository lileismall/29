 ///
 /// @file    new.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-17 16:26:09
 ///
 
#include <stdlib.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;


//malloc/free与new/delete表达式的区别？
//相同点: 都是用来申请堆空间
//
//不同点:
//	1. malloc/free是库函数; new/delete是表达式
//	2. malloc开空间时，并不会进行初始化;new表达式是可以进行初始化

void test0()
{
	int * p0;

	int * p1 = (int *)malloc(sizeof(int));//系统调用
	::memset(p1, 0, sizeof(int));
	//bzero();
	*p1 = 10;
	printf("*p = %d\n", *p1);

	free(p1);


	int * p2 = (int *)malloc(sizeof(int) * 10); 

	free(p2);
}

void test1()
{
	int * p1 = new int(1);
	cout << "*p1 = " << *p1 << endl;

	delete p1;

	int * p2 = new int[10]();//对于数组的申请需要加上[]
							//加上小括号是有初始化
							//不加小括号是不会进行初始化
	delete [] p2;
}
 
int main(void)
{
	test0();
	test1();
	return 0;
}
