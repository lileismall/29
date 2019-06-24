 ///
 /// @file    TestMylogger.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-24 14:51:09
 ///
 
#include "Mylogger.h"

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

void test0()
{
	wd::Mylogger::getInstance()->error("error message");
	wd::Mylogger::getInstance()->warn("warn message");
	wd::Mylogger::getInstance()->info("info message");
	wd::Mylogger::getInstance()->debug("debug message");
}

void test1()
{
	cout << __func__ << endl;
	cout << __FILE__ << endl;
	cout << __LINE__ << endl;
}


void test2()
{
	wd::Mylogger::getInstance()->error(prefix("error message"));
	//wd::Mylogger::getInstance()->warn("warn message");
	//wd::Mylogger::getInstance()->info("info message");
	//wd::Mylogger::getInstance()->debug("debug message");
}
 
void test3()
{
	int number = 1;
	LogError("error message %d", number);

	LogWarn("warn message");
	LogInfo("info message");
	LogDebug("debug message");
}

int main(void)
{
	//test0();
	//test1();
	//test2();
	test3();

	wd::Mylogger::getInstance()->destroy();
	return 0;
}
