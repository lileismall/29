 ///
 /// @file    string.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-18 10:59:40
 ///
 
#include <string.h>

#include <string>
#include <iostream>
using std::cout;
using std::endl;

void test0()
{
	const char * pstr1 = "hello";// 文字常量区, 只读的
	const char * pstr2 = "world";//C风格字符串
	//*pstr1 = 'X';//error  不能进行修改
	
	//空间是否足够
	char * ptmp = new char[strlen(pstr1) + strlen(pstr2) + 1]();
	strcpy(ptmp, pstr1);
	strcat(ptmp, pstr2);
	cout << "ptmp = " << ptmp << endl;

	delete [] ptmp;

	//获取字符串的长度
	//strlen  ==> 时间复杂度是O(N)

}

void test1()
{
	//把C风格字符串转换成C++风格的字符串
	std::string s1 = "hello";
	std::string s2 = "world";

	//做字符串的拼接
	std::string s3 = s1 + s2;
	cout << "s3 = " << s3 << endl;
	s3 += "aaa";
	cout << "s3 = " << s3 << endl;


	//获取字符串的长度
	cout << "s3'size = " << s3.size() << endl;
	cout << "s3'length = " << s3.length() << endl;
	
	//把C++风格字符串转换成C风格字符串
	const char * pstr = s3.c_str();
	const char * pstr2 = s3.data();
	cout << "pstr = " << pstr << endl;
	cout << "pstr2 = " << pstr2 << endl;

	//遍历元素
	for(size_t idx = 0; idx != s3.size(); ++idx) 
	{
		cout << s3[idx] << endl;//数组的下标进行访问
	}

	//&s3;   代表的是std::string类型的对象的首地址
	
	
	s3.append(3, 'j');
	cout << "s3 = " << s3 << endl;
	s3.append(s1);
	cout << "s3 = " << s3 << endl;
	s3.append("wangdao");
	cout << "s3 = " << s3 << endl;
	s3.append("shenzhen", 4);
	cout << "s3 = " << s3 << endl;
	
	//查找元素的用法
	size_t pos = s3.find("world");
	cout << "pos = " << pos << endl;
	std::string s4 = s3.substr(pos, 5);
	cout << "s4 = " << s4 << endl;

}
 
int main(void)
{
	test0();
	test1();
	return 0;
}
