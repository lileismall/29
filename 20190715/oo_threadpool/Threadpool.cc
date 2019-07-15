 ///
 /// @file    Threadpool.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-15 15:15:24
 ///
 
#include "Threadpool.h"
#include "WorkerThread.h"

#include <unistd.h>

#include <iostream>
using std::cout;
using std::endl;

namespace wd
{

Threadpool::Threadpool(size_t threadNum, size_t queSize)
: _threadNum(threadNum)
, _queSize(queSize)
, _taskque(queSize)
, _isExit(false)
{
	_threads.reserve(_threadNum);
}

Threadpool::~Threadpool()
{
	if(!_isExit)
		stop();
}

void Threadpool::start()
{
	for(size_t idx = 0; idx != _threadNum; ++idx) {
		unique_ptr<Thread> thread(new WorkerThread(*this));	
		_threads.push_back(std::move(thread));
		//_threads.push_back(thread);
	}

	for(auto & thread : _threads){
		thread->start();
	}
}

void Threadpool::stop()
{
	if(!_isExit) {

		while(!_taskque.empty()) {
			::sleep(1);
		}

		_isExit = true;
		_taskque.wakeup();
		for(auto & thread : _threads) {
			thread->join();
		}
	}
}

void Threadpool::addTask(Task * task)
{
	_taskque.push(task);
}

Task * Threadpool::getTask()
{
	return _taskque.pop();
}

//每一个子线程要完成的任务, 其运行在
//WorkerThread::run方法中
void Threadpool::threadfunc()
{
	while(!_isExit) 
	{
		Task * task = getTask();
		if(task)
			task->process();//当任务执行的速度过快
			//在还没有将_isExit设置为true之前，每一个子线程
			//已经阻塞在了getTask()方法之上；
	}
}

}//end of namespace wd
 
