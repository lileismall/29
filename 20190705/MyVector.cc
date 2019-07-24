 ///
 /// @file    MyVector.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-05 10:24:20
 ///
 
#include <iostream>
#include <memory>
#include <algorithm>
using std::cout;
using std::endl;
using std::allocator;

template <class Type>
class Vector
{
public:
	using iterator = Type *;
	using const_iterator = const Type *;

	Vector()
	: _start(nullptr)
	, _finish(nullptr)
	, _end_of_storage(nullptr)
	{}

	~Vector()
	{
		if(size() > 0) {
			while(_start != _finish)
				_alloc.destroy(--_finish);

			_alloc.deallocate(_start, capacity());
		}
	}

	size_t size() const {	return _finish - _start;	}
	size_t capacity() const {	return _end_of_storage - _start;	}

	void push_back(const Type & value);
	void pop_back();

	iterator begin() {	return _start;	}
	iterator end() {	return _finish;	}

	const_iterator begin() const {	return _start;	}
	const_iterator end() const {	return _finish;	}

	Type & operator[](size_t idx) {	return _start[idx]; }

private:
	void reallocate();

private:
	static allocator<Type> _alloc;
	Type * _start;
	Type * _finish;
	Type * _end_of_storage;
};

template <class Type>
allocator<Type> Vector<Type>::_alloc;

template <class Type>
void Vector<Type>::push_back(const Type & value)
{
	if(size() == capacity()) {
		reallocate();
	}

	//有空间放数据了
	_alloc.construct(_finish++, value);
}

template <class Type>
void Vector<Type>::pop_back()
{
	if(size() !=0 ) {
		_alloc.destroy(--_finish);
	}
}

template <class Type>
void Vector<Type>::reallocate()
{
	size_t capa = capacity();
	size_t newCapa = 2 * capa > 0 ? 2 * capa:1;
	
	Type * p = _alloc.allocate(newCapa);//为类型化空间
	
	if(_start) {
		std::uninitialized_copy(_start, _finish, p);
		while(_start != _finish)
			_alloc.destroy(--_finish);

		_alloc.deallocate(_start, capa);
	}
	_start = p;
	_finish = _start + capa;
	_end_of_storage = _start + newCapa;
}

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

template <class Container>
void printCapacity(const Container & c)
{
	cout << "c' size = " << c.size() << endl;
	cout << "c' capacity = " << c.capacity() << endl;
}
 
int test0(void)
{
	Vector<int> numbers;
	numbers.push_back(1);
	printCapacity(numbers);
	
	numbers.push_back(1);
	printCapacity(numbers);
	numbers.push_back(1);
	printCapacity(numbers);
	numbers.push_back(1);
	printCapacity(numbers);
	numbers.push_back(1);
	printCapacity(numbers);
	numbers.push_back(1);
	printCapacity(numbers);
 
	display(numbers);
	return 0;
}

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int,int)" << endl;
	}

	Point(const Point & rhs)
	: _ix(rhs._ix)
	, _iy(rhs._iy)
	{
		cout << "Point(const Point & rhs)" << endl;
	}

	void print() const
	{
		cout << "(" << _ix
		     << "," << _iy
			 << ")" << endl;
	}

	void setX(int ix) {	_ix = ix;	}
	void setY(int iy) {	_iy = iy;	}

	~Point()
	{
		cout << "~Point()" << endl;
	}

	friend std::ostream & operator<<(std::ostream & os, const Point & rhs);

private:
	int _ix;
	int _iy;
};

std::ostream & operator<<(std::ostream & os, const Point & rhs)
{
	os << "(" << rhs._ix
	   << "," << rhs._iy
	   << ")";
	return os;
}

void test1()
{
	Vector<Point> points;
	points.push_back(1);
	printCapacity(points);
	
	points.push_back(1);
	printCapacity(points);
	points.push_back(1);
	printCapacity(points);
	points.push_back(1);
	printCapacity(points);
	points.push_back(1);
	printCapacity(points); 
	points.push_back(1);
	printCapacity(points);

	display(points);

	for(size_t idx = 0; idx != points.size(); ++idx)
	{
		cout << points[idx] << " ";
	}
	cout << endl;
}

int main(void)
{
	test1();
	return 0;
}
