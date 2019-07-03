 ///
 /// @file    istream_iterator.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-03 11:15:49
 ///
 
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::copy;
using std::vector;
using std::istream_iterator;
using std::ostream_iterator;
 
int main(void)
{
	cout << "pls input valid integer!" << endl;
	istream_iterator<int> isi(cin);// cin >> number;
	vector<int> numbers;//begin()是有元素，然后进行遍历
	cout << "numbers's size = " << numbers.size() << endl;
	cout << "numbers's capacity = " << numbers.capacity() << endl;

	//copy(isi, istream_iterator<int>(), numbers.begin());
	//插入新元素时，要使用插入迭代器
	//
	//  numbers.push_back(number);
	copy(isi, istream_iterator<int>(), std::back_inserter(numbers));

	copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
	
	return 0;
}
