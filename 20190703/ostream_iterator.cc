 ///
 /// @file    ostream_iterator.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-03 10:22:32
 ///
 
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <fstream>
using std::cout;
using std::endl;
using std::copy;
using std::vector;
using std::ofstream;
using std::ostream_iterator;
 
int main(void)
{
	vector<int> numbers{1, 2, 3, 4, 5};

	for(auto it = numbers.begin(); it != numbers.end(); ++it)
		cout << *it << " ";
	cout << endl;

	//把输出流看成一个容器
	ostream_iterator<int> osi(cout, " ");// 迭代器适配器
	copy(numbers.begin(), numbers.end(), osi);
	cout << endl;

	ofstream ofs("test.txt");
	if(!ofs) {
		cout << "ofstream open file error!" << endl;
		return -1;
	}
	ostream_iterator<int> ofsi(ofs, ",");

	copy(numbers.begin(), numbers.end(), ofsi);
	

	return 0;
}
