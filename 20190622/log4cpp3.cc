 ///
 /// @file    log4cpp3.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-22 11:06:42
 ///

#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/PatternLayout.hh>

#include <iostream>
using std::cout;
using std::endl;

using namespace log4cpp;
 
int main(void)
{
	PatternLayout * ptnLayout1 = new PatternLayout();
	ptnLayout1->setConversionPattern("%d [%p] %m%n");

	PatternLayout * ptnLayout2 = new PatternLayout();
	ptnLayout2->setConversionPattern("%d [%p] %m%n");

	PatternLayout * ptnLayout3 = new PatternLayout();
	ptnLayout3->setConversionPattern("%d [%p] %m%n");


	OstreamAppender * ostreamAppender = new OstreamAppender("ostreamAppender", &cout);
	ostreamAppender->setLayout(ptnLayout1);

	FileAppender * fileAppender = new FileAppender("fileAppender", "wangdao.log");
	fileAppender->setLayout(ptnLayout2);

	RollingFileAppender * rollingFileAppender = new 
		RollingFileAppender("rollingfileAppender",
			"rollingwangdao.log",
			5 * 1024,
			2);
	rollingFileAppender->setLayout(ptnLayout3);

	Category & root = Category::getRoot();
	root.setAppender(ostreamAppender);
	root.addAppender(fileAppender);
	root.addAppender(rollingFileAppender);

	root.setPriority(Priority::DEBUG);//日志记录器的级别
 
	int cnt = 100;
	while(cnt--) {
		root.alert("alert message");//一条日志的级别
		root.crit("crit message");
		root.debug("debug message");
		root.error("error message");
		root.emerg("emerg message");
		root.info("info message");
		root.fatal("fatal message");
		root.warn("warn message");
	}

	Category::shutdown();//回收资源

	return 0;
}
