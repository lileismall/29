 ///
 /// @file    Line.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-25 14:31:58
 ///
 
#pragma once


//PIMPL设计模式:
//优点:
//	 1. 可以实现信息隐藏
//	 2. 可以降低编译依赖, 以最低的成本完成库的平滑升级

class Line
{
	class LineImpl;
public:
	Line(int x1, int y1, int x2, int y2);

	~Line();

	void printLine() const;
private:
	LineImpl * _pimpl;
};
