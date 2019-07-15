 ///
 /// @file    Consumer.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-15 11:35:56
 ///

#pragma once

#include "Thread.h"

namespace wd
{

class TaskQueue;

class Consumer
: public Thread
{
public:
	Consumer(TaskQueue & que)
	: _que(que)
	{}
private:
	void run() ;


private:
	TaskQueue & _que;
};


}//end of namespace wd
