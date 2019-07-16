 ///
 /// @file    TestThreadpool.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-15 15:53:24
 ///
 
#include "Threadpool.h"

#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>
using std::cout;
using std::endl;
using namespace wd;

class Mytask
{
public:
	void process()
	{
		::srand(::time(nullptr));	
		int number = ::rand() % 100;
		cout << ">>> sub Thread " << pthread_self()
			 << " Mytask: number = " << number << endl;
		::sleep(1);
	}

	~Mytask() {	cout << "~Mytask()" << endl;	}
	
};
 
int main(void)
{
	Threadpool threadpool;
	threadpool.start();

	Mytask task;

	int cnt = 20;
	while(cnt--) {
		//threadpool.addTask(std::bind(&Mytask::process, Mytask()));
		threadpool.addTask(std::bind(&Mytask::process, &task));
		cout << "main thread " << pthread_self()
			 << ": cnt = " << cnt << endl;
	}

	threadpool.stop();

	return 0;
}
