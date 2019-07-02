 ///
 /// @file    list.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-02 10:07:27
 ///
 
#include <iostream>
#include <list>
using std::cout;
using std::endl;
using std::list;

template <class Container>
void display(const Container & c)
{
	for(auto & elem : c) {
		cout <<  elem << " ";
	}
	cout << endl;
}

struct Comparator
{
	bool operator()(int x, int y) const
	{	return x > y;	}
};


void test0()
{
	list<int> numbers1{3, 1, 4, 5, 2};
	list<int> numbers2{11, 21, 14, 15, 8};

	//默认情况下按升序方式进行排序
	numbers1.sort();
	numbers2.sort();
	cout << "numbers1:";
	display(numbers1);
	cout << "numbers2:";
	display(numbers2);

	//std::greater<int> gt;
	//numbers1.sort(gt);//定制化排序方式
	
	Comparator cmp;
	numbers1.sort(cmp);

	cout << "numbers1:";
	display(numbers1);
}

void test1()
{
	list<int> numbers1{3, 1, 4, 5, 2};
	list<int> numbers2{11, 21, 14, 15, 8};

	//默认情况下按升序方式进行排序
	numbers1.sort();
	numbers2.sort();

	//执行merge之后，numbers2中的元素全部进入到numbers1中去了，
	//numbers2中没有元素了
	numbers1.merge(numbers2);
	cout << "numbers1:";
	display(numbers1);

	cout << "numbers2:";
	display(numbers2);

	numbers1.reverse();
	cout << "numbers1:";
	display(numbers1);

}

void test2()
{
	list<int> numbers1{3, 1, 4, 5, 2};
	list<int> numbers2{11, 21, 14, 15, 8};
	auto it = numbers1.begin();
	++it;

	auto start = numbers2.begin();
	++start;

	auto finish = numbers2.end();
	--finish;
	numbers1.splice(it, numbers2, start, finish);
	cout << "numbers1:";
	display(numbers1);
	cout << "numbers2:";
	display(numbers2);

	auto it2 = numbers1.end();
	--it2;

	numbers1.splice(numbers1.begin(), numbers1, it2);
	cout << "numbers1:";
	display(numbers1);
}

 
int main(void)
{
	//test0();
	//test1();
	test2();
	return 0;
}
