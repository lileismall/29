 ///
 /// @file    Queue.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-24 10:23:02
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Queue
{
public:
	explicit
	Queue(int size = 10)
	: _size(size)
	, _head(0)
	, _rear(0)
	, _base(new int[_size]())
	{}

	bool empty() const
	{
		return _head == _rear;
	}

	bool full() const
	{
		return _head == (_rear + 1) % _size;
	}

	void push(int number)
	{
		if(!full())	{
			_base[_rear++] = number;
			_rear %= _size;
		} else 
			cout << ">> queue is full!" << endl;
	}

	void pop()
	{
		if(!empty()) {
			++_head;
			_head %= _size;
		} else 
			cout << ">> queue is empty!" << endl; 
	}

	int front() 
	{	return _base[_head];	}

	int back()
	{	return _base[(_rear - 1 + _size) % _size];	}

private:
	int _size;
	int _head;
	int _rear;
	int * _base;
};
 
int main(void)
{
	Queue queue;
	cout << "此时队列是否为空?" << queue.empty() << endl;
	queue.push(1);
	cout << "此时队列是否为空?" << queue.empty() << endl;

	for(int idx = 2; idx != 12; ++idx)
	{
		queue.push(idx);
	}
	cout << "此时队列是否已满?" << queue.full() << endl;
	cout << "此时队头元素为: " << queue.front() << endl;
	cout << "此时队尾元素为: " << queue.back() << endl;
	queue.pop();
	queue.push(10);
	cout << "元素先出队再入队之后:" << endl;
	cout << "此时队头元素为: " << queue.front() << endl;
	cout << "此时队尾元素为: " << queue.back() << endl;

	while(!queue.empty()) {
		cout << queue.front() << " ";
		queue.pop();
	}
	cout << endl;
	cout << "此时队列是否为空?" << queue.empty() << endl;


 
	return 0;
}
