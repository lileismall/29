 ///
 /// @file    sequenceContainer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-01 16:17:51
 ///
 
#include <iostream>
#include <vector>
#include <list>
#include <deque>
using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::deque;

class Example
{
public:
	int _data;
	class Pimpl;
};

//Example::_data;
//Example::Pimpl;


template <class Container>
void display(const Container & c)
{
	typename Container::const_iterator it = c.begin();
	while(it != c.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void test0()
{
	cout << ">>> test vector: " << endl;
	//int arr[5] = {1, 2, 3, 4, 5};
	//vector<int> numbers(10, 1);
	//vector<int> numbers(arr, arr + 5);
	vector<int> numbers{1, 2, 3, 4, 5};//动态数组
	display(numbers);
	cout << ">> number's capacity = " << numbers.capacity() << endl;

	cout << "sizeof(numbers) = " << sizeof(numbers) << endl;
	
	//vector没有提供push_front/pop_front？？？
	//如果提供，其时间复杂度为O(N)
	//
	//vector不提倡在头部添加或者删除元素
	//
	//numbers.push_back(11);
	//numbers.push_back(12);
	//display(numbers);
	//numbers.pop_back();
	display(numbers);

	cout << "numbers[2] = " << numbers[2] << endl;

	cout << ">> test insert :" << endl;
	cout << ">> number's capacity = " << numbers.capacity() << endl;
	//insert
	//vector<int>::iterator it = numbers.begin();
	auto it = numbers.begin();//auto关键字具有自动推导的功能
	++it;
	cout << "*it = " << *it << endl;
	//vector的insert操作时间复杂度为O(N)
	auto it2 = numbers.insert(it, 22);// 必须重新获取迭代器 
	cout << "*it = " << *it << endl;//无效值, 迭代器失效了
	cout << "*it2 = " << *it2 << endl;
	display(numbers);

	numbers.insert(it2, 3, 33);
	display(numbers);
	cout << "*it2 = " << *it2 << endl;
	
	it = numbers.begin();
	vector<int> numbers2{41, 42, 43, 44};
	numbers.insert(it, numbers2.begin(), numbers2.end());
	display(numbers);
	numbers.shrink_to_fit();//如果要回收多余的空间，可以使用shrink_to_fit
	cout << ">> number's capacity = " << numbers.capacity() << endl;

	cout << ">> clear elemnts test:" << endl;
	numbers.clear();//对于vector来说，清空元素之后，没有回收空间的
	display(numbers);
	numbers.shrink_to_fit();//如果要回收多余的空间，可以使用shrink_to_fit
	cout << ">> number's capacity = " << numbers.capacity() << endl;

}

void test1()
{
	cout << endl << ">>> test deque: " << endl;
	int arr[5] = {1, 2, 3, 4, 5};
	//deque<int> numbers(10, 2);
	//deque<int> numbers(arr, arr + 5);
	deque<int> numbers{1, 2, 3, 4, 5};// 双端队列
	display(numbers);
	//deque没有capacity() 方法
	//cout << ">> number's capacity = " << numbers.capacity() << endl;//error
	
	numbers.push_back(21);
	numbers.push_front(31);
	display(numbers);
	numbers.pop_front();
	display(numbers);

	cout << "numbers[2] = " << numbers[2] << endl;

	cout << ">> test insert :" << endl;
	//insert
	auto it = numbers.begin();//auto关键字具有自动推导的功能
	++it;
	cout << "*it = " << *it << endl;
	//deque的insert操作时间复杂度为O(N)
	auto it2 = numbers.insert(it, 22);// 必须重新获取迭代器
	cout << "*it = " << *it << endl;//无效值, 迭代器失效了
	cout << "*it2 = " << *it2 << endl;
	display(numbers);

	numbers.insert(it2, 3, 33);
	display(numbers);
	cout << "*it2 = " << *it2 << endl;
	
	it = numbers.begin();
	vector<int> numbers2{41, 42, 43, 44};
	numbers.insert(it, numbers2.begin(), numbers2.end());
	display(numbers);
	cout << ">> clear elemnts test:" << endl;
	numbers.clear();
	display(numbers);
	numbers.shrink_to_fit();
}

void test2()
{
	cout << endl << ">>> test list: " << endl;
	int arr[5] = {1, 2, 3, 4, 5};
	//list<int> numbers(10);
	//list<int> numbers(arr, arr + 5);
	list<int> numbers{1, 2, 3, 4, 5};//双向链表
	display(numbers);
	//list没有capacity() 方法
	//cout << ">> number's capacity = " << numbers.capacity() << endl;
	
	numbers.push_back(21); //时间复杂度为O(1)
	numbers.push_front(31);
	display(numbers);
	numbers.pop_front();
	display(numbers);

	//list不支持下标访问， 只支持双向访问
	//cout << "numbers[2] = " << numbers[2] << endl;
	cout << ">> test insert :" << endl;
	//insert
	auto it = numbers.begin();//auto关键字具有自动推导的功能
	++it;
	cout << "*it = " << *it << endl;
	//list的insert操作时间复杂度为O(1)
	auto it2 = numbers.insert(it, 22);
	cout << "*it = " << *it << endl;
	cout << "*it2 = " << *it2 << endl;
	display(numbers);

	numbers.insert(it2, 3, 33);
	display(numbers);
	cout << "*it2 = " << *it2 << endl;
	
	it = numbers.begin();
	vector<int> numbers2{41, 42, 43, 44};
	numbers.insert(it, numbers2.begin(), numbers2.end());
	display(numbers);

	cout << ">> clear elemnts test:" << endl;
	numbers.clear();
	display(numbers);
}

 
int main(void)
{
	test0();
	test1();
	test2();
	return 0;
}
