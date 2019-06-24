 ///
 /// @file    log4cpp2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-22 11:06:42
 ///

#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/PatternLayout.hh>

#include <iostream>
using std::cout;
using std::endl;

using namespace log4cpp;
 
int main(void)
{
	PatternLayout * ptnLayout = new PatternLayout();
	ptnLayout->setConversionPattern("%d [%p] %m%n");

	OstreamAppender * ostreamAppender = new OstreamAppender("ostreamAppender", &cout);
	ostreamAppender->setLayout(ptnLayout);

	Category & root = Category::getRoot();
	root.setAppender(ostreamAppender);
	root.setPriority(Priority::WARN);//日志记录器的级别
 
	root.alert("alert message");//一条日志的级别
	root.crit("crit message");
	root.debug("debug message");
	root.error("error message");
	root.emerg("emerg message");
	root.info("info message");
	root.fatal("fatal message");
	root.warn("warn message");

	Category::shutdown();//回收资源

	return 0;
}
