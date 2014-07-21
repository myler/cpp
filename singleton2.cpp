#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Student
{
private:
	string name;
	int age;
public:
	Student(const string name = "MYL", const int age = 25)
	 : name(name), age(age)
	{
		cout << "constructor..." << endl;
	}

	void print_info()
	{
		cout << "Name: " << name << " age: " << age << endl;
	}
};

template<typename T>
class Singleton
{
private:
	Singleton()
	{
		cout << "Singleton::constructor..." << endl;
	}

	static auto_ptr<T> _instance;
public:
	static auto_ptr<T> getInstance()
	{
		cout << "Singleton::getInstance..." << endl;
		if (!_instance.get())
		{
			auto_ptr<T> temp(new T);
			_instance = temp;
		}

		return _instance;
	}
};

auto_ptr<Student> Singleton<Student>::_instance;

int main(int argc, char const *argv[])
{
	auto_ptr<Student> mySingleton(Singleton<Student>::getInstance());
	mySingleton->print_info();

	return 0;
}