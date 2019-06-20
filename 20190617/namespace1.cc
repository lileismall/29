 ///
 /// @file    namespace1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-17 14:51:45
 ///
 
#include <iostream>
using namespace std;//using编译指令, 它会一次性把std空间中
				    //的所有实体全部引进来
					//
					//要求：熟悉空间中的实体
					//目前来说，不推荐使用
             
void wd_display();
void tls_display();

void cout()
{
	
}

namespace wd
{
void display()
{
	cout << "wd::display() " << endl;
}


}//end of namespace wd

namespace tls
{

void display()
{
	cout << "tls::display() " << endl;
}

}//end of namespace tls


 
int main(void)
{
	wd::display();//::  作用域限定符, 这是完整形式
	tls::display();

	return 0;
}
