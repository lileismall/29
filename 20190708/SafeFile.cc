 ///
 /// @file    SafeFile.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-08 14:33:31
 ///
 
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std:: string;

class SafeFile
{
public:
	SafeFile(FILE * fp)
	: _fp(fp)
	{ }

	void write(const string & msg)
	{
		fwrite(msg.c_str(), 1, msg.size(), _fp);
	}

	~SafeFile()
	{
		if(_fp) {
			fclose(_fp);
			cout << "fclose(fp) " << endl;
		}
	}
private:
	FILE * _fp;
};
 
int main(void)
{
	SafeFile sf(fopen("test.txt", "aw+"));
	string msg = "hello,world";
	sf.write(msg);

	return 0;
}
