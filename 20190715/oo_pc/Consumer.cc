 ///
 /// @file    Consumer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-15 11:37:24
 /// 
#include "Consumer.h"
#include "TaskQueue.h"

#include <unistd.h>

#include <iostream>
using std::cout;
using std::endl;
 
namespace wd
{

void Consumer::run() 
{
	int cnt = 20;
	while(cnt--) 
	{
		int number = _que.pop();
		cout << "consumer thread " << pthread_self() << " cnt = " << cnt  
			 << ":  consume a number = " << number << endl;
		::sleep(1);
	}
}
}//end of namespace wd
