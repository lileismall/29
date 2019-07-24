 ///
 /// @file    Subject.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-13 11:05:11
 ///
 
#include "Subject.h"

#include "Observer.h"

#include <algorithm>
	
void Ring::alarm()
{
	if(!_isRing) {
		_isRing = true;
		notify();
		_isRing = false;
	}
}

void Ring::attach(Observer * ob)
{
	auto it = std::find(_oblist.begin(),_oblist.end(), ob);
	if(it == _oblist.end())
		_oblist.push_back(ob);
}

void Ring::detach(Observer * ob) 
{
	auto it = std::find(_oblist.begin(),_oblist.end(), ob);
	if(it != _oblist.end())
		_oblist.erase(it);
}

void Ring::notify() 
{
	for(auto & ob : _oblist) {
		ob->update();
	}
}
