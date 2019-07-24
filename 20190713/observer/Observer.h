 ///
 /// @file    Observer.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-13 11:04:21
 ///
 
#pragma once
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;


class Observer
{
public:
	virtual void update() = 0;
	//
	//直接传递状态(消息)的方式，称为推模式
	//virtual void update(Status status)=0;
	//
	//传递的是主题的指针或者引用，需要观察者
	//自己对消息进行处理，称为拉模式
	//virtual void update(Subject * ) = 0;
	virtual ~Observer() {}
};

class Baby
: public Observer
{
public:
	Baby(const string & name)
	: _name(name)
	{}

	void update() override;

private:
	string _name;

};

class Nurse
: public Observer
{
public:
	Nurse(const string & name)
	: _name(name)
	{}

	void update() override;

private:
	string _name;
};

class Ring;
class Guest
{
public:
	Guest(const string & name)
	: _name(name)
	{}

	void knock(Ring & ring);

private:
	string _name;
};
 
