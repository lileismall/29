 ///
 /// @file    TestPC.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-15 09:38:51
 ///
 
#include "Thread.h"
#include "TaskQueue.h"

#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;
using namespace wd;


class Producer
{
public:
	void produce(TaskQueue & taskque)
	{
		::srand(::time(nullptr));
		int cnt = 20;
		while(cnt--)
		{
			int number = ::rand() % 100;
			taskque.push(number);
			cout << "cnt = " << cnt << "producer thread " << pthread_self()
				 << ": produce a number = " << number << endl;
			//::sleep(1);
		}
	}
};

class Consumer
{
public:
	void consume(TaskQueue & taskque)
	{
		int cnt = 20;
		while(cnt--) {
		int number = taskque.pop();
		cout << "consumer thread " << pthread_self() << " cnt = " << cnt  
			 << ":  consume a number = " << number << endl;
		::sleep(1);
		}
	}
};


 
int main(void)
{
	TaskQueue taskque(10);

	unique_ptr<Thread> producer1(new Thread(
		std::bind(&Producer::produce, Producer(), std::ref(taskque))
	));

	unique_ptr<Thread> producer2(new Thread(
		std::bind(&Producer::produce, Producer(), std::ref(taskque))
	));

	unique_ptr<Thread> consumer1(new Thread(
		std::bind(&Consumer::consume, Consumer(), std::ref(taskque))
	));

	unique_ptr<Thread> consumer2(new Thread(
		std::bind(&Consumer::consume, Consumer(), std::ref(taskque))
	));

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
