 ///
 /// @file    TemplateSingleton.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-06 09:36:46
 ///
 
#include <iostream>
using std::cout;
using std::endl;

template <class T>
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
				_pInstance = nullptr;
				cout << "~AutoRelease()" << endl;
			}
		}
	};
public:
	template <class... Args>
	static T * getInstance(Args... args)
	{
		if(nullptr == _pInstance ) {
			(void)_auto;
			_pInstance = new T(args...);
		}
		return _pInstance;
	}

private:
	Singleton() {}
	~Singleton() {}

private:
	static T * _pInstance;
	static AutoRelease _auto;
};

template <class T>
T * Singleton<T>::_pInstance = nullptr;

template <class T>
typename Singleton<T>::AutoRelease Singleton<T>::_auto;


class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int,int)" << endl;
	}

	void print() const
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

	~Point() {	cout << "~Point()" << endl;	}

private:
	int _ix;
	int _iy;
};
 
int main(void)
{
	Point * p1 = Singleton<Point>::getInstance(1, 2);
	Point * p2 = Singleton<Point>::getInstance(3, 2);
	p1->print();
	p2->print();
	cout << "p1 = " << p1 << endl
		 << "p2 = " << p2 << endl;

	//Point pt(3, 4);
	//pt.print();
	return 0;
}
