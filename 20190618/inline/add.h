 ///
 /// @file    add.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-18 10:24:46
 ///
 

#pragma once

//inline函数可以有声明和实现，但是必须在同一文件
//inline函数不能分成头文件和实现文件
inline int add(int x, int y)
{	//一般不要放循环语句
	return x + y;
}

//......


#if 0
inline int add(int x, int y)
{
	return x + y;
}
#endif

