 ///
 /// @file    EventThread.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-19 11:15:43
 ///
 
#pragma once
#include "Thread.h"
#include "Eventfd.h"
#include <iostream>
using std::cout;
using std::endl;
 
namespace wd
{

class EventThread
{
	using EventCallback = function<void()>;
public:
	EventThread(EventCallback && cb)
	: _eventfd(std::move(cb))
	, _thread(std::bind(&Eventfd::start, &_eventfd))
	{
	}

	void start()
	{
		_thread.start();
	}

	void wakeup()
	{
		_eventfd.wakeup();
	}

	void stop()
	{
		_eventfd.stop();
		_thread.join();
	}

private:
	Eventfd _eventfd;
	Thread _thread;
};

}//end of namespace wd
