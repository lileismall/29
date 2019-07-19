 ///
 /// @file    Eventfd.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-19 10:19:01
 ///
 
#pragma once

#include <iostream>
#include <functional>
using std::cout;
using std::endl;
using std::function;
 

namespace wd
{

class Eventfd
{
public:
	using EventCallback = function<void()>; 
	
	Eventfd(EventCallback && cb);

	void start();//运行在B线程
	void stop();

	void wakeup();//运行在A线程

private:
	int createEventfd();
	void handleRead();

private:
	int _fd;
	EventCallback _cb;
	bool _isStarted;
};

}//end of namespace wd
