 ///
 /// @file    sizeof.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-24 16:16:30
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
int main(void)
{
	int a = 1;
	//长度运算符, 发生时机：编译时，不是在运算时
	//sizeof不是函数
	printf("sizeof(a) = %d\n", sizeof a);

	return 0;
}
