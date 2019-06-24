 ///
 /// @file    Stack.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-24 09:59:40
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Stack
{
public:
	explicit
	Stack(int size = 10)
	: _top(-1)
	, _size(size)
	, _base(new int[_size]())
	{
	
	}

	bool empty() const
	{	return _top == -1;	}

	bool full() const
	{	return _top == _size - 1;	}

	void push(int number)
	{
		if(!full()) {
			_base[++_top] = number;
		} else
			cout << ">> stack is full!" << endl;
	}

	void pop()
	{
		if(!empty()) {
			--_top;
		} else
			cout << ">> stack is empty!" << endl;
	}

	int top()
	{
		return _base[_top];
	}

private:
	int _top;
	int _size;
	int * _base;
};
 
int main(void)
{
	Stack stack;
	cout << "此时栈是否为空?" << stack.empty() << endl;
	stack.push(1);
	cout << "此时栈是否为空?" << stack.empty() << endl;

	for(int idx = 2; idx != 12; ++idx)
	{
		stack.push(idx);
	}
	cout << "此时栈是否已满?" << stack.full() << endl;

	while(!stack.empty()) {
		cout << stack.top() << " ";
		stack.pop();
	}
	cout << endl;
	cout << "此时栈是否为空?" << stack.empty() << endl;

	return 0;
}
