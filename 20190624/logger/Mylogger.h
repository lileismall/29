 ///
 /// @file    Mylogger.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-24 14:36:26
 ///
 
#pragma once

#include <log4cpp/Category.hh>

using namespace log4cpp;


namespace wd
{

class Mylogger
{
public:
	static Mylogger * getInstance();
	static void destroy();

	void error(const char * msg);
	template <class... Args>
	void error(Args... args)
	{
		_root.error(args...);
	}

	void warn(const char * msg);
	void info(const char * msg);
	void debug(const char * msg);

private:
	Mylogger();
	~Mylogger();

private:
	static Mylogger * _pInstance;
	Category & _root;
};

}//end of namespace wd

#define prefix(msg)	string("[").append(__FILE__)\
		.append(":").append(__FUNCTION__)\
		.append(":").append(std::to_string(__LINE__))\
		.append("] ").append(msg).c_str()
	
#define LogError(msg, ...) wd::Mylogger::getInstance()->error(prefix(msg), ##__VA_ARGS__)
#define LogWarn(msg) wd::Mylogger::getInstance()->warn(prefix(msg))
#define LogInfo(msg) wd::Mylogger::getInstance()->info(prefix(msg))
#define LogDebug(msg) wd::Mylogger::getInstance()->debug(prefix(msg))

