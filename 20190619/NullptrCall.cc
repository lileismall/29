 ///
 /// @file    NullptrCall.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-19 11:10:59
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class NullptrCall
{
public:
	void func1()
	{	cout << "func1()" << endl;	}

	void func2(int ix)
	{	cout << "func2() ix = " << ix << endl;	}

	static void func3()
	{	cout << "func3()" << endl;	}

	void func4()
	{	cout << "func4() _ix " << this->_ix << endl;	}

private:
	int _ix;
};
 
int main(void)
{
	NullptrCall * p = nullptr;
	
	p->func1();// NullptrCall::func1(nullptr);
	p->func2(10);//NullptrCall::func2(nullptr, 10);
	p->func3();//NullptrCall::func3();
	p->func4();//NullptrCall::fun4(nullptr);
	return 0;
}
