 ///
 /// @file    mvc.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-09 14:43:16
 ///
 
#include <iostream>
#include <string>
#include <map>
#include <memory>
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::shared_ptr;

class Student
{
public:
	Student(size_t id = 0, const string & name = string())
	: _id(id)
	, _name(name)
	{	cout << "Student(size_t, string)" << endl;	}

	size_t getId() const {	return _id;	}
	string getName() const {	return _name;	}

	~Student() {	cout << "~Student()" << endl;	}
private:
	size_t _id;
	string _name;
};

class View
{
public:
	View(Student * stu = nullptr)
	: _stu(stu)
	{	cout << "View(Student *)" << endl;	}

	void setStudent(Student * stu)
	{	_stu = stu;	}

	virtual void show() const
	{
		cout << "id: " << _stu->getId() << endl
		     << "name: " << _stu->getName() << endl; 
	}

protected:
	Student * _stu;
};

class SubView
: public View
{
public:
	void show() const override
	{	
		cout << "{ id: " << _stu->getId() 
			 << ", name:" << _stu->getName()
			 << "}" << endl;
	}

};

class Controller
{
public:
	Controller() {	cout << "Controller()" << endl;	}

	void attach(const Student & stu)
	{
		_students[stu.getId()] = stu;
	}

	void attach(Student && stu)
	{
		_students[stu.getId()] = std::move(stu);
	}

	void detach(size_t id) 
	{
		auto it = _students.find(id);
		if(it != _students.end())
			_students.erase(id);
	}

	void show(View * view)
	{
		for(auto & element :  _students) {
			view->setStudent(&element.second);
			view->show();
		}
	}

private:
	map<size_t, Student> _students;
};
 
int main(void)
{
	Controller controller;
	controller.attach(Student(100, "Jackie"));
	controller.attach(Student(101, "John"));
	controller.attach(Student(102, "Marry"));
	
	shared_ptr<View> view(new View());
	shared_ptr<View> view2(new SubView());
	controller.show(view.get());

	controller.show(view2.get());


	return 0;
}
