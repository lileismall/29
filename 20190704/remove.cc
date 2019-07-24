 ///
 /// @file    remove.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-04 11:09:56
 ///
 
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using std::cout;
using std::endl;
using std::vector;
using std::copy;
using std::remove;
using std::ostream_iterator;

void test0()
{
	vector<int> numbers{3, 2, 1, 66, 7, 4, 9, 66, 10, 66};
	copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	//remove的过程中，没有直接删除元素;
	//如果直接删除元素，可能会导致迭代器出现错误
	auto it = remove(numbers.begin(), numbers.end(), 66);
	numbers.erase(it, numbers.end());
	// erase-remove惯用法
	copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}
//一般情况下，在遍历容器元素的过程中，不要做删除元素和添加元素的操作
//防止发生迭代器失效的问题

void test1()
{
	vector<int> numbers;
	numbers.push_back(1);
	bool flag = true;
	//迭代器失效
	for(auto it = numbers.begin(); it != numbers.end(); ++it)
	{
		cout << *it << " ";
		if(flag) {
			numbers.push_back(2);
			flag = false;
		}
	}
}
 
int main(void)
{
	//test0();
	test1();
	return 0;
}
