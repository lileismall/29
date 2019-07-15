 ///
 /// @file    Task.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-15 15:06:36
 ///
 
#pragma once

namespace wd
{

class Task
{
public:
	virtual 
	void process()=0;

	virtual ~Task() {}
};

}//end of namespace wd
