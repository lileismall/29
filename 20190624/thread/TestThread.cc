 ///
 /// @file    TestThread.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-24 11:27:17
 ///
 
#include "MutexLock.h"
#include "Condition.h"

#include <iostream>
using std::cout;
using std::endl;

int tickets = 1000;
bool flag = true;
wd::MutexLock mutex;
//wd::MutexLock mutex2(mutex);//error
wd::Condition cond(mutex);


void * threadfunc1(void * arg)
{//1号窗口，当flag为true时，卖票
	int cnt = 100;
	while(cnt--) {
		wd::MutexLockGuard autolock(mutex);
		if(!flag) {
			cond.wait();
		}

		//....异常行为，直接退出，也有可能导致死锁
		--tickets;
		cout << ">> 1号窗口卖票之后，还剩余" << tickets << "票" << endl;
		if(flag)
			flag = false;
		cond.notify();

	}
	return nullptr;
}

void * threadfunc2(void * arg)
{//2号窗口，当flag为false时，卖票
	int cnt =100;
	while(cnt--) {
		wd::MutexLockGuard autolock(mutex);
		if(flag) {
			cond.wait();
		}

		--tickets;
		cout << ">> 2号窗口卖票之后，还剩余" << tickets << "票" << endl;
		if(!flag)
			flag = true;
		cond.notify();
	}
	return nullptr;
}
 
int main(void)
{
	pthread_t pthid1, pthid2;

	pthread_create(&pthid1, nullptr, threadfunc1, nullptr);
	pthread_create(&pthid2, nullptr, threadfunc2, nullptr);

	pthread_join(pthid1, nullptr);
	pthread_join(pthid2, nullptr);

	return 0;
}
