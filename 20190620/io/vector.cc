 ///
 /// @file    vector.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-20 14:33:32
 ///
 
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

void printVectorCapacity(const vector<int> & c)
{
	cout << "c's size = " << c.size() << endl;
	cout << "c's capacity = " << c.capacity() << endl;
}

 
int main(void)
{
	int arr[10];//静态数组
	//动态数组
	//策略: 当数组中的size() == capacity()，并且此时还要
	//添加新的元素时，需要进行动态扩容。 
	//
	//先去申请2 * capacity() 的空间，然后把原来空间中的
	//元素全部复制到新空间中，
	//然后去释放原来的空间的数据
	//最后再添加新的元素
	vector<int>	numbers;
	numbers.reserve(100);
	printVectorCapacity(numbers);

	numbers.push_back(1);
	printVectorCapacity(numbers);
	numbers.push_back(1);
	printVectorCapacity(numbers);
	numbers.push_back(1);
	printVectorCapacity(numbers);
	numbers.push_back(1);
	printVectorCapacity(numbers);
	numbers.push_back(1);
	printVectorCapacity(numbers);
	numbers.push_back(1);
	printVectorCapacity(numbers);

	numbers.pop_back();

	for(size_t idx = 0; idx != numbers.size(); ++idx)
	{
		cout << numbers[idx] << " ";
	}
	cout << endl;
	
	//C++11中的
	for(auto & number : numbers)
	{
		cout << number << " ";
	}
	cout << endl;

	//迭代器访问
	auto iter = numbers.begin();
	while(iter != numbers.end())
	{
		cout << *iter << " ";
		++iter;
	}
	cout << endl;

	return 0;
}
