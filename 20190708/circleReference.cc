 ///
 /// @file    shared_ptr2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-08 16:13:08
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::weak_ptr;

class Parent;

class Child
{
public:
	Child() {	cout << "Child()" << endl;	}
	~Child() {	cout << "~Child()" << endl;	}

	weak_ptr<Parent> _pParent;
};

class Parent 
{
public:
	Parent() {	cout << "Parent()" << endl;	}
	~Parent() {	cout << "~Parent()" << endl;	}

	shared_ptr<Child> _pChild;
};
 
//问题: shared_ptr的循环引用会导致内存泄漏
//解决方案: weak_ptr
int main(void)
{
	shared_ptr<Parent> pParent(new Parent());
	shared_ptr<Child> pChild(new Child());

	pParent->_pChild = pChild;// shared_ptr = shared_ptr;//引用计数加1
	pChild->_pParent = pParent;//weak_ptr = shared_ptr//不会加1,保持不变

	cout << "parent's use_count = " << pParent.use_count() << endl
		 << "child's use_count = " << pChild.use_count() << endl;

	return 0;
}
