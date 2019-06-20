 ///
 /// @file    io3.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-20 16:09:11
 ///
 
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::stringstream;
using std::istringstream;
using std::ostringstream;

void printStreamStatus(stringstream & fs)
{
	cout << "fs's badbit = " << fs.bad() << endl
		 << "fs's failbit = " << fs.fail() << endl
		 << "fs's eofbit = " << fs.eof() << endl
		 << "fs's goodbit = " << fs.good() << endl << endl;
}

void test0()
{
	int number1 = 1;
	int number2 = 2.22;

	stringstream ss;

	//字符串输出流
	ss << "number1= " << number1 << " number2= " << number2;
	cout << ss.str() << endl << endl;
	//snprintf();

	string key;
	int value;

	while(!ss.eof()) {
		ss >> key >> value;
		//printStreamStatus(ss);
		cout << key << " ---> " << value << endl;
	}
}

string int2str(int number)
{
	ostringstream oss;
	oss << number;
	return oss.str();
}

struct Element
{
	Element(const string & k, const string & v)
	: key(k), value(v)
	{}
	string key;
	string value;
};

void readConfiguration(const string & filename)
{
	ifstream ifs(filename);
	if(!ifs.good()) {
		cout << ">> ifstream open " << filename << " error!" << endl;
		return ;
	}

	vector<Element> config;
	
	string key, value;
	string line;
	while(getline(ifs, line)) {
		istringstream iss(line);	
		while(!iss.eof()) {
			iss >> key >> value;
			//cout << key << " --> " << value << endl;
			Element element(key, value);
			config.push_back(element);
		}
	}

	for(auto & element: config)
	{
		cout << element.key  << " ---> " << element.value << endl;
	}
}

void test1()
{
	string filename = "my.conf";
	readConfiguration(filename);
}
 
int main(void)
{
	//test0();
	test1();

	return 0;
}
