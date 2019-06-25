 ///
 /// @file    arrow.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-25 10:54:47
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Data
{
public:
	Data(int data = 1)
	: _data(data)
	{	cout << "Data()" << endl;	}

	void print() const
	{	cout << "_data = " << _data << endl;	}

	~Data()
	{	cout << "~Data()" << endl;	}

private:
	int _data;
};

class MiddleLayer
{
public:
	MiddleLayer(Data * pdata)
	: _pdata(pdata)
	{	cout << "MiddleLayer(Data*)" << endl;	}

	Data * operator->()
	{
		return _pdata;
	}

	Data & operator*()
	{
		return *_pdata;
	}

	~MiddleLayer() {	
		cout << "~MiddleLayer()" << endl;	
		if(_pdata)
			delete _pdata;
	}
private:
	Data * _pdata;
};

class ThirdLayer
{
public:
	ThirdLayer(MiddleLayer * pml)
	: _pml(pml)
	{	cout << "ThirdLayer(MiddleLayer*)" << endl;	}

	MiddleLayer & operator->()
	{
		return *_pml;
	}

	~ThirdLayer()
	{
		cout << "~ThirdLayer()" << endl;
		if(_pml)
			delete _pml;
	}
private:
	MiddleLayer * _pml;
};

 
int main(void)
{
	Data * pdata = new Data(12);
	pdata->print();
	(*pdata).print();
	delete pdata;
	cout << endl;

	//智能指针的雏形
	MiddleLayer ml(new Data(10));
	ml->print();//简写
	(*ml).print();
	//(ml.operator->())->print();//完整形式

	cout << endl;

//	ThirdLayer tl(new MiddleLayer(new Data(11)));
//	tl->print();//简写
//	((tl.operator->()).operator->())->print();

 
	return 0;
}
