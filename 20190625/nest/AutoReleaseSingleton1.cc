 ///
 /// @file    Singleton.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-25 14:54:19
 ///
 
#include <iostream>
using std::cout;
using std::endl;



//单例对象自动释放
//方案一： 嵌套类 + 静态对象


class Singleton
{
	class AutoRelease
	{
	public:
		AutoRelease() {	cout << "AutoRelease()" << endl;	}
		~AutoRelease() 
		{
			if(_pInstance) {
				delete _pInstance;
				cout << "~AutoRelease()" << endl;
			}
		}
	};
public:
	static Singleton * getInstance()
	{
		//在多线程环境下是非线程安全的
		//加锁
		if(_pInstance == nullptr)
			_pInstance = new Singleton();
		return _pInstance;
	}

	static void destroy()
	{
		if(_pInstance)
			delete _pInstance;
	}

	void print()const
	{	cout << "Singleton::print()" << endl;	}

private:
	Singleton() {	cout << "Singleton()" << endl;	}
	~Singleton() {	cout << "~Singleton()" << endl;	}

private:
	static Singleton * _pInstance;
	static AutoRelease _autoRelease;
};

//Singleton * Singleton::_pInstance = nullptr;//懒（饿）汉模式(懒加载) 
//解决多线程安全的问题
Singleton * Singleton::_pInstance = getInstance();//饱汉模式

Singleton::AutoRelease Singleton::_autoRelease;
 
int main(void)
{
	Singleton* p1 = Singleton::getInstance();
	p1->print();

	//Singleton::destroy();
	return 0;
}
