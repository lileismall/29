 ///
 /// @file    io1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-20 11:12:30
 ///
 
#include <iostream>
#include <string>
#include <limits>
using std::cout;//std::ostream
using std::cin;
using std::endl;
using std::string;


void printStreamStatus()
{
	cout << "cin's badbit = " << cin.bad() << endl
		 << "cin's failbit = " << cin.fail() << endl
		 << "cin's eofbit = " << cin.eof() << endl
		 << "cin's goodbit = " << cin.good() << endl;
}

void test0()
{
	int number;
	printStreamStatus();
	while(cin >> number) {
		printStreamStatus();
		cout << ">> number = " << number << endl;
	}
	printStreamStatus();

	cout << "clear之后, 流的状态:" << endl;
	cin.clear();//重置流的状态
	cin.ignore(1024, '\n');//清空缓冲区

	printStreamStatus();

	string str;
	cin >> str;
	cout << "str = " << str << endl;
}


void test1()
{
	cout << "pls input a interger number:" << endl;
	int number;
	while(cin >> number, !cin.eof()) {
		if(cin.bad()) {
			cout << ">> cin stream status is corrupted!" << endl;
			return;
		} else if(cin.fail()) {
			cout << "pls input a valid interger number:" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		cout << ">> number = " << number << endl;
	}

	printStreamStatus();
}

 
int main(void)
{
	//test0();
	test1();
	return 0;
}
