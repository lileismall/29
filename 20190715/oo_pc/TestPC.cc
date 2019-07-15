 ///
 /// @file    TestPC.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-15 09:38:51
 ///
 
#include "TaskQueue.h"
#include "Producer.h"
#include "Consumer.h"

#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;
using namespace wd;


 
int main(void)
{
	TaskQueue taskque(10);

	unique_ptr<Thread> producer1(new Producer(taskque));
	unique_ptr<Thread> producer2(new Producer(taskque));
	unique_ptr<Thread> consumer1(new Consumer(taskque));
	unique_ptr<Thread> consumer2(new Consumer(taskque));

	producer1->start();
	producer2->start();
	consumer1->start();
	consumer2->start();

	producer1->join();
	producer2->join();
	consumer1->join();
	consumer2->join();

	return 0;
}
