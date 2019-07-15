 ///
 /// @file    WorkerThread.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-15 15:19:07
 ///
 
#pragma once

#include "Thread.h"

namespace wd
{

class Threadpool;
class WorkerThread
: public Thread
{
public:
	WorkerThread(Threadpool & threadpool);
	~WorkerThread();
	
	void run();

private:
	Threadpool & _threadpool;

};

}//end of namespace wd
