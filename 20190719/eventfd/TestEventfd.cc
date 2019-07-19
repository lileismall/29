 ///
 /// @file    TestEventfd.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-19 10:59:37
 ///

#include "EventThread.h"

#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>
using std::cout;
using std::endl;

void getNumber()
{
	::srand(::time(nullptr));
	int number = ::rand() % 100;
	cout << ">> sub thread: get a number  = " << number << endl;
}
 
int main(void)
{
	wd::EventThread eventfd(getNumber);
	eventfd.start();
	int cnt = 10;
	while(cnt--) {
		eventfd.wakeup();	
		cout << "main thread notify sub thread..." << endl;
		::sleep(1);
	}

	cout << "main thread" << endl;
	eventfd.stop();
 
	return 0;
}
