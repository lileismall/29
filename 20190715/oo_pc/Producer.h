 ///
 /// @file    Producer.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-15 11:29:13
 ///
 
#pragma once

#include "Thread.h"

#include <iostream>
using std::cout;
using std::endl;

namespace wd
{
class TaskQueue;

class Producer
: public Thread
{
public:
	Producer(TaskQueue & que)
	: _que(que)
	{}	

private:
	void run();

private:
	TaskQueue & _que;
};

}//end of namespace wd

 
