 ///
 /// @file    replace.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-04 11:34:10
 ///
 
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using std::cout;
using std::endl;
using std::vector;
using std::ostream_iterator;
using std::replace_if;

void test0()
{
	vector<int> numbers {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

#if 0
	replace_if(numbers.begin(), numbers.end(), 
		[](int number){
			return number > 6;
		},
		22);
#endif

	std::less<int> lt;// 二元断言
	std::greater<int> gt;

	//函数适配器, 函数绑定器==> 在调用函数之前提前给某一个参数绑定值
	bind1st(lt, 6);// 变成一个一元断言
	bind2nd(lt, 6);

	//replace_if(numbers.begin(), numbers.end(), bind1st(lt, 6), 66);
	replace_if(numbers.begin(), numbers.end(), bind2nd(lt, 6), 66);

	copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}
 
int main(void)
{
	test0();
	return 0;
}
