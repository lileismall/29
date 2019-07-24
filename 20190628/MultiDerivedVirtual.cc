 ///
 /// @file    MultiDerivedVirtual.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-28 16:01:38
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A
{
public:
	virtual void a() { cout << "A::a()" << endl;	}
	virtual void b() { cout << "A::b()" << endl;	}
	virtual void c() { cout << "A::c()" << endl;	}
};	

class B
{
public:
	virtual void a() { cout << "B::a()" << endl;	}
	virtual void b() { cout << "B::b()" << endl;	}
	void c() { cout << "B::c()" << endl;	}
	void d() { cout << "B::d()" << endl;	}
};

class C
: public A
, public B
{
public:
	virtual void a() { cout << "C::a()" << endl;	}
	void c() {	cout << "C::c()" << endl;	}
	void d() { cout << "C::d()" << endl;	}
};
 
int main(void)
{
	C c;
	A * pa = &c;
	pa->a();
	pa->b();
	pa->c();
	cout << endl;

	B * pb = &c;
	pb->a();
	pb->b();
	pb->c();
	pb->d();
	cout << endl;

#if 1
	C * pc = &c;
	pc->a();
	//pc->b();
	//pc->c();
	pc->d();
#endif
	cout << "pa = " << pa << endl
		 << "pb = " << pb << endl
		 << "pc = " << pc << endl;
 
}
