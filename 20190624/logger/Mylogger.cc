 ///
 /// @file    Mylogger.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-24 14:40:44
 ///
 
#include "Mylogger.h"

#include <log4cpp/Priority.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/PatternLayout.hh>

#include <iostream>
using std::cout;
using std::endl;

namespace wd
{

Mylogger * Mylogger::_pInstance = nullptr;

Mylogger * Mylogger::getInstance()
{
	if(_pInstance == nullptr) {
		_pInstance = new Mylogger();
	}
	return _pInstance;
}

void Mylogger::destroy()
{
	if(_pInstance)
		delete _pInstance;
}


void Mylogger::error(const char * msg)
{
	_root.error(msg);
}

void Mylogger::warn(const char * msg)
{
	_root.warn(msg);
}

void Mylogger::info(const char * msg)
{
	_root.info(msg);
}

void Mylogger::debug(const char * msg)
{
	_root.debug(msg);
}


Mylogger::Mylogger()
: _root(Category::getRoot().getInstance("root"))
{
	PatternLayout * ptn1 = new PatternLayout();
	ptn1->setConversionPattern("%d [%p] %m%n");

	PatternLayout * ptn2 = new PatternLayout();
	ptn2->setConversionPattern("%d [%p] %m%n");

	OstreamAppender * ostreamAppender = new OstreamAppender("ostreamAppender", &cout);
	ostreamAppender->setLayout(ptn1);

	FileAppender * fileAppender = new FileAppender("fileAppender", "wangdao.log");
	fileAppender->setLayout(ptn2);

	_root.addAppender(ostreamAppender);
	_root.addAppender(fileAppender);
	_root.setPriority(Priority::DEBUG);

	cout << "Mylogger()" << endl;
}

Mylogger::~Mylogger()
{
	Category::shutdown();
	cout << "~Mylogger()" << endl;
}


}//end of namespace wd
 
