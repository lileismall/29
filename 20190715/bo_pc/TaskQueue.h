 ///
 /// @file    TaskQueue.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-15 11:11:24
 ///
 
#pragma once

#include "MutexLock.h"
#include "Condition.h"

#include <queue>
using std::queue;

namespace wd
{


class TaskQueue
{
public:
	TaskQueue(size_t queSize = 10);

	bool empty() const;
	bool full() const;
	void push(int number);
	int pop();

private:
	size_t _queSize;
	queue<int> _que;
	MutexLock _mutex;
	Condition _notFull;
	Condition _notEmpty;
};


}//end of namespace wd

 
