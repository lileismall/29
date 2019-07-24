 ///
 /// @file    TemplateStack.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-01 15:03:42
 ///
 
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;


//类模板
template <class Type, int kSize = 10>
class Stack
{
public:
	Stack()
	: _top(-1)
	, _base(new Type[kSize]())
	{}

	~Stack();

	bool full() const;
	bool empty() const;
	void push(const Type & value);
	void pop();
	const Type & top() const;

private:
	int _top;
	Type * _base;
};

template <class Type, int kSize>
Stack<Type, kSize>::~Stack()
{
	if(_base) {
		delete [] _base;
		_base = nullptr;
	}
}

template <class Type, int kSize>
bool Stack<Type, kSize>::full() const
{
	return _top == kSize - 1;
}

template <class Type, int kSize>
bool Stack<Type, kSize>::empty() const
{
	return _top == -1;
}

template <class Type, int kSize>
void Stack<Type, kSize>::push(const Type & value)
{
	if(!full()) {
		_base[++_top] = value;
	} else {
		cout << " stack is full, cannot push any more data!" << endl;
	}
}

template <class Type, int kSize>
void Stack<Type, kSize>::pop()
{
	if(!empty()) {
		--_top;
	} else {
		cout << " stack is empty, no more data!" << endl;
	}
} 

template <class Type, int kSize>
const Type & Stack<Type, kSize>::top() const
{
	return _base[_top];
}
 
int test0(void)
{
	Stack<int> stack;
	cout << ">> 此时栈中是否为空?" << stack.empty() << endl;
	stack.push(1);
	cout << ">> 此时栈中是否为空?" << stack.empty() << endl;

	for(int idx = 2; idx != 12; ++idx) 
	{
		stack.push(idx);
	}
	cout << ">> 此时栈中是否已满?" << stack.full() << endl;
	while(!stack.empty()) {
		cout << stack.top() << endl;
		stack.pop();
	}
	cout << ">> 此时栈中是否为空?" << stack.empty() << endl;

	return 0;
}

int test1(void)
{

	Stack<string> stack;
	cout << ">> 此时栈中是否为空?" << stack.empty() << endl;
	stack.push(string(5, 'a'));
	cout << ">> 此时栈中是否为空?" << stack.empty() << endl;

	for(int idx = 1; idx != 12; ++idx) 
	{
		stack.push(string(5, 'a' + idx));
	}
	cout << ">> 此时栈中是否已满?" << stack.full() << endl;
	while(!stack.empty()) {
		cout << stack.top() << endl;
		stack.pop();
	}
	cout << ">> 此时栈中是否为空?" << stack.empty() << endl;

	return 0;
}

int main(void)
{
	test1();
	return 0;
}
