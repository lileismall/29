 ///
 /// @file    Thread.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-15 09:43:12
 ///

#include "Thread.h"

#include <iostream>
#include <functional>
using std::cout;
using std::endl;
using std::function;


namespace wd
{

namespace current_thread
{
	__thread const char * threadName = "wd thread";
}

struct ThreadData
{
	using ThreadCallback = function<void()>;

	ThreadData(const string & name, 
		ThreadCallback && cb)
	: _name(name)
	, _cb(std::move(cb))
	{}

	string _name;
	ThreadCallback _cb;


	void runInThread()
	{
		current_thread::threadName = _name == string() ? "wd thread" : _name.c_str();
		if(_cb)
			_cb();
	}
};

void Thread::start()
{
	ThreadData * threadData = new ThreadData(_name, std::move(_cb));

	pthread_create(&_pthid, nullptr, threadfunc, threadData);	
	_isRunning = true;
}

void * Thread::threadfunc(void * arg)
{
	ThreadData * threadData = static_cast<ThreadData *>(arg);
	if(threadData)
		threadData->runInThread();

	delete threadData;

	return nullptr;
}

void Thread::join()
{
	if(_isRunning)
		pthread_join(_pthid, nullptr);
}

Thread::~Thread()
{
	if(_isRunning) 
		pthread_detach(_pthid);
}

}//end of namespace wd
