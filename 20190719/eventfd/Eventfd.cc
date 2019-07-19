 ///
 /// @file    Eventfd.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-19 10:21:40
 ///
 
#include "Eventfd.h"

#include <unistd.h>
#include <poll.h>
#include <sys/eventfd.h>

#include <iostream>
using std::cout;
using std::endl;
 
namespace wd
{

Eventfd::Eventfd(EventCallback && cb)
: _fd(createEventfd())
, _cb(std::move(cb))
, _isStarted(false)
{}

void Eventfd::start()
{
	_isStarted = true;

	struct pollfd pfd;
	pfd.fd = _fd;
	pfd.events = POLLIN;

	while(_isStarted) {
		int nready = ::poll(&pfd, 1, 5000);	
		if(nready == -1 && errno == EINTR)
			continue;
		else if(nready == -1)
			return;
		else if(nready == 0)
			printf(">> poll timeout!!\n");
		else {
			if(pfd.revents & POLLIN) {
				handleRead();
				if(_cb)
					_cb();
			}
		}
	}
}

void Eventfd::stop()
{
	if(_isStarted) {
		_isStarted = false;
	}
}

void Eventfd::wakeup()
{
	uint64_t one = 1;
	int ret = ::write(_fd, &one, sizeof(one));
	if(ret != sizeof(one)) {
		perror(">> write");
	}
}

int Eventfd::createEventfd()
{
	int fd = ::eventfd(10, 0);
	if(fd == -1) {
		perror(">> eventfd");
	}
	return fd;
}


void Eventfd::handleRead()
{
	uint64_t howmany;
	int ret = ::read(_fd, &howmany, sizeof(uint64_t));
	if(ret != sizeof(howmany)) {
		perror(">> read");
	}
}
}//end of namespace wd
