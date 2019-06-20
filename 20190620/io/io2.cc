 ///
 /// @file    io2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-20 11:44:50
 ///
 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;

vector<string> file;

void test1()
{
	//ifstream要求文件必须存在
	//ifstream ifs("test.txt");
	ifstream ifs("io2.cc");
	if(!ifs.good()) {
		cout << "ifstream open file error!" << endl;
		return;
	}

	file.reserve(100);
	string line;
	//while(ifs >> str) {
	while(std::getline(ifs, line)) {
		file.push_back(line);
	}

	//auto 自动推导元素的类型
#if 0
	for(auto & line : file)
	{
		cout << line << endl;
	}
#endif
	
	ifs.close();
}

void test2()
{
	string filename = "test.txt";
	//文件输出流不要求文件存在；
	//当文件不存在时，直接创建文件；
	//当文件存在时，直接清空文件中的内容
	ofstream ofs(filename);
	if(!ofs.good()) {
		cout << ">> ofstream open error!" << endl;
		return ;
	}

	for(auto & line : file)
	{
		ofs << line << "\n";
	}
	ofs.close();
}

void test3()
{
	string filename = "test.txt";
	//std::ios::app模式可以在文件的末尾追加新的内容
	ofstream ofs(filename, std::ios::app);
	if(!ofs.good()) {
		cout << ">> ofstream open error!" << endl;
		return ;
	}
	
	cout << "pos: " << ofs.tellp() << endl;

	string line = "that's a new line\n";
	ofs << line;
	
	ofs.close(); 
}

void printStreamStatus(fstream & fs)
{
	cout << "fs's badbit = " << fs.bad() << endl
		 << "fs's failbit = " << fs.fail() << endl
		 << "fs's eofbit = " << fs.eof() << endl
		 << "fs's goodbit = " << fs.good() << endl << endl;
}

void test4()
{
	string filename = "readme.txt";
	fstream fs(filename);
	if(!fs.good()) {
		cout << "fstream open error! " << endl;
		return ;
	}

	int number = -1;
	for(size_t idx = 0; idx != 10; ++idx)
	{
		cin >> number;
		fs << number << " ";
	}
	cout << ">> pos : " << fs.tellg() << endl;
	fs.seekg(std::ios::beg);

	printStreamStatus(fs);
	for(size_t idx = 0; idx != 10; ++idx)
	{
		fs >> number;
		
		//printStreamStatus(fs);
		cout << number << " ";
	}
	cout << endl;
	
	fs.close();
}

void test5()
{
	string filename = "vector.cc";
	ifstream ifs;
	ifs.open(filename, std::ios::in|std::ios::ate);
	if(!ifs.good()) {
		cout << ">> ifstream open file error!" << endl;
		return;
	}
	
	cout << "pos: " << ifs.tellg() << endl;
	size_t len = ifs.tellg();

	char buff[len + 1] = {0};

	ifs.seekg(std::ios::beg);

	ifs.read(buff, len);//获取一篇文章的内容

	cout << "buff:" << endl << buff << endl;
	
	ifs.close();
}


 
int main(void)
{
	//test1();
	//test2();
	//test3();
	//test4();
	test5();
	return 0;
}
