 ///
 /// @file    mem_fn.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-04 16:19:10
 ///
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using std::cout;
using std::endl;
using std::vector;
using std::for_each;
using std::remove_if;

class Number
{
public:
	Number(int data = 0)
	: _data(data)
	{}

	void display() const {	cout << _data << " ";	}
	bool isEven() const 
	{
		return !(_data % 2 );
	}

	bool isPrime() const
	{
		if(_data == 1)
			return false;
		for(size_t idx = 2; idx <= _data / 2; ++idx) {
			if(!(_data % idx))	
				return false;
		}
		return true;
	}
private:
	size_t _data;
};
 
int main(void)
{
	vector<Number> numbers;
	for(size_t idx = 1; idx != 20; ++idx) {
		numbers.emplace_back(idx);
	}

	for_each(numbers.begin(), numbers.end(), std::mem_fn(&Number::display));
	cout << endl;

	
	numbers.erase(remove_if(numbers.begin(), numbers.end(), std::mem_fn(&Number::isEven)),
			numbers.end());
	for_each(numbers.begin(), numbers.end(), std::mem_fn(&Number::display));
	cout << endl;

	numbers.erase(remove_if(numbers.begin(), numbers.end(), std::mem_fn(&Number::isPrime)),
			numbers.end());
	for_each(numbers.begin(), numbers.end(), std::mem_fn(&Number::display));
	cout << endl;

	return 0;
}
