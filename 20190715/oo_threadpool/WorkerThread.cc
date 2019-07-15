 ///
 /// @file    WorkerThread.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-15 15:21:13
 ///
 
#include "WorkerThread.h"

#include "Threadpool.h"

#include <iostream>
using std::cout;
using std::endl;

namespace wd
{

WorkerThread::WorkerThread(Threadpool & threadpool)
: _threadpool(threadpool)
{
	cout << "WorkerThread()" << endl;
}

WorkerThread::~WorkerThread()
{
	cout << "~WorkerThread()" << endl;	
}

void WorkerThread::run()
{
	_threadpool.threadfunc();
}

}//end of namespace wd
 
