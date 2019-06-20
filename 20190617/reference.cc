 ///
 /// @file    reference.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-17 17:08:43
 ///
 
#include <iostream>
using std::cout;
using std::endl;


//引用于指针的区别？
//相同点: 引用底层的实现还是指针, 引用于指针都有"地址"的概念 
//
//不同点:
//	1. 引用是一个变量的别名，必须要进行初始化
//	   指针是一个独立的实体，可以不进行初始化
//	2. 引用不是一个独立的实体
//	3. 引用一经绑定之后，就不会就再改变其指向;
//	   指针是很灵活的，可以改变指向

void test0()
{
	int number = 1;
	//引用是变量的别名
	int & ref = number;
	cout << "ref = " << ref << endl;
	cout << "number = " << number << endl;

	ref = 10;
	cout << ">> 修改引用之后:" << endl;
	cout << "ref = " << ref << endl;
	cout << "number = " << number << endl;
	cout << "&ref = " << &ref << endl
		 << "&number = " << &number << endl;


	//int & ref2;//error 引用不能单独存在,必须要绑定到一个实体
				 //引用必须要进行初始化
} 



//值传递 ==> 复制
#if 0
void swap(int x, int y)
{
	int temp = x;
	x = y;
	y = temp;
}
#endif

//地址传递 ==> 值传递 ==> 复制
void swap(int * px, int * py)
{
	int temp = *px;
	*px = *py;
	*py = temp;
}

//引用作为函数的参数存在
// 引用传递 ==> 没有复制的开销，
//可以提高程序的执行效率，
//传递参数的方式更加直观，自然
void swap(int & x, int & y)
{
	int temp = x;
	x = y;
	y = temp;
}

void test1()
{
	int a = 3, b = 4;
	cout << "a = " << a << ", b = " << b << endl;
	swap(a, b);
	//swap(&a, &b);
	cout << "a = " << a << ", b = " << b << endl;
}


//引用还可以作为返回值存在

int array[5] = {1, 2, 3, 4, 5};


int func1()
{
	int number = 5;
	return number;//会进行复制
}

int & getNumber(int idx)
{
	return array[idx];//如果返回值是引用，不会进行复制
}

//不能返回一个局部变量的引用
int & func2()
{//当函数执行完毕时，局部变量生命周期已经结束
	int number = 5;
	return number;
}

//不要轻易返回一个堆空间变量的引用
//除非已经有了内存回收的策略
int & func3()
{
	int * p3 = new int(100);
	return *p3;
}

void test2()
{
	int idx = 0;
	cout << "array[idx] = " << getNumber(idx) << endl;
	&getNumber(1);

	getNumber(idx) = 10;//左值：就是可以取地址
	cout << "array[idx] = " << getNumber(idx) << endl;

	//&func1();//error 右值（临时变量）: 不可以取地址
	//func1() = 100;//error

	//int & ref = func2();
	//cout << "ref = " << ref << endl;//error

	int & ref2 = func3();
	cout << "ref2 = " << ref2 << endl;
	delete &ref2;

	int a = 3, b = 4, c = 5;

	c = a + func3() + b + c;//执行该表达式之后，就会发生内存泄漏
	cout << "c = " << c << endl;
}


int main(void)
{
	//test0();
	//test1();
	test2();
	return 0;
}
