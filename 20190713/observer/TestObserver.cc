 ///
 /// @file    TestObserver.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-13 11:32:32
 ///
 
#include "Subject.h"
#include "Observer.h"

#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;

void test0()
{
	unique_ptr<Observer> baby1(new Baby("豆豆"));
	unique_ptr<Observer> baby2(new Baby("小米"));

	unique_ptr<Observer> nurse1(new Nurse("小丽"));
	unique_ptr<Observer> nurse2(new Nurse("小红"));

	Ring ring;
	ring.attach(baby1.get());
	ring.attach(baby2.get());
	ring.attach(nurse1.get());
	ring.attach(nurse2.get());

	Guest guest("熊大");
	guest.knock(ring);
	cout << "------" << endl;

	ring.detach(nurse2.get());
	
	guest.knock(ring);
}
 
int main(void)
{
	test0();
	return 0;
}
