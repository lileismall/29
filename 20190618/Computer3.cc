 ///
 /// @file    Computer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-18 14:46:25
 ///
 
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;


class Computer
{
public:
	Computer(const char * brand, double price)
	: _brand(new char[strlen(brand) + 1]())  //浅拷贝, 只传地址
	, _price(price)
	{
		strcpy(_brand, brand);
		cout << "Computer(const char *, double)" << endl;
	}
	

	void print()
	{
		cout << "   brand:" << _brand << endl
			 << "   price:" << _price << endl;
	}

	//对象销毁的过程中会自动调用析构函数
	//
	//问题: 执行了析构函数就是销毁了对象
	
#if 0
	void release()
	{
		delete [] _brand;
	}
#endif

	~Computer()
	{	//析构函数的作用：是用来回收对象申请的资源
		if(_brand) {
			delete [] _brand;
			_brand = nullptr;//NULL
		}
		cout << "~Computer()" << endl;
	}

private:
	char * _brand;
	double _price;
};

//Computer pc2("Xiaomi", 7500);
 
int test0(void)
{
	{
	Computer pc1("MateBook", 6666);
	cout << ">> pc1: " << endl;
	pc1.print();
	}

	cout << ">> pc2: " << endl;
//	pc2.print();

	//堆空间的对象的销毁，需要手动执行
	Computer * pc3 = new Computer("Thinkpad", 7777);
	cout << ">> pc3: " << endl;
	pc3->print();

	delete pc3;//不要忘了, 执行delete表达式的过程中，就会调用析构函数

	static Computer pc4("Macbook pro", 20000);
	cout << ">> pc4: " << endl;
	pc4.print();

	return 0;
}

void test1()
{
	Computer * pc3 = new Computer("Thinkpad", 7777);
	cout << ">> pc3: " << endl;
	pc3->print();
	pc3->~Computer();//该语句被执行之后，对象是没有被销毁的
	delete pc3;
}

void test2()
{
	Computer pc1("MateBook", 6666);
	cout << ">> pc1: " << endl;
	pc1.print();
	pc1.~Computer();//析构函数可以主动调用，但不推荐这样做
				    //析构函数应该让其自动执行
	//pc1.release();
}

int main(void)
{
	//test1();
	test2();
	return 0;
}
