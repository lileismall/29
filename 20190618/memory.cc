 ///
 /// @file    memory.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-18 11:38:49
 ///
 
#include <stdio.h>
#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

int a = 1;//全局静态区
char * p1;//全局变量如果没有显式进行初始化，
		  //系统也会设置默认值
 
int test0(void)
{
	int b = 2;
	const char * p2 = "hello,world";//文字常量区
	char str[] = "hello,world";//栈区
	//str = 0x1000;//str 常量
	
	char * p3;//野指针
	
	p3 = new char[20]();//堆区

	strcpy(p3, "hello,world");

	static int c = 100;//局部静态变量, 全局/静态区
	++c;

	printf("sizeof(str) = %lu\n", sizeof(str));
	printf("sizeof(p2) = %lu\n", strlen(p2));
 
	printf("&a = %p\n", &a);
	printf("&b = %p\n", &b);
	printf("p1 = %p\n", p1);
	printf("&p1 = %p\n", &p1);
	printf("p2 = %p\n", p2);
	printf("&p2 = %p\n", &p2);
	printf("str = %p\n", str);
	printf("p3 = %p\n", p3);
	//*p3 = '1';//error 野指针
	printf("&p3 = %p\n", &p3);
	printf("&c = %p\n", &c);
	printf("address(hello,world) = %p\n", "hello,world");
	printf("address(test0) = %p\n", &test0);//程序代码区

	return 0;
}

int main(void)
{
	test0();
	return 0;
}
