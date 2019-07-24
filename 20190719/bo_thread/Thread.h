 ///
 /// @file    Thread.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-15 09:40:52
 ///
 
#pragma once

#include "Noncopyable.h"

#include <pthread.h>
#include <functional>
#include <string>
using std::function;
using std::string;
 
namespace wd
{

namespace current_thread
{
extern	__thread const char * threadName;
}//end of namespace current_thread

//具体类
class Thread
: Noncopyable
{
public:
	using ThreadCallback = function<void()>;

	Thread(ThreadCallback && cb, const string & name = string())
	: _pthid(0)
	, _isRunning(false)
	, _cb(std::move(cb))
	, _name(name)
	{}

	void start();
	void join();

	string getName() const {	return _name;	}

	~Thread();

private:
	static void * threadfunc(void * arg);

private:
	pthread_t _pthid;
	bool _isRunning;
	ThreadCallback _cb;
	string _name;
};

}//end of namespace wd
