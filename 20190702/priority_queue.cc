 ///
 /// @file    priority_queue.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-02 16:10:20
 ///
 
#include <iostream>
#include <queue> 
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::priority_queue;

//外部排序

// 八大排序 --> 内部排序
// > 插入排序
// > 希尔排序
// > 选择排序
// > 冒泡
// > 快排
// > 堆排
// > 归并排序
// > 基数排序 
//
// > (计数排序)

void test0()
{
	//优先级队列的底层实现: 堆排序
	//
	//小于符号，得到是一个大顶堆
	//
	//大于符号，得到是一个小顶堆
	//
	//每一次操作的堆顶的元素, 将堆顶元素作为左操作数, 
	//与新来的元素进行比较，如果返回值为true,则用新来的
	//元素替换堆顶的元素
	//
	vector<int> vec{5, 1, 2, 6, 9, 7, 3, 4, 8};
	//priority_queue<int> numbers(vec.begin(), vec.end()); 
	priority_queue<int> numbers;
	//priority_queue<int, vector<int>, std::greater<int>> numbers;
	
	for(auto it = vec.begin(); it != vec.end(); ++it)
	{
		numbers.push(*it);	
		cout << "当前队列中优先级最高的元素的是: " << numbers.top() << endl;
	}

	while(!numbers.empty()) {
		cout << numbers.top() << " ";
		numbers.pop();
	}
	cout << endl;
}
 
int main(void)
{
	test0();

	return 0;
}
