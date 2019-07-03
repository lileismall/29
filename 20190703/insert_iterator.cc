 ///
 /// @file    insert_iterator.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-03 11:48:25
 ///
 
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <iterator>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::copy;
using std::set;


//都采用了适配器设计模式
//stack/queue/prioty_queue
using std::ostream_iterator;
using std::back_insert_iterator;//在尾部添加元素
using std::front_insert_iterator;//在头部添加元素
using std::insert_iterator;//在任意添加元素
 
int main(void)
{
	vector<int> numbers{1, 2, 3};

	for(auto rit = numbers.rbegin(); rit != numbers.rend(); ++rit)
	{
		cout << *rit << " ";
	}
	cout << endl;


	list<int> numbers2{11, 12, 13};

	//back_insert_iterator调用push_back方法
	//适用容器 vector/deque/list
	copy(numbers2.begin(), numbers2.end(), 
			back_insert_iterator<vector<int>>(numbers));
	copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	//front_insert_iterator调用push_front方法
	//适用容器 deque/list
	copy(numbers.begin(), numbers.end(), 
			front_insert_iterator<list<int>>(numbers2));
	copy(numbers2.begin(), numbers2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	//insert_iterator调用的是insert方法
	set<int> numbers3{22, 23, 24};
	copy(numbers.begin(), numbers.end(), insert_iterator<set<int>>(numbers3, ++numbers3.begin()));
	copy(numbers3.begin(), numbers3.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	return 0;
}
